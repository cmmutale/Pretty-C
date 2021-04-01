#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p2.h"

void write_char(){
    printf("<u><span style='color:brown;'>");
    write_html();
    printf("</span></u>");
}

void write_string(){
    printf("<span style='color:red;'>");
    write_html();
    printf("</span>");
}

void write_oct(){
    printf("<i><span style='color:brown;'>");
    write_html();
    printf("</span></i>");
}

void write_hex(){
    printf("<i><span style='color:brown;'>");
    write_html();
    printf("</span></i>");
}

void write_int(){
    printf("<span style='color:brown;'>");
    write_html();
    printf("</span>");
}

void write_fp(){
    printf("<span style='color:brown;'>");
    write_html();
    printf("</span>");
}

void write_id(){
    int tk = lookupVar_index(yytext);
    int check = lookupID(yytext);

    if (tk == -1){
        // check keywords
        printf("<a name='%s'><span style='color:blue; font-weight:bold;'>", yytext);
        write_html();
        printf("</span></a>");
        printf(" ");
    }else{
        if (check == -1){
            printf("<a name='%s'><span style='color:blue;'>", yytext);
            write_html();
            printf("</span></a>");
            //printf(" ");
        }else{
            printf("<a href='#%s'><span style='color:blue;'>", yytext);
            write_html();
            printf("</span></a>");
            //printf(" ");
        }
            int insert = (int)installID(yytext, ID, 0);

    }
    
}

//-----INDENT--------
void write_begin(){
    write_indent();
    write_html();
    column += INDENT;
    write_indent();
        //write_indent();
}

void write_end(){
    column -= INDENT;
    write_indent();
    write_html();
    write_indent();

}

void write_open(){
    write_html();
    putchar(' ');
    paren++;

}

void write_close(){
    write_html();
    putchar(' ');
    paren--;

}

void write_bopen(){
    write_html();

}

void write_bclose(){
    write_html();

}

void write_sep(){
    write_html();
    if (!paren){
        write_indent();
    }else{
        putchar(' ');
    }

}

void write_op(){
    printf("<span style='color:black;'>");
    write_html();
    printf("</span></b>");

}

void write_inline(){
    printf("<span style='color:green;'>");
    write_html();
    printf("\n");
    printf("</span>");

}

void write_comment(){
    printf("<span style='color:green;'>");
    write_html();
    printf("\n");
    printf("</span>");
}


void write_derivative(){
    if((yytext[0] == '<')||(yytext[0] == '"')){
        printf("<span style='color:magenta; font-weight:bold;'>");
        write_html();
        printf("</span>");
        printf("\n");
    }else{
        printf("<span style='color:magenta; font-weight:bold;'>");
        write_html();
        printf("</span>");
    }
}

void write_indent(){
    //printf("\n%-*d", column, line++);
    printf("\n%-*d", column, line++);
}

void write_html_char(int c){
    switch (c)
    {
    case '<':
        printf("&lt");
        break;
    case '>':
        printf("&gt");
        break;
    case '"':
        printf("&quot");
        break;
    case '&':
        printf("&amp");
        break;
    case '\n':
        break;
    
    default:
        putchar(c);
    }
}

void write_html(){
    char *s = yytext;
    while (*s)
        write_html_char(*s++);
}

