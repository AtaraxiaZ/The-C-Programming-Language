// :make ../lib/mygetline.c ../lib/alloc.c
#include "../lib/mygetline.h"
#include <stdio.h>
#define MAXLEN 100
#define BUFSIZE 1000
#define MAXLINES 10

int readlines(char *lineptr[], char * buffer);
void writelines(char *lineptr[], int nlines);

int main(){
    char *linearr[10];
    char buffer[MAXLEN];
    int nlines;
    if ((nlines = readlines(linearr, buffer)) >= 0){
        writelines(linearr, nlines);
    }
    return 0;
}

int readlines(char *lineptr[], char * buffer){
    int len, nlines;
    char *bufmax = buffer + BUFSIZE - MAXLEN;

    nlines = 0;
    while ((len = mygetline(buffer, MAXLEN)) > 0){
        lineptr[nlines++] = buffer;
        buffer += len;
        *(buffer - 1) = '\0';
        if (nlines >= MAXLINES || buffer > bufmax)
            return -1;
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines){
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
