#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include <iostream>
#include "board.h"
#include "fox.h"
#include "sheep.h"

struct gameStats
{
    bool gameOver;
    char winner;
    int numSheep;
    int numFoxes;
};

/*/// Check if sheep has filled up paddock.
///// This function checks the "paddock" area of the game board to see if the sheep have filled
///// it up. If they have, then "true" is returned. If they haven't, "false" is returned.
///// The "board.h" public board array is the array that will be checked.*/
    bool paddockFilled(char gameBoard[7][7]);


    /*/// Check if a fox is surrounded by sheep.
///// This function checks to see if a fox is surrounded by sheep on all sides. If one is,
///// then it is captured. Its space becomes a '.' in the public "board.h" board array. */
    void foxSurrounded(char gameBoard[7][7]);


    /*/// Manage the game with all of the major functions.
///// This function is the primary function where all of the major functions of the game
///// are called to play the game and check if there is a winner. The public "board.h" array
///// is manipulated as the main char array for other functions.*/
    void manageGame(std::istream& in);

    /*/// Manage the game with all of the major functions.
///// This function is the primary function where all of the major functions of the game
///// are called to play the game and check if there is a winner. The public "board.h" array
///// is manipulated as the main char array for other functions.*/
    gameStats manageTestGame(std::istream& in);

    /*/// This function reads the user's input, tests whether or not the new position they entered
//// is legal, and if it is, the new position in the "board.h" public board array gets changed to 'S'
//// and this function returns true. If the new position the user entered was illegal, then it will return false.*/
    bool validUserInput(char gameBoard[7][7], std::istream& in);


#endif // MANAGER_H_INCLUDED
