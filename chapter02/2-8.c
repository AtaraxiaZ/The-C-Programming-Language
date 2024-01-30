#include <stdio.h>


int rightrot(unsigned x, int n);

int main(){
    unsigned int a = 0b1110101001110101;
    int res = rightrot(a, 3);
    printf("%u\n", res);
}

int rightrot(unsigned x, int n){

    
    int mask = (1u << n) - 1;

    int remain = x & mask;

    remain = remain << (32 - n);

    x = remain | (x >> n);

    return x;
}
