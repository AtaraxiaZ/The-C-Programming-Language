// :make ../lib/mygetline.c ../lib/alloc.c
#include "../lib/alloc.h"
#include "../lib/mygetline.h"
#include <string.h>
#include <stdio.h>
#define MAXLEN 1000
#define MAXLINES 10

int readlines(char *lineptr[], int maxlines);

int main(){
    char *linearr[10];
    int nlines = readlines(linearr, MAXLINES);
    for (int i=0; i < nlines; i++){
        printf("%s\n", linearr[i]);
    }
    return 0;
}

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}
