#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;

    if (argc == 3) {
        fp1 = fopen(argv[1], "r");
        fp2 = fopen(argv[2], "r");
    } else {
        fprintf(stderr, "The params number is wrong!\n");
        return 1;
    }

    char line1[100];
    char line2[100];
    int linenumber;

    for(linenumber = 0; linenumber < 100; linenumber++){
        fgets(line1, 100, fp1);
        fgets(line2, 100, fp2);
        if (strlen(line1) != strlen(line2)){
            printf("Not the same\n");
            return 1;
        }
        for (int i = 0; line1[i] == '\0'; i++){
            if (line1[i] != line2[i]){
                printf("Not the same\n");
                return 1;
            }
        }
    }
    printf("Same\n");
    return 0;
}
