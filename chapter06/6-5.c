#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define HASHSIZE 101

struct nlist *lookup(char *);
static struct nlist *hashtab[HASHSIZE];

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

unsigned hash(char *s){
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s){
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
         if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *name, char *defn){
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL){
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free((void *) np->defn);
    }
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

int undef(char *name){
    struct nlist *prev = NULL;
    struct nlist *np;
    unsigned hashval;
    
    for (np = hashtab[hash(name)]; np != NULL; np = np->next){
        if (strcmp(name, np->name) == 0){
            if (prev == NULL)
                hashtab[hash(name)] = np->next;
            else
                prev->next = np->next;
            free((void *) np);
            return 0;
        } else {
            prev = np;
        }
    }
    printf("Entry not found!\n");
    return 1;
}

int main(){
    char *a = "abcd";
    char *b = "efgh";
    install(a, b);
    struct nlist *p = lookup(a);
    printf("%s\n", p->defn);
    if (undef(a) == 0){
        printf("undef %s\n", a);
    }
    undef(b);
    return 0;
}
