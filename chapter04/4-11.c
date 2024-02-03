#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define LETTER 'A'

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

#define BUFSIZE 100
int buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
void ungets(char s[]);

int getop(char []);
void push(double);
double pop(void);
void peek();

void duplicate();
void swap();
void clear();

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case LETTER:
                if (s[0] == 'P')
                    peek();
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor");
                break;
            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
}

void push(double f){
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf("error stack empty!\n");
        return 0.0;
    }
}

int getop(char s[]){
    int i, c;
    static int bufp;
    while ((s[0] = c = (bufp = 1) ? buf[--bufp] : getchar()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-'){
        if (isalpha(c))
            return LETTER;
        return c;
    }
    i = 0;
    while (isdigit(s[++i] = c = (bufp = 1) ? buf[--bufp] : getchar()));
    if (c == '.')
        while (isdigit(s[++i] = c = (bufp = 1) ? buf[--bufp] : getchar()));
    s[i] = '\0';
    if (bufp == 1)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;

    return NUMBER;
}


void ungets(char s[]){
    for (int i = 0; s[i] != '\0'; i++)
        ungetch(s[i]);
}

void peek(){
    char temp = pop();
    printf("%c", temp);
    push(temp);
}

void duplicate(){
    char temp = pop();
    push(temp);
    push(temp);
}

void swap(){
    char temp1 = pop();
    char temp2 = pop();
    push(temp1);
    push(temp2);
}

void clear(){
    sp = 0;
}
