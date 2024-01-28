// 只实现//的注释，/* */的注释不考虑
#include <stdio.h>

#define N 30
#define MAXLEN 1000

void remove_comment(char s[], char d[], int len);
int mygetline(char s[], int lim);

int main(){
    int len;
    char inLine[MAXLEN];
    char outLine[MAXLEN];
    while ((len = mygetline(inLine, MAXLEN)) != 0) {
        remove_comment(inLine, outLine, len);
        printf("%s", outLine);
    }
    return 0;
}

void remove_comment(char s[], char d[], int len){
    int ptr_s;
    int ptr_d;
    int comment = 0;
    int singlestring = 0;
    int doublestring = 0;
    for (ptr_s = 0, ptr_d = 0; ptr_s < len; ptr_s++){
        char ch = s[ptr_s];
        if (singlestring){
            if (ch == '\''){
                singlestring = 0;
            } else {
                d[ptr_d++] = ch;
            }
        } else if (doublestring){
            if (ch == '\"'){
                doublestring = 0;
            } else {
                d[ptr_d++] = ch;
            }
        } else if (comment) {
            if (ch == '/') {
                d[--ptr_d] = '\0';
                break;
            } else {
                d[ptr_d++] = ch;
                comment = 0;
            }
        } else {
            if (ch == '/'){
                d[ptr_d++] = ch;
                comment = 1;
            } else {
                d[ptr_d++] = ch;
            }
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
