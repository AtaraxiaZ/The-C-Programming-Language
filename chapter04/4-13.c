#include <stdio.h>

void reverse(char s[], int i, int j);

int main(){
    char s[8] = "abcdefg";
    reverse(s, 0, 6);
    printf("%s\n", s);
    return 0;
}

void reverse(char s[], int i, int j){
    if (i < j){
        reverse(s, i+1, j-1);
    }
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
