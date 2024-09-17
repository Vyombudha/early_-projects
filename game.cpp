#include <iostream>
#include <stdlib.h>

using namespace std;

void declarewinner(char board[], int j)
{
    cout << "Player " << board[j] << " wins!" << endl;
    exit(EXIT_SUCCESS);
}

void printBoard(char board[])
{
    for (int i = 0; i < 9; i++)
    {
        cout << board[i];
        if ((i + 1) % 3 == 0)
        {
            cout << endl;
        }
        else
        {
            cout << " | ";
        }
    }
}

void checkwinner(char board[])
{
    int i, j;
    // 1. checks rows
    for (j = 0; j < 9; j += 3)
    {
        if (board[j] != ' ' && board[j] == board[j + 1] && board[j + 1] == board[j + 2])
        {
            declarewinner(board, j);
        }
    }

    // 2. checks columns
    for (j = 0; j < 3; j++)
    {
        if (board[j] != ' ' && (board[j] == board[j + 3]) && (board[j + 3] == board[j + 6]))
        {
            declarewinner(board, j);
        }
    }

    // 3. Diagonal 1st
    if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8])
    {
        declarewinner(board, 0);
    }

    // 4.Diagonal 2nd
    if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6])
    {
        declarewinner(board, 2);
    }

    // Draw condition
    if (i == 8)
    {
        cout << "Game Draw! " << endl;
        exit(EXIT_SUCCESS);
    }
}

int main()
{
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, move;

    for (int i = 0; i < 9; i++)
    {
        cout << "Player " << ((i % 2 == 0) ? 'X' : 'O') << ", enter your move (1-9): ";
        move = getchar();
        fflush(stdin);
        move = move - '0'; // subracting by '0' to convert the entered character integer to it's integer value;
        if (move < 1 || move > 9 || board[move - 1] != ' ')
        {
            cout << "Invalid Move Try again" << endl;
            i--;
            continue;
        }
        board[move - 1] = (i % 2 == 0) ? 'X' : 'O';
        printBoard(board);
        checkwinner(board);
    }

    return 0;
}