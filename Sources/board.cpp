#include "board.h"

using namespace std;

board::board(){}

board::board(char theBoard[7][7])
{
    for(int x = 0; x < 7; x++)
        for(int y = 0; y < 7; y++)
            gameBoard[x][y] = theBoard[x][y];
}

/*/// This function will be used to initialize the game board that will be manipulated
/// throughout the program of which the user will be playing on. It will take in a two-dimensional
/// array of char as a parameter which will be filled with '-' characters.*/
void board::initializeBoardSetup()
{
    for(int x = 0; x < 7; x++)
    {
        for(int y = 0; y < 7; y++)
            board::gameBoard[x][y] = '-';
    }
}


/*/// This function simply displays the game board and all of the current positions.
    //// The gameBoard array is output, including the
    //// /|\ symbols and side/bottom labels.*/
void board::printBoard()
{
    cout << endl;
    cout << "7     " << gameBoard[0][2] << "-" << gameBoard[0][3] << "-" << gameBoard[0][4] << endl;
    cout << "      |\\|/|" << endl;
    cout << "6     " << gameBoard[1][2] << "-" << gameBoard[1][3] << "-" << gameBoard[1][4] << endl;
    cout << "      |/|\\|" << endl;
    cout << "5 " << gameBoard[2][0] << "-" << gameBoard[2][1] << "-" << gameBoard[2][2] << "-" << gameBoard[2][3] << "-" << gameBoard[2][4] << "-" << gameBoard[2][5] << "-" << gameBoard[2][6] << endl;
    cout << "  |\\|/|\\|/|\\|/|" << endl;
    cout << "4 " << gameBoard[3][0] << "-" << gameBoard[3][1] << "-" << gameBoard[3][2] << "-" << gameBoard[3][3] << "-" << gameBoard[3][4] << "-" << gameBoard[3][5] << "-" << gameBoard[3][6] << endl;
    cout << "  |/|\\|/|\\|/|\\|" << endl;
    cout << "3 " << gameBoard[4][0] << "-" << gameBoard[4][1] << "-" << gameBoard[4][2] << "-" << gameBoard[4][3] << "-" << gameBoard[4][4] << "-" << gameBoard[4][5] << "-" << gameBoard[4][6] << endl;
    cout << "      |\\|/|" << endl;
    cout << "2     " << gameBoard[5][2] << "-" << gameBoard[5][3] << "-" << gameBoard[5][4] << endl;
    cout << "      |/|\\|" << endl;
    cout << "1     " << gameBoard[6][2] << "-" << gameBoard[6][3] << "-" << gameBoard[6][4] << endl;
    cout << "  a b c d e f g";
}

// This function is the driver(tester) of the program that will allow the user
    // to enter the initial board positions and read them from standard input or from a file.
void board::readBoard(istream& in)
{
    // ROWS ONE AND TWO
    for (int num = 0; num < 2; num++)
    {
        for (int x = 2; x < 5; x++)
        {
            while ((in.peek() == '-') || (in.peek() == '/') || (in.peek() == '\\') || (in.peek() == '|'))
            {
                in.ignore();
            }
            in >> gameBoard[num][x];
        }
    }

    // ROWS THREE, FOUR, AND FIVE
    for (int num = 2; num < 5; num++)
    {
        for (int x = 0; x < 7; x++)
        {
            while ((in.peek() == '-') || (in.peek() == '/') || (in.peek() == '\\') || (in.peek() == '|'))
            {
                in.ignore();
            }
            in >> gameBoard[num][x];
        }
    }

    // ROWS FIVE AND SIX
    for (int num = 5; num < 7; num++)
    {
        for (int x = 2; x < 5; x++)
        {
            while ((in.peek() == '-') || (in.peek() == '/') || (in.peek() == '\\') || (in.peek() == '|'))
            {
                in.ignore();
            }
            in >> gameBoard[num][x];
        }
    }
}
