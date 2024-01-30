#include <stdio.h>


int setbits(unsigned int x, int p, int n, unsigned int y);

int main(){
    unsigned int a = 0b1110101001110101;
    unsigned int b = 0b0100101001011010;
    int res = setbits(a, 7, 3, b);
    printf("%u\n", res);
}

int setbits(unsigned int x, int p, int n, unsigned int y){
    // Step 1: Extract the rightmost n bits of y
    unsigned rightmostNBits = y & ((1U << n) - 1);

    // Step 2: Shift these bits to the desired position
    unsigned shiftedNBits = rightmostNBits << (p - n + 1);

    // Step 3: Create a mask to clear n bits at position p in x
    unsigned mask = ~(((1U << n) - 1) << (p - n + 1));

    // Step 4: Clear the bits at position p in x
    x &= mask;

    // Step 5: Combine x with the shifted bits from y
    x |= shiftedNBits;

    return x;
}
