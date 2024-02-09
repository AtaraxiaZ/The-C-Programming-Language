#include <ctype.h>
#include <stdio.h>


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
    return word[0];
}

// Another way is to define two functions
int asalpha(char c){
	return isalpha(c) || c == '_';
}

/* is character we treat As alphabetic or is numeric */
int asalnum(char c){
	return isalnum(c) || c == '_';
}
