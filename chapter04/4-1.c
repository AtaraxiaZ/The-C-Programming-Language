#include <stdio.h>
#include "../lib/mygetline.h"

int mygetline(char s[], int lim);
int strindex(char s[], char t[]);

int main(){
    char s1[1000];
    char s2[1000];
    int len1 = mygetline(s1, 1000);
    mygetline(s2, 1000);
    int res = strindex(s1, s2);
    printf("The first position is %d\n", len1 - res - 1);
    return 0;
}

int strindex(char s[], char t[]){
    int i,j,k;

    for (i = 0; s[i] != '\0'; i++){
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
