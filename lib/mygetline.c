#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mygetline.h"



int mygetline(char s[], int lim){
    int c, i;

    // press ctrl+d to send EOF
    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[]){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0)
        if (nlines >= MAXLINES || (p = malloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines){
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
