#include "../lib/mygetline.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>

double atof(char s[]);

int main(){
    char s[1000];
    mygetline(s, 1000);
    double res = atof(s);
    printf("%f\n", res);
}

double atof(char s[]){
    double val, power;
    int i, sign;
    int exp_sign;
    int exp;
    double res;

    for (i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    res = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E'){
        i++;
        if (s[i] == '+' || s[i] == '-'){
            exp_sign = (s[i] == '-') ? -1 : 1;
            i++;
        } else {
            exp_sign = 0;
        }
        for (exp = 0.0; isdigit(s[i]); i++){
            exp = 10.0 * exp + (s[i] - '0');
        }
        if (exp_sign){
            res /= pow(10, exp);
        } else {
            res *= pow(10, exp);
        }
    }
    return res;
}
