#include <stdio.h>

int lower(char x);

int main(){
    char c;
    char res;
    while ((c = getchar()) != EOF){
        res = lower(c);
        printf("%c", res);

    }
    printf("%u\n", res);
}

int lower(char c){
    return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}
