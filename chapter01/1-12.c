#include <stdio.h>

#define IN  1
#define OUT 0

void main(){
    int c, nw, state;
    while((c = getchar()) != EOF){
        if (c != '\n' && c != '\t' && c != ' '){
            putchar(c);
        } else {
            putchar('\n');
        }
    }
}
