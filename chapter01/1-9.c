#include <stdio.h>

void main(){
    int c;
    int flag = 0;
    while((c = getchar()) != EOF){
        if (c == ' '){
            if (flag == 1){
                continue;
            } else {
                flag = 1;
                putchar(c);
            }
        } else {
            flag = 0;
            putchar(c);
        }
    }
}
