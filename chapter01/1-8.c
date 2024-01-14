#include <stdio.h>

void main(){
    int c, nb, nt, nl;
    nb = 0;
    nt = 0;
    nl = 0;
    c = getchar();
    while (c == ' ' || c == '\t' || c == '\n'){
        if (c == ' ')
            nb++;
        else if (c == '\t')
            nt++;
        else if (c == '\n')
            nl++;
        c = getchar();
    }
    printf("Blanks:%d\nTabs:%d\nNew Lines:%d\n", nb, nt, nl);
}
