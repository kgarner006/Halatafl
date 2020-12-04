#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <assert.h>
#include "manager.h"

using namespace std;

// This function will call the manageTestGame function with an input stream.
int main(int argc, char** argv)
{
    //// Call the manageTestGame function to retrieve the game status after giving board input.
    char theBoard[7][7];
    theBoard[0][0] = '-';
    theBoard[0][1] = '-';
    theBoard[0][2] = 'F';
    theBoard[0][3] = '.';
    theBoard[0][4] = 'F';
    theBoard[0][5] = '-';
    theBoard[0][6] = '-';
    theBoard[1][0] = '-';
    theBoard[1][1] = '-';
    theBoard[1][2] = '.';
    theBoard[1][3] = '.';
    theBoard[1][4] = '.';
    theBoard[1][5] = '-';
    theBoard[1][6] = '-';
    theBoard[2][0] = '.';
    theBoard[2][1] = '.';
    theBoard[2][2] = '.';
    theBoard[2][3] = '.';
    theBoard[2][4] = '.';
    theBoard[2][5] = '.';
    theBoard[2][6] = '.';
    theBoard[3][0] = '.';
    theBoard[3][1] = '.';
    theBoard[3][2] = '.';
    theBoard[3][3] = 'S';
    theBoard[3][4] = 'S';
    theBoard[3][5] = '.';
    theBoard[3][6] = '.';
    theBoard[4][0] = 'S';
    theBoard[4][1] = 'S';
    theBoard[4][2] = 'S';
    theBoard[4][3] = '.';
    theBoard[4][4] = 'S';
    theBoard[4][5] = 'S';
    theBoard[4][6] = 'S';
    theBoard[5][0] = '-';
    theBoard[5][1] = '-';
    theBoard[5][2] = 'S';
    theBoard[5][3] = 'S';
    theBoard[5][4] = 'S';
    theBoard[5][5] = '-';
    theBoard[5][6] = '-';
    theBoard[6][0] = '-';
    theBoard[6][1] = '-';
    theBoard[6][2] = 'S';
    theBoard[6][3] = 'S';
    theBoard[6][4] = 'S';
    theBoard[6][5] = '-';
    theBoard[6][6] = '-';

    /*board gameBoard (theBoard);
    gameBoard.printBoard();*/

	string input = "d4-c4";

	istringstream str(input);

    if (validUserInput(theBoard, str))
    {
        return 0;
    }
    else
        return 1;
}
