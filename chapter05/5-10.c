#include <stdlib.h>
#include <stdio.h>

char buffer[100];
int bufptr = 0;
void push(int c);
int pop();

int main(int argc, char *argv[]){
    int op2;
    printf("%d of commands\n", argc);

    for (int i = 1; i < argc; i++){
        switch (*argv[i]){
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                push(pop() / op2);
                break;
            default:
                push(atoi(argv[i]));
        }
    }
    printf("%d\n", pop());
    return 0;
}

void push(int c){
    if (bufptr != 100){
        buffer[bufptr++] = c;
    }
}

int pop(){
    if (bufptr != 0){
        return buffer[--bufptr];
    } else {
        return 0;
    }
}
