#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>

class board
{

    public:

    board();
    board(char board[7][7]);

    char gameBoard[7][7];

    /*/// This function will be used to initialize the game board that will be manipulated
    /// throughout the program of which the user will be playing on. It will take in a two-dimensional
    /// array of char as a parameter which will be filled with '-' characters.*/
    void initializeBoardSetup();


    /*/// This function simply displays the game board and all of the current positions.
    //// The gameBoard array is output, including the
    //// /|\ symbols and side/bottom labels.*/
    void printBoard();


    // This function is the driver(tester) of the program that will allow the user
    // to enter the initial board positions and read them from standard input or from a file.
    void readBoard(std::istream& in);


};


#endif // BOARD_H_INCLUDED
