#include <stdio.h>

#define LEN 26

void main(){
    int c;
    int word = 0;
    int length = 0;
    int nchar[LEN];

    for (int i = 0; i < LEN; i++) {
        nchar[i] = 0;
    }

    while ((c = getchar()) != EOF){
        if (c >= 'A' && c <= 'Z') {
            nchar[c-'A']++;
        } else if (c >= 'a' && c <= 'z'){
            nchar[c-'a']++;
        }
    }
    for (int i = 0; i < LEN; i++) {
        printf("%c: ", i+'a');
        for (int j = 0; j < nchar[i]; j++)
            putchar('|');
        putchar('\n');
    }
}

