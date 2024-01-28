// 因为输入的shell本身就会把tab对齐，所以很难看出效果
#include <stdio.h>

#define N 7
#define MAXLEN 1000

void detab(char s[], char d[], int len);
int mygetline(char s[], int lim);

int main(){
    int len;
    char inLine[MAXLEN];
    char outLine[MAXLEN];
    while ((len = mygetline(inLine, MAXLEN)) != 0) {
        detab(inLine, outLine, len);
        printf("%s", outLine);
    }
    return 0;
}

void detab(char s[], char d[], int len){
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
