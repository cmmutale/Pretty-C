%option noyywrap
%option yylineno


%{
	#include "p2.h"

	int column = 4;
	int line = 1;
	int paren = 0;

%}
delim	[ \t\n]
ws	{delim}+
nl [\n]
quote	[']
ditto	["]
digit	[0-9]
oct	[0-7]
exp	[e|E][+|-|$]{digit}+
hex	{digit}[a-fA-F]
alpha	[a-zA-Z]
notquote [^']
notditto [^"]
start_com	[/*]
end_com		[*/]
hash [#]
one_line	[\/][\/]{alpha}*([ ]{alpha}*)+[\n]
float_p {digit}*.{digit}*
include ["|<]{alpha}*.?{alpha}*["|>]
h_file	"([a-zA-Z]|[0-9])*[.][h]"
one_line_string [\/][\/]({ws}*[\'])*
%%

{ws}	{}
{quote}({notquote}|\\{quote})*{quote}	{write_char();}
{ditto}({notditto}|\\{ditto})*{ditto}	{write_string();}
0{oct}+							{write_oct();}
0(x|X){hex}+					{write_hex();}
{digit}+						{write_int();}

{alpha}({alpha}|{digit})*		{write_id();}

"{"								{write_begin();}
"}"								{write_end();}
"("								{write_open();}
")"								{write_close();}
"["								{write_bopen();}
"]"								{write_bclose();}
";"								{write_sep();}

"++" 						|
"->" 						|
"-" 						|
"&" 						|
"*" 						|
"+" 						|
"~" 						|
"!" 						|
"/" 						|
"%" 						|
"<<" 						|
">>" 						|
"<" 						|
">" 						|
"<=" 						|
"=>" 						|
"==" 						|
"!=" 						|
"^" 						|
"|" 						|
"&&" 						|
"||" 						|
"=" 						|
"*=" 						|
"/=" 						|
"%=" 						|
"+=" 						|
"-=" 						|
"<<=" 						|
">>=" 						|
"&=" 						|
"^=" 						|
"|=" 						|
"," 						|
"#" 						|
"##" 								{write_op();}

{one_line}					|
{one_line_string}					{write_inline();}

{hash}"include"				|
{include}					|
{hash}"define"				|
{h_file}							{write_derivative();}

%%
