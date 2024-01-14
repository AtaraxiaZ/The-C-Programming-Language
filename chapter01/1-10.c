#include <stdio.h>

void main(){
    int c;
    int flag = 0;
    while((c = getchar()) != EOF){
        if (c == '\t'){
            putchar('\\');
            putchar('t');
        } else if (c == ' '){
            putchar('\\');
            putchar('b');
        } else if (c == '\\'){
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }
}
