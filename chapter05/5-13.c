#include "../lib/mygetline.h"
#include <stdlib.h>
#include <stdio.h>

void writelines(char *lineptr[], int nlines, int tail);

int main(int argc, char *argv[]){
    int tail = 10;
    char *lines[100];
    char *c;
    if (--argc > 0 && (*++argv)[0] == '-')
        if ((c = (++argv)[0])){
            tail = atoi(c);
        }
    int nlines = readlines(lines);
    writelines(lines, nlines, tail);
}

void writelines(char *lineptr[], int nlines, int tail){
    int i;
    if (tail >= nlines){
        tail = nlines;
    }

    for (i = nlines-tail; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
