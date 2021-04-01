#include <stdio.h>
#include "p2.h"

int main(){
    initTable();
    printf("<html><pre>\n");
    yylex();
    printf("</pre></html>\n");
    return 0;
}
