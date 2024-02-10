#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    int c;
    int (*convert)(int) = NULL;
    char *prog = argv[0];

    if (strstr(prog, "lower") != NULL)
        convert = tolower;
    else if (strstr(prog, "upper") != NULL)
        convert = toupper;
    else {
        fprintf(stderr, "Usage: %s [lower|upper]\n", prog);
        return 1;
    }

    while ((c = getchar()) != EOF)
        putchar(convert(c));
    return 0;
}
