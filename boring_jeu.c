#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20
#define MAX_ATTEMPTS 6

char words[MAX_WORDS][MAX_WORD_LENGTH] = {
    "elephant",
    "computer",
    "programming",
    "language",
    "keyboard",
    "internet",
    "hangman",
    "guitar",
    "painting",
    "library"
};

void displayHangman(int attempts) {
    // Your hangman ASCII art here
}

void displayWord(char word[], char guessed[]) {
    // Your code to display the word with guessed letters
}

int main() {
    srand(time(NULL));

    char word[MAX_WORD_LENGTH];
    strcpy(word, words[rand() % MAX_WORDS]);

    int wordLength = strlen(word);
    char guessed[MAX_WORD_LENGTH];
    memset(guessed, 0, sizeof(guessed));

    int attempts = 0;
    int correctGuesses = 0;
    int maxAttempts = MAX_ATTEMPTS;

    printf("Welcome to Hangman!\n");

    while (attempts < maxAttempts && correctGuesses < wordLength) {
        printf("\n");
        displayHangman(attempts);
        printf("\n");
        displayWord(word, guessed);

        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess && !guessed[i]) {
                guessed[i] = 1;
                correctGuesses++;
                found = 1;
            }
        }

        if (!found) {
            printf("Incorrect guess.\n");
            attempts++;
        }
    }

    printf("\n");
    if (correctGuesses == wordLength) {
        printf("Congratulations! You guessed the word: %s\n", word);
    } else {
        printf("You lost! The word was: %s\n", word);
        displayHangman(attempts);
    }

    return 0;
}
