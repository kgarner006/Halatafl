#ifndef FOX_H_INCLUDED
#define FOX_H_INCLUDED

#include <iostream>
#include "board.h"
#include "sheep.h"
#include <vector>

class fox
{
    public:

    fox();

    // Function used to calculate and return number of foxes on game board
    int numberOfFoxes(char board[7][7]);


    /*/// This function determines which fox will make a move and the actual move set that it will make,
    //// whether it's a single jump, multiple jumps, or random jumps. The "board.h" public board array is used
    //// to gather where the fox positions and sheep positions are and calculates the move the fox will make.
    //// The integer numberofSheep parameter is passed in from the sheep ADT to determine how many sheep there are overall
    //// on the game board.
    //// The fox move is output.*/
    void newFoxPosition(char gameBoard[7][7]);

    private:
    struct aFox
    {
        int numCaptured;
        int numThreatened;
        int rowCo;
        int colCo;
        int finalRow;
        int finalColumn;
        char tempBoard[7][7];
    };

    struct aMove
    {
        int row;
        int column;
    };

    // This struct includes a vector of aMove
    // structs for the co-ordinates along with a number
    // to keep count of those aMove structs that it's creating.
    struct theMoves
    {
        std::vector<aMove> moves;
        int numCap;
        char theBoard[7][7];
    };

    struct threats
    {
        aMove moveSet;
        int numThreatened;
    };

};


#endif // FOX_H_INCLUDED
