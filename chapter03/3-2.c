#include <stdio.h>
#include "../lib/mygetline.h"

void escape(char s[], char t[], int len);
int mygetline(char s[], int lim);

int main(){
    char source[1000];
    char dest[1000];
    int len;

    while ((len = mygetline(source, 1000)) != 0){
        escape(source, dest, len);
        printf("%s", dest);
    }
}

void escape(char s[], char t[], int len){
    int j=0;
    for (int i = 0; i < len; i++){
        switch (s[i]){
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
        }
    }
    t[j] = '\0';
}

int mygetline(char s[], int lim){
    int c, i;

    // press ctrl+d to send EOF
    for (i=0; i < lim-1 && (c=getchar()) != EOF; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
