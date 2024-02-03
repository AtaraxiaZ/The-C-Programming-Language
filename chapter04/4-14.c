#include <stdio.h>
#define swap(t, x, y) {t temp = x; x = y; y = temp;}

int main(){
    int a = 10;
    int b = 3;
    swap(int, a, b);
    printf("%d, %d\n", a, b);
}
