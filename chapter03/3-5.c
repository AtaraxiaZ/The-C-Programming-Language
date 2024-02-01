#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);
void itoa(int n, char s[], int b);


int main(){
    int a = INT_MIN;
    int b = 20;
    int c = -10;
    char res[1000];
    itoa(a, res, 2);
    printf("%d, %s\n", a, res);
    itoa(b, res, 2);
    printf("%d, %s\n", b, res);
    itoa(c, res, 16);
    printf("%d, %s\n", c, res);
}


void itoa(int n, char s[], int b){
    int i, sign;
    int flag = 0;

    if ((sign = n) < 0){
        if (n == -n){
            flag = 1;
            n = -(n+1);
        } else {
            n = -n;
        }
    }
    i = 0;
    do {
        if (n % b > 9){
            s[i++] = n % b - 10 + 'A';
        } else {
            s[i++] = n % b + '0';
        }
    } while ((n = (n / b)) > 0);
    if (flag) {
        // The INT_MIN just don't care
        // s[0]++;
    }
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]){
    int len = strlen(s);
    char temp;
    for(int i=0, j=len-1; i < j; i++, j--){
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}
