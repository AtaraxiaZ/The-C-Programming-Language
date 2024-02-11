#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void filecopy(int ifp, int ofp);

int main(int argc, char *argv[]){
    int fp;

    if (argc == 1)
        filecopy(0, 1);
    else
        while(--argc > 0)
            if ((fp = open(*++argv, O_RDONLY, 0)) == -1) {
                printf("cat: can't open %s\n", *argv);
                return 1;
            } else {
                filecopy(fp, 1);
                close(fp);
            }
    return 0;
}

void filecopy(int ifp, int ofp){
    char buffer;

    while((read(ifp, &buffer, 1)) == 1)
        write(ofp, &buffer, 1);
}
