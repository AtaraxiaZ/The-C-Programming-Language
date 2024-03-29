#include <stdio.h>

#define LEN 10

void main(){
    int c;
    int word = 0;
    int length = 0;
    int ndigit[LEN];

    for (int i = 0; i < LEN; i++) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n') {
            ndigit[length]++;
            length = 0;
        } else {
            length++;
        }
    }
    for (int i = 0; i < LEN; i++) {
        printf("%d: ", i);
        for (int j = 0; j < ndigit[i]; j++)
            putchar('|');
        putchar('\n');
    }
}

