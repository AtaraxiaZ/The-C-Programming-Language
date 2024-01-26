#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

// print longest input line
int main()
{
    int len;
    char line[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0){
        if (line[0] == '\n') continue;
        for (int i=len-1; i >= 0; i--){
            if (line[i] == ' ' || line[i] == '\t')
                line[i] = '\0';
        }
        for (int i = 0; i < MAXLINE && line[i] != '\0'; i++){
            if (line[i] != ' ' && line[i] != '\t') 
            printf("%c", line[i]);
        }
    }
    return 0;
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
