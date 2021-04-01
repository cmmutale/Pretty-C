#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p2.h"

struct table symtable[1024];

int lastentry = 0;
int symEntry = 0;

int lookupID(char s[]) {
    int p;
    int rc = -1;

    for (p = 0; p < lastentry; p++) {
        if (strcmp(symtable[p].lexptr, s) == 0) {
            rc = p;
            break;
        }
    }
    return(rc);
}

int lookupVar_index(char s[]) {
    int p;
    int rc = -2;

    for (p = 0; p < lastentry; p++) {
        if (strcmp(symtable[p].lexptr, s) == 0) {
            rc = symtable[p].var_index;
            break;
        }
    }
    return(rc);
}

int installID(char s[], int tk, int var_index){
    int rc;

    rc = lookupID(s);

    if (rc == -1){
        // execute if id is not in table
        if(lastentry+1 == 1024){
            printf("Symbol table full!!");
        }

        symtable[lastentry].token = tk;

        symtable[lastentry].lexptr = (char *)malloc(strlen(s)+1); // ' ' 
        strcpy(symtable[lastentry].lexptr, s);  // yytext copies to lexptr at index lastentry

        if (var_index == 0) {
	        symtable[lastentry].var_index = symEntry++;
	    } else {
	        symtable[lastentry].var_index = var_index;
	    }

        rc = lastentry;
        lastentry++;
    }

    return(rc);
}

