#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int lim);
int any(char s1[], char s2[]);

int main(){
    int loc;
    char line1[MAXLINE];
    char line2[MAXLINE];
    mygetline(line1, MAXLINE);
    mygetline(line2, MAXLINE);
    loc = any(line1, line2);
    printf("%d\n", loc);
}

int any(char s1[], char s2[]){
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++){
            if (s1[i] == s2[j])
                return i;
        }
    }
    return -1;
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
