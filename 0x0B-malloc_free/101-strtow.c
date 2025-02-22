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
        return NULL; // Handle edge cases
    }

    int word_count = 0;
    int in_word = 0; // Flag to track if we are inside a word
    char *temp = str;

    // Count the number of words
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
        return NULL; // No words found
    }

    // Allocate memory for the array of words
    char **words = malloc((word_count + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL; // Memory allocation failed
    }

    int word_index = 0;
    in_word = 0;
    char *start = str;

    // Extract words and store them in the array
    while (*str) {
        if (*str != ' ') {
            if (!in_word) {
                start = str; // Start of a new word
                in_word = 1;
            }
        } else {
            if (in_word) {
                // End of a word, allocate memory and copy the word
                int word_length = str - start;
                words[word_index] = malloc((word_length + 1) * sizeof(char));
                if (words[word_index] == NULL) {
                    // Free previously allocated memory on failure
                    for (int i = 0; i < word_index; i++) {
                        free(words[i]);
                    }
                    free(words);
                    return NULL;
                }
                strncpy(words[word_index], start, word_length);
                words[word_index][word_length] = '\0'; // Null-terminate the word
                word_index++;
                in_word = 0;
            }
        }
        str++;
    }

    // Handle the last word if the string doesn't end with a space
    if (in_word) {
        int word_length = str - start;
        words[word_index] = malloc((word_length + 1) * sizeof(char));
        if (words[word_index] == NULL) {
            // Free previously allocated memory on failure
            for (int i = 0; i < word_index; i++) {
                free(words[i]);
            }
            free(words);
            return NULL;
        }
        strncpy(words[word_index], start, word_length);
        words[word_index][word_length] = '\0'; // Null-terminate the word
        word_index++;
    }

    words[word_index] = NULL; // Null-terminate the array of words
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

    print_words(words); // Print the words
    free_words(words);  // Free the allocated memory

    return 0;
}
