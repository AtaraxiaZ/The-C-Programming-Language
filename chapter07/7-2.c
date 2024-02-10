#include <stdio.h>
#include <stdlib.h>
#include "../lib/mygetline.h"

int can_print(char ch);

int main(int argc, char *argv[]){
    int oct0_hex1;
    if (argc == 1 && *argv[1] == '8'){
        oct0_hex1 = 0;
    } else {
        oct0_hex1 = 1;
    }
    char *line = malloc(sizeof(char) * 100);
    int len;
    while((len = mygetline(line, 100)) != 0){
        for (int i = 0; i < len; i++){
            if (can_print((int)line[i]))
                putchar(line[i]);
            else{
                printf(oct0_hex1 ? "\\x%02x" : "\\%03o", line[i]);
            }
        }
    }
}


int can_print(char ch)
{
    char *printable = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !\"#%&'()*+,-./:;<=>?[\\]^_{|}~\t\f\v\r\n";

    char *s;
    int found = 0;

    for(s = printable; !found && *s; s++) {
        if(*s == ch) {
            found = 1;
        }
    }

    return found;
}
