#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int main(int argc, char *argv[]){
    int maxword = 6;
    struct tnode *root;
    char word[maxword];
    if (argc > 1)
        maxword = atoi(argv[1]);

    root = NULL;
    while (getword(word, maxword) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getword(char *word, int lim){
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    
    while(isspace(c = getch()));

    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) && c != '_') {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            if (*w != '_') {
                ungetch(*w);
                break;
            }
        }
    *w = '\0';
    while((c = getch() != '\n'));
    return word[0];
}

struct tnode *talloc(void);
char *mystrdup(char *);

struct tnode *addtree(struct tnode *p, char *w){
    int cond;

    if (p == NULL){
        p = talloc();
        p->word = mystrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

void treeprint(struct tnode *p){
    if (p != NULL){
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *mystrdup(char *s){
    char *p;
    
    p = (char *) malloc(strlen(s)+1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

