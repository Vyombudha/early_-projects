#include <iostream>
#include <stdbool.h>

using namespace std;


// 9 *  3 * 3  = 81
//  TODO Write the Code for the PrintWholeBoard() ;
const int BOARD_SIZE = 9;

char Board[BOARD_SIZE][BOARD_SIZE];
char winnersBoard[BOARD_SIZE] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};


int GotoBoard(int CurrentPlayingBoard, char currentPlayer);
bool CheckWinner_smallBoard(int CurrentPlayingBoard);
bool CheckWinner_BigBoard();
void Printboard(int CurrentPlayingBoard);
void PrintWholeBoard();

int main()
{
    int initialBoard, CurrentPlayingBoard;
    char currentMove, currentPlayer;
    // initializing all the indexes to blank space ' ' for our condition
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            Board[i][j] = ' ';
        }
    }
    // 9 * 9  = 81 
    // taking initial board no from player X until the right Board no is entered
    do
    {
        cout << "Enter Initial Starting Board No Player X " << endl;
        cin >> initialBoard;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignoring all the possible inputs after the initial number is entered
        if (initialBoard < 1 || initialBoard > 9)
        {
            cout << "Wrong Board no Player X Try again!" << endl; //  tell the user that it was a wrong input
        }
    } while (initialBoard < 1 || initialBoard > 9); //  Check that if it was a wrong move and let X try again


    CurrentPlayingBoard = initialBoard; 
    for (int i = 1; i <= BOARD_SIZE * BOARD_SIZE; i++)
    {
      
        currentPlayer = ((i % 2) != 0) ? 'X' : 'O';
        CurrentPlayingBoard = GotoBoard(CurrentPlayingBoard, currentPlayer);
        if (CheckWinner_BigBoard())
        {
            cout << "Player " << currentPlayer << " has won! " << endl;
            return 0;
        }
    }

    cout << "Whole Game Draw!" << endl; // noone won in 81 moves of the whole board so it was a draw
    return 0;
}

int GotoBoard(int CurrentPlayingBoard, char currentPlayer)
{
    int move;
    do
    {
        cout << "Enter Your Move in " << CurrentPlayingBoard << " Player " << currentPlayer << endl;
        cin >> move;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (Board[CurrentPlayingBoard - 1][move - 1] != ' ' || move < 1 || move > 9)
        {
            cout << "Wrong move Player " << currentPlayer << " Try again!" << endl; //  tell the currentplayer that it was a wrong input
        }
    } while (Board[CurrentPlayingBoard - 1][move - 1] != ' ' || move < 1 || move > 9);

    PrintWholeBoard();  //  work in progress
    Board[CurrentPlayingBoard - 1][move - 1] = currentPlayer;    // indexes always start at 0 ,  
    Printboard(CurrentPlayingBoard - 1); // prints current playing board

    if (CheckWinner_smallBoard(CurrentPlayingBoard - 1))
    {
        cout << "Player " << currentPlayer << " has won Board no " << CurrentPlayingBoard << endl;
        winnersBoard[CurrentPlayingBoard - 1] = currentPlayer;
    }
    return move;
}

bool CheckWinner_smallBoard(int CurrentPlayingBoard, char currentPlayer)
{
    int i;
    //  Standard 3 x 3 win condtions

    // 1. check rows
    for (i = 0; i < 9; i += 3)
    {
        if (Board[CurrentPlayingBoard][i] != ' ' && Board[CurrentPlayingBoard][i] == Board[CurrentPlayingBoard][i + 1] && Board[CurrentPlayingBoard][i] == Board[CurrentPlayingBoard][i + 2])
        {
            return true;
        }
    }

    // 2. check columns
    for (i = 0; i < 3; i++)
    {
        if (Board[CurrentPlayingBoard][i] != ' ' && Board[CurrentPlayingBoard][i] == Board[CurrentPlayingBoard][i + 3] && Board[CurrentPlayingBoard][i] == Board[CurrentPlayingBoard][i + 6])
        {
            return true;
        }
    }

    // 3. check digaonal from left to right
    if (Board[CurrentPlayingBoard][0] != ' ' && Board[CurrentPlayingBoard][0] == Board[CurrentPlayingBoard][4] && Board[CurrentPlayingBoard][0] == Board[CurrentPlayingBoard][8])
    {
        return true;
    }

    // 4. check diagonal from right to left
    if (Board[CurrentPlayingBoard][2] != ' ' && Board[CurrentPlayingBoard][2] == Board[CurrentPlayingBoard][4] && Board[CurrentPlayingBoard][2] == Board[CurrentPlayingBoard][6])
    {
        return true;
    }

    // else noone won so we return false
    return false;
}

bool CheckWinner_BigBoard()
{
    int j;
    // 1. checks rows i
    for (j = 0; j < 9; j += 3)
    {
        if (winnersBoard[j] != ' ' && winnersBoard[j] == winnersBoard[j + 1] && winnersBoard[j + 1] == winnersBoard[j + 2])
        {
            return true;
        }
    }

    // 2. checks columns
    for (j = 0; j < 3; j++)
    {
        if (winnersBoard[j] != ' ' && (winnersBoard[j] == winnersBoard[j + 3]) && (winnersBoard[j + 3] == winnersBoard[j + 6]))
        {
            return true;
        }
    }

    // 3. Diagonal 1st
    if (winnersBoard[0] != ' ' && winnersBoard[0] == winnersBoard[4] && winnersBoard[4] == winnersBoard[8])
    {
        return true;
    }

    // 4.Diagonal 2nd
    if (winnersBoard[2] != ' ' && winnersBoard[2] == winnersBoard[4] && winnersBoard[4] == winnersBoard[6])
    {
        return true;
    }

    return false;
}

void Printboard(int CurrentPlayingBoard)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cout << Board[CurrentPlayingBoard][i];
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

void PrintWholeBoard()
{
    cout << "\n\n";
}
