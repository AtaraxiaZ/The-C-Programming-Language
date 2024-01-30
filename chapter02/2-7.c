#include <stdio.h>


int invert(unsigned x, int p, int n);

int main(){
    unsigned int a = 0b1110101001110101;
    unsigned int b = 0b0100101001011010;
    int res = invert(a, 7, 3);
    printf("%u\n", res);
}

int invert(unsigned x, int p, int n){
    int mask = ((1u << p) - 1) ^ ((1u << (p-n)) - 1);

    x = x ^ mask;

    return x;
}
