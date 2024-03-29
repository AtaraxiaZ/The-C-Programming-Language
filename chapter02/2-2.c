#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int lim);


int main(){
    int len;
    char line[MAXLINE];
    while ((len = mygetline(line, MAXLINE)) != 0){
        printf("%s", line);
    }
}




int mygetline(char s[], int lim){
    int c, i;

    for (i=0; i < lim-1; ++i){
        if ((c = getchar()) != EOF) {
            if ( c != '\n') {
                s[i] = c;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
