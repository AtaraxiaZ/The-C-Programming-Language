// 和vim里的gq功能一样
#include <stdio.h>

#define N 30
#define MAXLEN 1000

void fold(char s[], char d[], int len);
int mygetline(char s[], int lim);

int main(){
    int len;
    char inLine[MAXLEN];
    char outLine[MAXLEN];
    while ((len = mygetline(inLine, MAXLEN)) != 0) {
        fold(inLine, outLine, len);
        printf("%s", outLine);
    }
    return 0;
}

void fold(char s[], char d[], int len){
    int ptr_s;
    int ptr_d;
    for (ptr_s = 0, ptr_d = 0; ptr_s < len; ptr_s++){
        if (s[ptr_s] == '\t' || s[ptr_s] == ' ')
            continue;
        if (ptr_d % N  == N-1){
            d[ptr_d++] = '\n';
        } else {
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
