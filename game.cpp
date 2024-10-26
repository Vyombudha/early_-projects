#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define BOARD_WIDTH 3
#define BOARD_LENGTH 9


void printBoard(char *board);
bool checkWinner(char *board);

int main()
{
    char board[BOARD_LENGTH] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // the board is initially set to blanks
    char current_player;
    int move;

    for (int i = 0; i < BOARD_LENGTH; i++)
    {
        current_player = ((i % 2 == 0) ? 'X' : 'O');                    // the current player will be X to O alternatively
        printf("\nPlayer %c, Enter your move (1-9): ", current_player); 
        scanf("%d", &move);  
        fflush(stdin);     

        if (move < 1 || move > 9 || board[move - 1] != ' ')
        {                                                                   // Validate the move
            printf("Invalid move Player %c! Try again!\n", current_player); 
            i--;      // Decrement i to retry the current player's turn
            continue; // Skip to the next iteration
        }

        board[move - 1] = current_player; // Place the player's move
        printBoard(board);                // Print the current board

        if (i >= 4 && checkWinner(board))   // Check for a winner only if 5 or more moves have been made 
        {                                              
            printf("Player %c Wins!\n", current_player); 
            return 0;
        }
    }

    printf("\nGame Was a Draw!\n"); 
    return 0;
}

void printBoard(char *board)
{
    for (int i = 0; i < BOARD_LENGTH; i++)
    {
        printf("%c", board[i]);
        if ((i + 1) % BOARD_WIDTH == 0)
        {
            printf("\n");
        }
        else
        {
            printf(" | ");
        }
    }
}

bool checkWinner(char *board)
{
    // Check Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i] != ' ' && board[i] == board[i + 3] && board[i] == board[i + 6])
        {
            return true; // Win in columns
        }
    }

    // Check Rows
    for (int i = 0; i < BOARD_LENGTH; i += 3)
    {
        if (board[i] != ' ' && board[i] == board[i + 1] && board[i] == board[i + 2])
        {
            return true; // Win in rows
        }
    }

    // Check Diagonal From Left To Right
    if (board[0] != ' ' && board[0] == board[4] && board[0] == board[8])
    {
        return true; // Win diagonal left to right
    }

    // Check Diagonal From Right To Left
    if (board[2] != ' ' && board[2] == board[4] && board[2] == board[6])
    {
        return true; // Win diagonal right to left
    }

    return false; // No winner
}

