#ifndef P2_H
#define P2_H

#define INDENT (4)
#define include


#define DONE	300
#define ID	(DONE+1)
#define NUM	(ID+1)
#define IF	(NUM+1)
#define ELSE	(IF+1)
#define FOR	(ELSE+1)
#define WHILE	(FOR+1)
#define DO	(WHILE+1)
#define BREAK	(DO+1)
#define CONTINUE	(BREAK+1)
#define SWITCH	(CONTINUE+1)
#define CASE	(SWITCH+1)
#define RETURN	(CASE+1)

#define DEREF       313
#define DEFAULT		(DEREF+1)
#define CHAR		(DEFAULT+1)
#define SHORT		(CHAR+1)
#define INT		(SHORT+1)
#define LONG		(INT+1)
#define FLOAT		(LONG+1)
#define DOUBLE		(FLOAT+1)
#define UNSIGNED	(DOUBLE+1)
#define VOID		(UNSIGNED+1)
#define STATIC		(VOID+1)
#define VOLATILE	(STATIC+1)
#define EXTERN		(VOLATILE+1)
#define STRUCT		(EXTERN+1)
#define TYPEDEF		(STRUCT+1)
#define SIZEOF		(TYPEDEF+1)


extern int yylex();
extern char *yytext;
extern int line;
extern int column;
extern int paren;

extern void write_char();
extern void write_string();
extern void write_oct();
extern void write_hex();
extern void write_int();
extern void write_fp();
extern void write_id();
extern void write_begin();
extern void write_end();
extern void write_open();
extern void write_close();
extern void write_bopen();
extern void write_bclose();
extern void write_sep();
extern void write_op();
extern void write_inline();
extern void write_comment();
extern void write_indent();
extern void write_derivative();
extern void write_html();
extern void write_html_char();


struct table {
    char *lexptr;
    int token;
    int var_index;
};

extern struct table symtable[];
extern int installID(char s[], int tk, int var_index);
extern int lookupVar_index(char s[]);
extern int lookupID(char s[]);
extern void initTable();
#endif
