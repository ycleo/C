#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define GUESSLIMIT 5

int main() {
    
    // declare variables
    int answer = 0;
    int guess = 0;
    int try = 0;

    // initialize a random number as the game answer
    srand((unsigned)time(NULL));
    answer = (rand() % 20) + 1;

    // Let user guess the number
    for (try = GUESSLIMIT; try > 0; try--) {
        printf("\nYou have %d tr%s left.\nGuess a number: ", try, try == 1 ? "y" : "ies");
        scanf("%d", &guess);

        if(guess == answer) {
            printf("\nGreat! You win the game.\n");
            return 0;
        } else if (guess < 1 || guess > 20) {
            printf("You are out of range (1~20).\n");
        } else if(guess < answer) {
            printf("Your guess is too small!\n");
        } else if(guess > answer) {
            printf("Your guess is too big!\n");
        }
    }

    // Print the final game result
    printf("\nSorry... You lose the game.\n");

    return 0;
}