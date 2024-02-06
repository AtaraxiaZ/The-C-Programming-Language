#include <strings.h>

void strncpy(char *s, char *t, int n);
void strncat(char *s, char *t, int n);
int strncmp(char *s, char *t, int n);


void strncpy(char *s, char *t, int n){
    for (int i = 0; i < n; i++){
        *(s+i) = *(t+i);
    }
}

void strncat(char *s, char *t, int n){
    int i = 0;
    while (*(s+i) != '\0')
        i++;
    for (int j = 0; i < n; j++){
        *(s+i) = *(t+j);
        i++;
    }
}

int strncmp(char *s, char *t, int n){
    for (int i = 0; i < n; i++){
        if (s[i] != t[i])
            return 1;
    }
    return 0;
}
