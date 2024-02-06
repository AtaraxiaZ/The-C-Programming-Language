#include <stdio.h>

#define MAXLEN 1000

void detab(char s[], char d[], int len, int N);
void entab(char s[], char d[], int len, int N);
int mygetline(char s[], int lim);

int main(int argc, char *argv[]){
    int N = 4;
    int len;
    char inLine[MAXLEN];
    char outLine[MAXLEN];
    if (argc >= 2){
        for (int i = 1; i < argc; i++){
            if (*argv[i] == '\t')
                N += 4;
        }
    }
    while ((len = mygetline(inLine, MAXLEN)) != 0) {
        entab(inLine, outLine, len, N);
        printf("%s", outLine);
    }
    return 0;
}

void detab(char s[], char d[], int len, int N){
    int ptr_s;
    int ptr_d;
    int blank;
    for (ptr_s = 0, ptr_d = 0; ptr_s < len; ptr_s++){
        if (s[ptr_s] == '\t'){
            blank = N - ptr_d % N;
            for(int i = 0; i < blank; i++)
                d[ptr_d+i] = ' ';
            ptr_d += blank;
        } else {
            d[ptr_d] = s[ptr_s];
            ptr_d++;
        }
    }
    d[ptr_d] = '\0';
}

void entab(char s[], char d[], int len, int N){
    int ptr_s;
    int ptr_d;
    int space = 0;
    int tabblank;
    for (ptr_s = 0, ptr_d = 0; ptr_s < len; ptr_s++){
        tabblank = N - ptr_d % N;
        if (ptr_s == ' '){
            space++;
            if (space == N || space == tabblank){
                d[ptr_d] = '\t';
                space = 0;
            }
        } else {
            for (int i = 0; i < space; i++)
                d[ptr_d++] = ' ';
            space = 0;
            d[ptr_d++] = s[ptr_s];
        }
    }
    d[ptr_d] = '\0';
}

int mygetline(char s[], int lim){
    int c, i;

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
