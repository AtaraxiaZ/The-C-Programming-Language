// I use ChatGPT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

int isNoiseWord(const char *word){
    const char* noiseWords[] = {"the", "and", "a", "an", "in"};
    int numNoiseWords = sizeof(noiseWords) / sizeof(noiseWords[0]);
    
    for (int i = 0; i < numNoiseWords; i++) {
        if (strcmp(word, noiseWords[i]) == 0){
            return 1;
        }
    }
    return 0;
}

void printCrossReference(char **words, int *lineNumbers, int numWords){
    for (int i = 0; i < numWords; i++){
        printf("%s: ", words[i]);

        for (int j = 0; j < numWords; j++){
            if (lineNumbers[j] == i+1) {
                printf("%d, ", j+1);
            }
        }

        printf("\n");
    }
}

void toLowerCase(char* word){
    for (int i = 0; word[i]; i++){
        word[i] = tolower(word[i]);
    }
}

int main(){
    char ** words = malloc(MAX_WORD_LENGTH * sizeof(char*));
    int* lineNumbers = malloc(MAX_WORD_LENGTH * sizeof(int));
    int numWords = 0;

    FILE* file = fopen("documents.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int lineNum = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        lineNum++;

        char* word = strtok(line, " \t\n");
        while (word != NULL) {
            if (!isNoiseWord(word)) {
                toLowerCase(word);

                // Check if the word is already in the list
                int found = 0;
                for (int i = 0; i < numWords; i++) {
                    if (strcmp(words[i], word) == 0) {
                        lineNumbers[i] = lineNum;
                        found = 1;
                        break;
                    }
                }

                // Add the word to the list if not found
                if (!found) {
                    words[numWords] = strdup(word);
                    lineNumbers[numWords] = lineNum;
                    numWords++;
                }
            }

            word = strtok(NULL, " \t\n");
        }
    }

    fclose(file);

    // Print the cross-reference list
    printCrossReference(words, lineNumbers, numWords);

    // Free allocated memory
    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }
    free(words);
    free(lineNumbers);

    return 0;
}
