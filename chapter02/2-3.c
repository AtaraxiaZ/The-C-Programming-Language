#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int mygetline(char s[], int lim);
int htoi(char s[], int len);
int main(){
    int len;
    char line[1000];
    while((len = mygetline(line, 1000)) != 0){
        printf("%d\n", htoi(line, len));
    }
}

int htoi(char s[], int len){
    int res = 0;
    printf("htoi received %s with length %d\n", s, len);
    for (int i = 0; i < len; i++){
        if (s[i] >= '0' && s[i] <= '9' )
            res += (s[i] - '0') * pow(16, (len - 1 - i));
        else {
            switch(s[i]){
                case 'A':
                case 'a':
                    res += 10 * pow(16, (len - 1 - i));
                    break;
                case 'B':
                case 'b':
                    res += 11 * pow(16, (len - 1 - i));
                    break;
                case 'C':
                case 'c':
                    res += 12 * pow(16, (len - 1 - i));
                    break;
                case 'D':
                case 'd':
                    res += 13 * pow(16, (len - 1 - i));
                    break;
                case 'E':
                case 'e':
                    res += 14 * pow(16, (len - 1 - i));
                    break;
                case 'F':
                case 'f':
                    res += 15 * pow(16, (len - 1 - i));
                    break;
                default:
                    printf("Error character!");
                break;
            }
        }
    }
    return res;
}

int mygetline(char s[], int lim){
    int c, i;
    int j;

    for (i=0, j=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i){
        if (i == 0 && c == '0'){
            continue;
        } else if (i == 1 && (c == 'X' || c == 'x')){
            continue;
        } else {
            s[j++] = c;
        }
    }
    s[j] = '\0';
    return j;
}
