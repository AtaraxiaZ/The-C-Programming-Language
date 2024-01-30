#include <stdio.h>


int bitcount(unsigned x);

int main(){
    unsigned int a = 0b0000100000000000;
    int res = bitcount(a);
    printf("%u\n", res);
}

int bitcount(unsigned x){
    int i;
    int res = 0;

    for (i = 0; i < 32; i++){
        if ((x = ((x - 1) & x)) != 0)
            res += 1;
        else {
            res += 1;
            break;
        }
    }


    return res;
}
