#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int lim);
void squeeze(char s1[], char s2[]);

int main(){
    char line1[MAXLINE];
    char line2[MAXLINE];
    mygetline(line1, MAXLINE);
    mygetline(line2, MAXLINE);
    squeeze(line1, line2);
    printf("%s\n", line1);
}

void squeeze(char s1[], char s2[]){
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++){
            if (s1[i] == s2[j])
                break;
        }
        if (s2[j] == '\0'){
            s1[k++] = s1[i];
        }
    }
    s1[j] = '\0';
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
