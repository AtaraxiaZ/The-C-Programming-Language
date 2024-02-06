#include "../lib/mygetline.h"
#include <stdio.h>

int strend(char *s, char *t);

int main(){
    char s[100];
    char t[100];
    mygetline(s, 100);
    mygetline(t, 100);
    printf("%d\n", strend(s, t));
    return 0;
}


int strend(char *s, char *t){
    int i, j;
    i = j = 0;
    while (*(s+i) != '\0'){
        i++;
    }
    while (*(t+j) != '\0'){
        j++;
    }
    for (; j >= 0;i--, j--){
        if (*(s+i) != *(t+j)){
            return 0;
        }
    }
    return 1;
}
