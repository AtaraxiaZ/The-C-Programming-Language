#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/mygetline.h"

char *lineptr[MAXLINES];

void myqsort(void *v[], int left, int right, int (*comp)(const void *, const void *));
int numcmp(const char *s1, const char *s2);
void swap(void *v[], int i, int j);
void mywritelines(char *lineptr[], int nlines, int reverse);

int main(int argc, char *argv[]){
    int i = 0;
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int fold = 0;

    while (--argc > 0){
        i++;
        if (*argv[i] == '-'){
            switch(*(argv[i]+1)){
                case 'n': 
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                case 'f':
                    fold = 1;
                    break;
            }
        }
    }
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr)) >= 0){
        myqsort((void**) lineptr, 0, nlines-1, (int (*)(const void*, const void*))(numeric ? numcmp : strcmp));
        mywritelines(lineptr, nlines, reverse);
        return 0;
    } else {
        printf("input too big to sort");
        return 1;
    }
}


void myqsort(void *v[], int left, int right, int (*comp)(const void *, const void *)){
    int i, last;

    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    myqsort(v, left, last-1, comp);
    myqsort(v, last+1, right, comp);
}

int numcmp(const char *s1, const char *s2){
    double v1, v2;
    
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j){
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void mywritelines(char *lineptr[], int nlines, int reverse){
    int i;

    if (reverse){
        for (i = nlines-1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    }else {
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
    }
}
