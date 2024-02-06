#include <stdio.h>


void mystrcat(char *s, char *t);

int main(){
    char s[100] = "abcd";
    char t[5] = "efgh";
    mystrcat(s, t);
    printf("%s\n", s);
    return 0;
}

void orgstrcat(char s[], char t[]){
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0');
}

void mystrcat(char *s, char *t){
    int i, j;
    i = j = 0;
    while (*(s+i) != '\0')
        i++;
    while ((*(s+i) = *(t+j)) != '\0'){
        i++;
        j++;
    }
}
