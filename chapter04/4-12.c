// This problem is very interesting!
// Actually, recursive is easy to understand
#include <stdio.h>

void itoa(int a, char s[]);

int main(){
    int a;
    char s[100];
    scanf("%d", &a);
    itoa(a, s);
    printf("%s\n", s);
    return 0;
}

void itoa(int a, char s[]) {
    static int i = 0;
    if (a < 0) {
        s[i++] = '-';
        a = -a; // We don't taker care INT_MIN
    }
    
    if (a / 10) {
        itoa(a / 10, s);
    }
    s[i++] = a % 10 + '0';
}
