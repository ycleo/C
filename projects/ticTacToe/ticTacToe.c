#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void drawBoard(char board[]);
void markBoard(char board[], int currentPlayer, int markPosition);
bool checkForWin(char board[], int currentPlayer);

int main () {
    int move = 0;
    int currentPlayer = 1;
    int markPosition = 0;
    char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    while (move < 9) {
        // draw the game board
        drawBoard(board);

        // prompt for player to enter the mark position
        printf("Player %d, enter a number: ", currentPlayer);
        scanf("%d", &markPosition);

        // mark the board
        markBoard(board, currentPlayer, markPosition);

        // check whether player win the game or not
        if (checkForWin(board, currentPlayer)) {
            drawBoard(board);
            break;
        }

        // switch the player
        currentPlayer = currentPlayer == 1 ? 2 : 1;
        move++;
    }

    if (move < 9) 
        printf("The winner is Player %d!\n", currentPlayer);
    else
        printf("Tie game!\n");

    return 0;
}

void drawBoard(char board[]) {
    system("clear");
    printf("         Tic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    for (int i = 0; i < 9; i+=3) {
        printf("   |   |   \n");
        printf(" %c | %c | %c \n", board[i], board[i+1], board[i+2]);
        printf("   |   |   \n");
        if(i < 5) 
            printf("-----------");
        printf("\n");
    }
}

void markBoard(char board[], int currentPlayer, int markPosition) {
    char mark = currentPlayer == 1 ? 'X' : 'O';
    char opponentMark = currentPlayer == 1 ? 'O' : 'X';

    // check the move validity
    while (markPosition < 1 || markPosition > 9 || board[markPosition - 1] == opponentMark || board[markPosition - 1] == mark) {
        printf("Invalid move, enter again: ");
        scanf("%d", &markPosition);
    }

    // start marking the board
    board[markPosition - 1] = mark;
    return;
}

bool checkForWin(char board[], int currentPlayer) {
    char mark = currentPlayer == 1 ? 'X' : 'O';

    int i;
    // check the vertical line
    for (i = 0; i < 3; i++) {
        if (board[i] == mark && board[i + 3] == mark && board[i + 6] == mark) 
            return true;
    }

    // check the horizontal line
    for (i = 0; i < 6; i += 3) {
        if(board[i] == mark && board[i + 1] == mark && board[i + 2] == mark) 
            return true;
    }
    
    // check the slash
    if (board[4] == mark) {
        if ((board[0] == mark && board[8] == mark) || (board[2] == mark && board[6] == mark))
            return true; 
    }

    return false;
}