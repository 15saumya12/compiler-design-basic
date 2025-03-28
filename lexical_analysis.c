#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define keywords
char *keywords[] = {"if", "else", "while", "for", "int", "char", "float", "double"};

// Define operators
char *operators[] = {"+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">="};

// Function to check if a word is a keyword
int is_keyword(char *word) {
    int i;
    for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is an operator
int is_operator(char c) {
    int i;
    for (i = 0; i < sizeof(operators) / sizeof(operators[0]); i++) {
        if (operators[i][0] == c) {
            return 1;
        }
    }
    return 0;
}

// Function to perform lexical analysis
void lexical_analysis(FILE *file) {
    char c;
    char word[100];
    int word_index = 0;

    while ((c = fgetc(file)) != EOF) {
        // Check for keywords and identifiers
        if (isalpha(c) || c == '_') {
            word[word_index++] = c;
        } else if (word_index > 0) {
            word[word_index] = '\0';
            if (is_keyword(word)) {
                printf("Keyword: %s\n", word);
            } else {
                printf("Identifier: %s\n", word);
            }
            word_index = 0;
        }

        // Check for operators
        if (is_operator(c)) {
            printf("Operator: %c\n", c);
        }

        // Check for numbers
        if (isdigit(c)) {
            printf("Number: %c\n", c);
        }
    }
}

int main() {
    FILE *file;
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }


    lexical_analysis(file);

    fclose(file);
    return 0;
}
