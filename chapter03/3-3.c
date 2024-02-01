#include <stdio.h>
#include "../lib/mygetline.h"

#define MAXLINE 1000

void expand(char s1[], char s2[], int len);

int main(){
    int len;
    char line[MAXLINE];
    char res[MAXLINE];
    while ((len = mygetline(line, MAXLINE)) != 0){
        expand(line, res, len);
        printf("%s", res);
    }
    return 0;
}

void expand(char s1[], char s2[], int len){
    s2[0] = s1[0];
    int dst_ptr = 1;
    for (int i = 1; i < len; i++){
        if (s1[i] == '-') {
            if (s1[i-1] >= 'a' && s1[i-1] <= 'z'){
                if (s1[i+1] >= 'a' && s1[i+1] <= 'z'){
                    if (s1[i+1] >= s1[i-1]) {
                        for (int j = ++s1[i-1]; j <= s1[i+1]; j++){
                            s2[dst_ptr++] = j;
                        }
                        i++;
                    } else {
                        for (int j = --s1[i+1]; j >= s1[i+1]; j--){
                            s2[dst_ptr++] = j;
                        }
                        i++;
                    }
                } else {
                    s2[dst_ptr++] = s1[i];
                }
            } else if (s1[i-1] >= '0' && s1[i-1] <= '9'){
                if (s1[i+1] >= '0' && s1[i+1] <= '9'){
                    if (s1[i+1] >= s1[i-1]) {
                        for (int j = ++s1[i-1]; j <= s1[i+1]; j++){
                            s2[dst_ptr++] = j;
                        }
                        i++;
                    } else {
                        for (int j = --s1[i+1]; j >= s1[i+1]; j--){
                            s2[dst_ptr++] = j;
                        }
                        i++;
                    }
                } else {
                    s2[dst_ptr++] = s1[i];
                }
            } else {
                s2[dst_ptr++] = s1[i];
            }
        } else {
            s2[dst_ptr++] = s1[i];
        }
    }

    s2[dst_ptr] = '\0';
}



