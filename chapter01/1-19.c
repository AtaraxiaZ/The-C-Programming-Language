#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void reverse(char to[], char from[], int len);

// print longest input line
int main()
{
    int len;
    char line[MAXLINE];
    char rev[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0){
        reverse(rev, line, len);
        for (int i = 0; i < MAXLINE && rev[i] != '\0'; i++){
            printf("%c", rev[i]);
        }
    }
    return 0;
}

void reverse(char to[], char from[], int len){
    for(int i=len-1; i >= 0; i--){
        to[len-i-1] = from[i];
    }
    to[len] = '\0';
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

void copy(char to[], char from[]){
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0'){
        ++i;
    }
}
