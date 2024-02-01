#include <stdio.h>
#include "mygetline.h"

int mygetline(char s[], int lim){
    int c, i;

    // press ctrl+d to send EOF
    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
