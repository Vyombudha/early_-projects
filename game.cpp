#include <iostream>
#include <stdbool.h>
#include <limits>

const int BOARD_WIDTH = 3, BOARD_LENGTH = 9, MAX_INVALID_MOVE = 5;

using namespace std;

void printboard(char *board);
bool checkwinner(char *board);


int main()
{
    char board[BOARD_LENGTH] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // the board is initally set to blanks
    char move, current_player;
    int invalid_move = 0;
    for (int i = 0; i < BOARD_LENGTH; i++)
    {
        current_player = ((i % 2 == 0) ? 'X' : 'O'); //  the current_player will be X to O alternatively
        cout << endl
             << "Player " << current_player << " Enter your move (1-9): ";
        move = cin.get();                                    //  first take the input character
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //  and ignore anything until new line
        move = move - '0';                                   //  we will use char move and then subtract by '0' to get the integer value of move
        if (move < 1 || move > 9 || board[move - 1] != ' ')  // if the integer value of move is less than one or greater than 9 it is invlaid move
        {
            cout << "Invalid move Player " << current_player << " Try again! " << endl; // warning the player that it was invlaid
            invalid_move++;
            if (invalid_move == MAX_INVALID_MOVE)
            {
                cout << endl
                     << " Too Many Invalid Moves from Player " << current_player << " Ending The Game! " << endl;
                return 1;
            }
            i--;      // this is done becuase the current_player hasnt made their move so we let them try again
            continue; // skip to the next iteration but since i was decremented we are contunuing to the current iteration
        }
        board[move - 1] = current_player; // the way indexing works in programming is from 0 not 1 so we move - 1 to fill the index with the current_player's symbol
        printboard(board);
        if (i >= 4 && checkwinner(board)) // since there will be requrement  of at least 5 move x,o,x,o,x  for there to be any winner
        {
            cout << "Player " << current_player << " Wins! " << endl; // declare the current player as the  winner
            return 0;
        }
    }
    cout << endl << "Game Was a Draw! " << endl; // since no one won , the loop was exited i.e the game was a draw.
    return 0;
}

void printboard(char *board)
{
    for (int i = 0; i < BOARD_LENGTH; i++)
    {
        cout << board[i];
        if ((i + 1) % BOARD_WIDTH == 0)
        {
            cout << endl;
        }
        else
        {
            cout << " | ";
        }
    }
}

bool checkwinner(char *board)
{
    // 1. check Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i] != ' ' && board[i] == board[i + 3] && board[i] == board[i + 6]) // for e.g if the index is at 0 then the next element of 1st columns will be the 3rd element and the 6th element form the 1st one
        {
            return true; //  if the current_player win in columns
        }
    }

    // 2. Check Rows
    for (int i = 0; i < BOARD_LENGTH; i += 3)
    {
        if (board[i] != ' ' && board[i] == board[i + 1] && board[i] == board[i + 2])
        {
            return true; //  if the current_player win in rows
        }
    }

    // 3.  Check Diagonal From left To Right
    if (board[0] != ' ' && board[0] == board[4] && board[0] == board[8])
    {
        return true; //  if the current_player won in diagonal from left to right
    }

    // 4. Check Diagonal From Right To Left
    if (board[2] != ' ' && board[2] == board[4] && board[2] == board[6])
    {
        return true; // if the current_player won in diagonal form right to left
    }

    return false; //  must  return flase if no has won
}