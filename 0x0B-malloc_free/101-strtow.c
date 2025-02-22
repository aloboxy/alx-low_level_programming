#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strtow - Splits a string into words.
 * @str: The input string to split.
 *
 * Return: A pointer to an array of strings (words), or NULL on failure.
 */
char **strtow(char *str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    int word_count = 0;
    int in_word = 0; 
    char *temp = str;

    
    while (*temp) {
        if (*temp != ' ') {
            if (!in_word) {
                word_count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
        temp++;
    }

    if (word_count == 0) {
        return NULL; 
    }

   
    char **words = malloc((word_count + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL;
    }

    int word_index = 0;
    in_word = 0;
    char *start = str;

    
    while (*str) {
        if (*str != ' ') {
            if (!in_word) {
                start = str;
                in_word = 1;
            }
        } else {
            if (in_word) {
               
                int word_length = str - start;
                words[word_index] = malloc((word_length + 1) * sizeof(char));
                if (words[word_index] == NULL) {
                   
                    for (int i = 0; i < word_index; i++) {
                        free(words[i]);
                    }
                    free(words);
                    return NULL;
                }
                strncpy(words[word_index], start, word_length);
                words[word_index][word_length] = '\0';
                word_index++;
                in_word = 0;
            }
        }
        str++;
    }

   
    if (in_word) {
        int word_length = str - start;
        words[word_index] = malloc((word_length + 1) * sizeof(char));
        if (words[word_index] == NULL) {
           
            for (int i = 0; i < word_index; i++) {
                free(words[i]);
            }
            free(words);
            return NULL;
        }
        strncpy(words[word_index], start, word_length);
        words[word_index][word_length] = '\0';
        word_index++;
    }

    words[word_index] = NULL;
    return words;
}

/**
 * print_words - Helper function to print the array of words.
 * @words: The array of words to print.
 */
void print_words(char **words) {
    if (words == NULL) {
        printf("NULL\n");
        return;
    }
    for (int i = 0; words[i] != NULL; i++) {
        printf("%s\n", words[i]);
    }
}

/**
 * free_words - Helper function to free the array of words.
 * @words: The array of words to free.
 */
void free_words(char **words) {
    if (words == NULL) {
        return;
    }
    for (int i = 0; words[i] != NULL; i++) {
        free(words[i]);
    }
    free(words);
}

int main(void) {
    char *str = "  Hello world!  This is a test.  ";
    char **words = strtow(str);

    print_words(words); 
    free_words(words);

    return 0;
}
