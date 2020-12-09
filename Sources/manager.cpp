#include "manager.h"
#include <iostream>
#include <unistd.h>
#include <ctime>

using namespace std;

/*/// Check if sheep has filled up paddock.
///// This function checks the "paddock" area of the game board to see if the sheep have filled
///// it up. If they have, then "true" is returned. If they haven't, "false" is returned.
///// The "board.h" public board array is the array that will be checked.*/
bool paddockFilled(char gameBoard[7][7])
{
    ////// If the number of sheep in the "paddock" area is nine, then return true. Otherwise, return false.
    if (gameBoard[0][2] == 'S' && gameBoard[0][3] == 'S' && gameBoard[0][4] == 'S' && gameBoard[1][2] == 'S' && gameBoard[1][3] == 'S' && gameBoard[1][4] == 'S' && gameBoard[2][2] == 'S' && gameBoard[2][3] == 'S' && gameBoard[2][4] == 'S') {
        return true;
    } else
        return false;
}

/*/// Check if a fox is surrounded by sheep.
///// This function checks to see if a fox is surrounded by sheep on all sides. If one is,
///// then it is captured. Its space becomes a '.' in the public "board.h" board array. */
void foxSurrounded(char gameBoard[7][7])
{
    ///// Find out where foxes are.
    for (int x = 0; x < 7; x++)
        for (int y = 0; y < 7; y++) {
            if (gameBoard[x][y] == 'F') {
                if ((gameBoard[x + 1][y] == 'S') && (gameBoard[x - 1][y] == 'S') &&
                    (gameBoard[x + 1][y + 1] == 'S') && (gameBoard[x + 1][y - 1] == 'S') &&
                    (gameBoard[x][y + 1] == 'S') && (gameBoard[x][y - 1] == 'S') &&
                    (gameBoard[x - 1][y + 1] == 'S') && (gameBoard[x - 1][y - 1] == 'S')) {
                    gameBoard[x][y] = '.';
                }
            }
        }
}

/*/// Manage the game with all of the major functions.
///// This function is the primary function where all of the major functions of the game
///// are called to play the game and check if there is a winner. The public "board.h" array
///// is manipulated as the main char array for other functions.
///// A char variable is returned to represent whether the sheep or foxes have won.*/
void manageGame(istream& in)
{
    ////// The game will loop until there is a winner.
    /////// Create a char variable that will represent whether
    /////// the game has ended or will continue as the winner, where 'F' will represent
    /////// the foxes winning and 'S' will represent the sheep winning.
    char gameDone = '-';

    board theBoard;
    sheep theSheep;
    fox foxes;

    theBoard.initializeBoardSetup();
    theBoard.readBoard(in);
    theBoard.printBoard();

    bool speedHalatafl = false;
    char speedAnswer = '-';
    double duration = 0;
    cout << "\n\nBlitz (Speed - 20 second turns) Halatafl? (Y or N) ";
    cin >> speedAnswer;
    while (speedAnswer != 'Y' && speedAnswer != 'y' && speedAnswer != 'N' && speedAnswer != 'n') {
        cout << "Invalid Response. Blitz (Speed - 20 second turns) Halatafl? (Y or N) ";
        cin >> speedAnswer;
    }
    if (speedAnswer == 'Y' || speedAnswer == 'y')
        speedHalatafl = true;

    while (gameDone == '-') {
        //////// Check number of sheep.
        if (theSheep.numberOfSheep(theBoard.gameBoard) < 9) {
            gameDone = 'F';
            break;
        }
        if (!theSheep.userInput(theBoard.gameBoard, in, speedHalatafl, duration)) {
            gameDone = 'F';
            cout << "\nTime up! You took too long (" << duration << " seconds) to make a move!\n";
            break;
        }

        theBoard.printBoard();
        //////// Check "paddock" area for sheep.
        if (paddockFilled(theBoard.gameBoard) == true) {
            gameDone = 'S';
            break;
        }

        foxSurrounded(theBoard.gameBoard);
        foxes.newFoxPosition(theBoard.gameBoard);
        theBoard.printBoard();
        // Test Driver
        //break;
    }
    if (gameDone == 'S')
        cout << "\nThe sheep win!" << endl
             << endl;
    else if (gameDone == 'F')
        cout << "\nThe foxes win!" << endl
             << endl;
}

/*/// Manage the game with all of the major functions.
///// This function is the primary function where all of the major functions of the game
///// are called to play the game and check if there is a winner. The public "board.h" array
///// is manipulated as the main char array for other functions.
///// A char variable is returned to represent whether the sheep or foxes have won.
///// This particular function acts as a unit testing driver and will return a struct
///// containing the game statistics after a single play (no more than two moves including both sheep and foxes).*/
gameStats manageTestGame(istream& in)
{
    ////// The game will loop until there is a winner.
    /////// Create a char variable that will represent whether
    /////// the game has ended or will continue as the winner, where 'F' will represent
    /////// the foxes winning and 'S' will represent the sheep winning.
    char gameDone = '-';

    board theBoard;
    sheep theSheep;
    fox foxes;

    theBoard.initializeBoardSetup();
    //cout << "initialized\n";
    theBoard.readBoard(in);
    //cout << "board read\n";
    theBoard.printBoard();
    //cout << "board printed\n";
    while (gameDone == '-') {
        //////// Check number of sheep.
        if (theSheep.numberOfSheep(theBoard.gameBoard) < 9) {
            gameDone = 'F';
            break;
        }
        //theSheep.userInput(theBoard.gameBoard, in);
        //theBoard.printBoard();
        //////// Check "paddock" area for sheep.
        if (paddockFilled(theBoard.gameBoard) == true) {
            gameDone = 'S';
            break;
        }

        foxSurrounded(theBoard.gameBoard);
        foxes.newFoxPosition(theBoard.gameBoard);
        theBoard.printBoard();

        //////// Check number of sheep.
        if (theSheep.numberOfSheep(theBoard.gameBoard) < 9) {
            gameDone = 'F';
            break;
        }
        //theSheep.userInput(theBoard.gameBoard, in);
        //theBoard.printBoard();
        //////// Check "paddock" area for sheep.
        if (paddockFilled(theBoard.gameBoard) == true) {
            gameDone = 'S';
            break;
        }

        // Test Driver
        break;
    }

    gameStats stats;
    stats.gameOver = false;
    stats.numFoxes = foxes.numberOfFoxes(theBoard.gameBoard);
    stats.numSheep = theSheep.numberOfSheep(theBoard.gameBoard);
    stats.winner = '-';

    if (gameDone == 'S') {
        cout << "\nThe sheep win!" << endl
             << endl;
        stats.gameOver = true;
        stats.winner = 'S';
    } else if (gameDone == 'F') {
        cout << "\nThe foxes win!" << endl
             << endl;
        stats.gameOver = true;
        stats.winner = 'F';
    }
    return stats;
}

/*/// This function reads the user's input, tests whether or not the new position they entered
//// is legal, and if it is, the new position in the "board.h" public board array gets changed to 'S'
//// and this function returns true. If the new position the user entered was illegal, then it will return false.*/
bool validUserInput(char gameBoard[7][7], std::istream& in, bool speedHalatafl, unsigned sleepTime)
{
    ///// Create 5 variables to read the input of the user, initial position - moving position.
    char oldPos = 'x', dash = '-', newPos = 'y';
    int oldPosition = 0, newPosition = 0;

    ///// Create an array to match the letters that represent the game gameBoard columns with
    ///// the two-dimensional gameBoard array.
    char letterArray[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    ///// Create an array to match the numbers that represent the game gameBoard rows with
    ///// the two-dimensional gameBoard array.
    int numberArray[7] = {7, 6, 5, 4, 3, 2, 1};

    // Timer variables for Blitz (speed) Halatafl
    clock_t start;
    double duration = 0;

    ///// Prompt user for input and read data into variables.
    board theBoard(gameBoard);
    theBoard.printBoard();
    cout << "\nYour move? ";
    if (speedHalatafl){
        start = clock();
        sleep(sleepTime);
    }
    in >> oldPos >> oldPosition >> dash >> newPos >> newPosition;
    if (speedHalatafl) {
        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        //cout << duration << endl;
        if (duration > 20) {
            cout << oldPos << oldPosition << dash << newPos << newPosition;
            cout << "\nTime up! You took too long (" << duration << " seconds) to make a move!\n";
            cout << "\nThe foxes win!" << endl << endl;
            return false;
        }
    }
    cout << oldPos << oldPosition << dash << newPos << newPosition;
    ///// Match oldPos, newPos, oldPosition, and newPosition with the letter and number arrays,
    ///// and store those values in new variables
    int columnOld = 0, rowOld = 0, columnNew = 0, rowNew = 0;
    for (int x = 0; x < 7; x++) {
        if (oldPos == letterArray[x])
            columnOld = x;
        if (oldPosition == numberArray[x])
            rowOld = x;
        if (newPos == letterArray[x])
            columnNew = x;
        if (newPosition == numberArray[x])
            rowNew = x;
    }
    ///// Check the new gameBoard array position to see if it's a legal move
    if (gameBoard[rowOld][columnOld] != 'S') {
        cout << "\nThat is not a legal move.\n";
        return false;
    }
    if ((columnNew < 0 || columnNew > 6) || (rowNew < 0 || rowNew > 6)) {
        cout << "\nThat is not a legal move.\n";
        return false;
    }

    if ((gameBoard[rowNew][columnNew] != '.') ||
        (((rowNew == rowOld + 1) && (columnNew == columnOld)) || ((rowNew == rowOld + 1) && (columnNew == columnOld + 1)) || ((rowNew == rowOld + 1) && (columnNew == columnOld - 1)) || ((rowNew == rowOld - 1) && (columnNew == columnOld - 1)) || ((rowNew == rowOld - 1) && (columnNew == columnOld + 1))) || ((rowNew > rowOld + 1) || (rowNew < rowOld - 1) || (columnNew > columnOld + 1) || (columnNew < columnOld - 1))) {

        cout << "\nThat is not a legal move.\n";
        return false;
    }


    ////// Set the new gameBoard position to 'S' and change the old position to '.'
    gameBoard[rowNew][columnNew] = 'S';
    gameBoard[rowOld][columnOld] = '.';

    board newBoard(gameBoard);
    newBoard.printBoard();

    return true;
}
