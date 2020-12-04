#include "fox.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

fox::fox(){}

// Function used to calculate and return number of foxes on game board
int fox::numberOfFoxes(char board[7][7])
{
    int numFoxes = 0;
    for(int x = 0; x < 7; x++)
        for(int y = 0; y < 7; y++)
        {
            if(board[x][y] == 'F')
                numFoxes++;
        }
    return numFoxes;
}

/*/// This function determines which fox will make a move and the actual move set that it will make,
    //// whether it's a single jump, multiple jumps, or random jumps. The "board.h" public board array is used
    //// to gather where the fox positions and sheep positions are and calculates the move the fox will make.
    //// The fox move is output.*/
void fox::newFoxPosition(char gameBoard[7][7])
{

    bool foxFound = false, areWeThereYet = false, notNearASheep = false;
    bool fromTop = false, fromTopRight = false, fromRight = false, fromBottomRight = false, fromBottom = false, fromBottomLeft = false, fromLeft = false, fromTopLeft = false;
    int row = 0, column = 0, count1 = -1, count2 = -1, count3 = -1, count4 = -1, count5 = -1, count6 = -1, count7 = -1, count8 = -1;
    int randoms = 0, officialRow = 0, officialColumn = 0, howManyFoxes = 0;

    aMove dummy;
    aMove firstIt, secondIt, thirdIt, fourthIt, fifthIt, sixthIt, seventhIt, eigthIt;
    dummy.row = 0;
    dummy.column = 0;
    firstIt.row = 0;
    firstIt.column = 0;
    secondIt.row = 0;
    secondIt.column = 0;
    thirdIt.row = 0;
    thirdIt.column = 0;
    fourthIt.row = 0;
    fourthIt.column = 0;
    fifthIt.row = 0;
    fifthIt.column = 0;
    sixthIt.row = 0;
    sixthIt.column = 0;
    seventhIt.row = 0;
    seventhIt.column = 0;
    eigthIt.row = 0;
    eigthIt.column = 0;

    char temp1[7][7];
    char temp2[7][7];
    char temp3[7][7];
    char temp4[7][7];
    char temp5[7][7];
    char temp6[7][7];
    char temp7[7][7];
    char temp8[7][7];
    char resetBoard[7][7];



    ///// Create an array to match the letters that represent the game board columns with
	///// the two-dimensional board array.
	char letterArray[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	///// Create an array to match the numbers that represent the game board rows with
	///// the two-dimensional board array.
	int numberArray[7] = {7, 6, 5, 4, 3, 2, 1};

	///// Create and initialize variables to represent fox initial position and new position.
    char oldPos = 'x';
    char newPos = 'y';
    int oldPosition = 0;
    int newPosition = 0;

	///// Loop through the game board to discover where foxes are.
	for (int x = 0; x < 7 && foxFound == false; x++)
		for (int y = 0; y < 7 && foxFound == false; y++)
		{
			if (gameBoard[x][y] == 'F')
			{
                row = x;
                column = y;
                foxFound = true;
			}
		}
    aFox fox1;
    fox1.rowCo = row;
    fox1.colCo = column;
    fox1.numCaptured = 0;
    fox1.numThreatened = 0;
    fox1.finalRow = 0;
    fox1.finalColumn = 0;


    foxFound = false;
    for (int x = 6; x > -1 && foxFound == false; x--)
		for (int y = 6; y > -1 && foxFound == false; y--)
		{
			if (gameBoard[x][y] == 'F')
			{
                row = x;
                column = y;
                foxFound = true;
			}
		}
    aFox fox2;
    fox2.rowCo = row;
    fox2.colCo = column;
    fox2.numCaptured = 0;
    fox2.numThreatened = 0;
    fox2.finalRow = 0;
    fox2.finalColumn = 0;


    if ((fox1.rowCo == fox2.rowCo) && (fox1.colCo == fox2.colCo))
        howManyFoxes = 1;
    else
        howManyFoxes = 2;


    theMoves eightMoves[8];


    for (int a = 0; a < 8; a++)
    {
        eightMoves[a].numCap = 0;
        eightMoves[a].moves.push_back(dummy);
        eightMoves[a].moves[0].row = 0;
        eightMoves[a].moves[0].column = 0;
    }

        aFox foxObjects[2];
        foxObjects[0] = fox1;
        foxObjects[1] = fox2;

        for (int rowNum = 0; rowNum < 7; rowNum++)
            for (int colNum = 0; colNum < 7; colNum++)
            {
                foxObjects[0].tempBoard[rowNum][colNum] = gameBoard[rowNum][colNum];
                foxObjects[1].tempBoard[rowNum][colNum] = gameBoard[rowNum][colNum];
            }



            for (int foxNum = 0; foxNum < howManyFoxes; foxNum++)
            {
                for (int a = 0; a < 7; a++)
                    for (int b = 0; b < 7; b++)
                    {
                        temp1[a][b] = gameBoard[a][b];
                        temp2[a][b] = gameBoard[a][b];
                        temp3[a][b] = gameBoard[a][b];
                        temp4[a][b] = gameBoard[a][b];
                        temp5[a][b] = gameBoard[a][b];
                        temp6[a][b] = gameBoard[a][b];
                        temp7[a][b] = gameBoard[a][b];
                        temp8[a][b] = gameBoard[a][b];
                        resetBoard[a][b] = gameBoard[a][b];
                    }

                    eightMoves[0].numCap = 0;
                    eightMoves[1].numCap = 0;
                    eightMoves[2].numCap = 0;
                    eightMoves[3].numCap = 0;
                    eightMoves[4].numCap = 0;
                    eightMoves[5].numCap = 0;
                    eightMoves[6].numCap = 0;
                    eightMoves[7].numCap = 0;

                    for (int a = 0; a < 7; a++)
                        for (int b = 0; b < 7; b++)
                        {
                            eightMoves[0].theBoard[a][b] = gameBoard[a][b];
                            eightMoves[1].theBoard[a][b] = gameBoard[a][b];
                            eightMoves[2].theBoard[a][b] = gameBoard[a][b];
                            eightMoves[3].theBoard[a][b] = gameBoard[a][b];
                            eightMoves[4].theBoard[a][b] = gameBoard[a][b];
                            eightMoves[5].theBoard[a][b] = gameBoard[a][b];
                            eightMoves[6].theBoard[a][b] = gameBoard[a][b];
                            eightMoves[7].theBoard[a][b] = gameBoard[a][b];
                        }
                notNearASheep = false;
				////// If it is possible to capture a sheep,
				////// a capturing move is made.
				/////// Look at spaces all around fox and see
				/////// if there is a sheep with an empty
				/////// space beyond it for capture. If there is, capture it.
                if ((foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) || (foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4)
                || (foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 2) || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 4) || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 3)
                || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 2) || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6) || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5)
                || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 4) || (foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3) || (foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2)
                || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6) || (foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                {
                    areWeThereYet = false;
                    // CHECK UP
                    if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 6))
                        {

                            if ((temp1[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] == 'S') && (temp1[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo] == '.'))
                            {
                                bool up, upRight, right, bottomRight, bottom, bottomLeft, left, upLeft;
                                eightMoves[0].numCap++;
                                eightMoves[0].moves[0].row = foxObjects[foxNum].rowCo - 2;
                                eightMoves[0].moves[0].column = foxObjects[foxNum].colCo;
                                temp1[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';
                                temp1[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                                for (int c = 0; c < 7; c++)
                                    for (int d = 0; d < 7; d++)
                                        eightMoves[0].theBoard[c][d] = temp1[c][d];
                                //resetBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';
                                //////// Look at spaces beyond that and see if multiple jumps are possible.
                                //////// If there are, make the move set of multiple jumps.
                                for (int num = 1; num < 8 && areWeThereYet == false; num++)
                                {
                                    randoms = 0;
                                    count1 = 0;
                                    count2 = 0;
                                    count3 = 0;
                                    count4 = 0;
                                    count5 = 0;
                                    count6 = 0;
                                    count7 = 0;
                                    count8 = 0;
                                    up = false;
                                    upRight = false;
                                    right = false;
                                    bottomRight = false;
                                    bottom = false;
                                    bottomLeft = false;
                                    left = false;
                                    upLeft = false;
                                    if ((eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) || (eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) || (eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4)
                                    || (eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) || (eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 2) || (eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                    || (eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) || (eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 4) || (eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 3)
                                    || (eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 2) || (eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6) || (eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5)
                                    || (eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 4) || (eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3) || (eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2)
                                    || (eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6) || (eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                    {
                                        // CHECK UP
                                        /*for (int z = 0; z < 7; z++)
                                            for (int c = 0; c < 7; c++)
                                            {
                                                temp1[z][c] = resetBoard[z][c];
                                            }*/
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                            && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2)
                                            && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                            && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                            && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6)
                                            && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                            && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 6))
                                            {
                                                if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[0].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[0].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                    //temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] = '.';
                                                    /*fromTop = true;
                                                    fromTopRight = false;
                                                    fromRight = false;
                                                    fromBottomRight = false;
                                                    fromBottom = false;
                                                    fromBottomLeft = false;
                                                    fromLeft = false;
                                                    fromTopLeft = false;
                                                    count1++;*/
                                                }
                                            }
                                        /*else if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column] == '.')) && fromTopRight == true)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] = '.';
                                            fromTop = true;
                                            fromTopRight = false;
                                            fromRight = false;
                                            fromBottomRight = false;
                                            fromBottom = false;
                                            fromBottomLeft = false;
                                            fromLeft = false;
                                            fromTopLeft = false;
                                            count1++;
                                        }
                                        else if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column] == '.')) && fromRight == true)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] = '.';
                                            fromTop = true;
                                            fromTopRight = false;
                                            fromRight = false;
                                            fromBottomRight = false;
                                            fromBottom = false;
                                            fromBottomLeft = false;
                                            fromLeft = false;
                                            fromTopLeft = false;
                                            count1++;
                                        }
                                        else if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column] == '.')) && fromBottomRight == true)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] = '.';
                                            fromTop = true;
                                            fromTopRight = false;
                                            fromRight = false;
                                            fromBottomRight = false;
                                            fromBottom = false;
                                            fromBottomLeft = false;
                                            fromLeft = false;
                                            fromTopLeft = false;
                                            count1++;
                                        }
                                        else if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column] == '.')) && fromBottom == true)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] = '.';
                                            fromTop = true;
                                            fromTopRight = false;
                                            fromRight = false;
                                            fromBottomRight = false;
                                            fromBottom = false;
                                            fromBottomLeft = false;
                                            fromLeft = false;
                                            fromTopLeft = false;
                                            count1++;
                                        }
                                        else if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column] == '.')) && fromBottomLeft == true)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] = '.';
                                            fromTop = true;
                                            fromTopRight = false;
                                            fromRight = false;
                                            fromBottomRight = false;
                                            fromBottom = false;
                                            fromBottomLeft = false;
                                            fromLeft = false;
                                            fromTopLeft = false;
                                            count1++;
                                        }
                                        else if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column] == '.')) && fromLeft == true)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] = '.';
                                            fromTop = true;
                                            fromTopRight = false;
                                            fromRight = false;
                                            fromBottomRight = false;
                                            fromBottom = false;
                                            fromBottomLeft = false;
                                            fromLeft = false;
                                            fromTopLeft = false;
                                            count1++;
                                        }
                                        else if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column] == '.')) && fromTopLeft == true)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] = '.';
                                            fromTop = true;
                                            fromTopRight = false;
                                            fromRight = false;
                                            fromBottomRight = false;
                                            fromBottom = false;
                                            fromBottomLeft = false;
                                            fromLeft = false;
                                            fromTopLeft = false;
                                            count1++;
                                        }
                                        else if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column] == '.')) && (fromTopLeft == false
                                                 && fromTop == false && fromTopRight == false && fromRight == false && fromBottomRight == false && fromBottom == false && fromBottomLeft == false && fromLeft == false))
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] = '.';
                                            fromTop = true;
                                            fromTopRight = false;
                                            fromRight = false;
                                            fromBottomRight = false;
                                            fromBottom = false;
                                            fromBottomLeft = false;
                                            fromLeft = false;
                                            fromTopLeft = false;
                                            count1++;
                                        }*/

                                        // CHECK UP RIGHT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                        {
                                            if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column + 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column + 2] == '.'))/* && fromTop == true*/)
                                            {

                                                secondIt.row = eightMoves[0].moves[num-1].row - 2;
                                                secondIt.column = eightMoves[0].moves[num-1].column + 2;
                                                randoms++;
                                                count2 = randoms;
                                                upRight = true;
                                            }
                                        }

                                        // CHECK RIGHT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4)
                                         && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                         && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6)
                                         && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                         && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6)
                                         && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                         && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                         {
                                            if ((temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column + 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column + 2] == '.'))
                                            {

                                                thirdIt.row = eightMoves[0].moves[num-1].row;
                                                thirdIt.column = eightMoves[0].moves[num-1].column + 2;
                                                randoms++;
                                                count3 = randoms;
                                                right = true;
                                            }
                                         }
                                        // CHECK BOTTOM RIGHT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column + 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row + 2][eightMoves[0].moves[num-1].column + 2] == '.'))
                                            {
                                                fourthIt.row = eightMoves[0].moves[num-1].row + 2;
                                                fourthIt.column = eightMoves[0].moves[num-1].column + 2;
                                                randoms++;
                                                count4 = randoms;
                                                bottomRight = true;
                                            }
                                        }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row + 2][eightMoves[0].moves[num-1].column] == '.'))
                                            {
                                                fifthIt.row = eightMoves[0].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[0].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK BOTTOM LEFT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column - 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row + 2][eightMoves[0].moves[num-1].column - 2] == '.'))
                                            {
                                                sixthIt.row = eightMoves[0].moves[num-1].row + 2;
                                                sixthIt.column = eightMoves[0].moves[num-1].column - 2;
                                                randoms++;
                                                count6 = randoms;
                                                bottomLeft = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column - 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[0].moves[num-1].row;
                                                seventhIt.column = eightMoves[0].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        // CHECK UPPER LEFT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column  - 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column - 2] == '.'))
                                            {
                                                eigthIt.row = eightMoves[0].moves[num-1].row - 2;
                                                eigthIt.column = eightMoves[0].moves[num-1].column  - 2;
                                                randoms++;
                                                count8 = randoms;
                                                upLeft = true;
                                            }
                                        }
                                        if (up == false && upRight == false && right == false && bottomRight == false && bottom == false && bottomLeft == false && left == false && upLeft == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }


                                        //////// If there are multiple possible moves that can be made, assign a number to each move set, then select
                                        //////// one at random. Add the number of sheep that can be jumped over to the counter of sheep captured.
                                        //////// Change the spots where the fox "jumped" over a sheep to '.' characters indicating that there is no longer a sheep there.
                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] = '.';

                                        }
                                        // UP RIGHT
                                        if (count2 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column + 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column + 1] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column + 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM RIGHT
                                        if (count4 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row + 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column + 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row + 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column] = '.';
                                        }
                                        // BOTTOM LEFT
                                        if (count6 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row + 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column - 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column - 1] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column - 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column - 1] = '.';
                                        }
                                        // UP LEFT
                                        if (count8 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column - 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[0].theBoard[s][w] = temp1[s][w];
                                    }
                                    else
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                            && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2)
                                            && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                            && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                            && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6)
                                            && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                            && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 6))
                                            {
                                                if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[0].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[0].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK RIGHT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4)
                                         && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                         && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6)
                                         && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                         && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6)
                                         && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                         && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                         {
                                            if ((temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column + 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column + 2] == '.'))
                                            {

                                                thirdIt.row = eightMoves[0].moves[num-1].row;
                                                thirdIt.column = eightMoves[0].moves[num-1].column + 2;
                                                randoms++;
                                                count3 = randoms;
                                                right = true;
                                            }
                                         }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row + 2][eightMoves[0].moves[num-1].column] == '.'))
                                            {

                                                fifthIt.row = eightMoves[0].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[0].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column - 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[0].moves[num-1].row;
                                                seventhIt.column = eightMoves[0].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        if (up == false && right == false && bottom == false && left == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }


                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column + 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row + 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column - 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[0].theBoard[s][w] = temp1[s][w];
                                    }

                                }

                            }
                        }
                    areWeThereYet = false;
                    // CHECK UP RIGHT
                    if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                        {
                            if ((temp2[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo + 1] == 'S') && (temp2[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo + 2] == '.'))
                            {
                                bool up, upRight, right, bottomRight, bottom, bottomLeft, left, upLeft;
                                eightMoves[1].numCap++;
                                eightMoves[1].moves[0].row = foxObjects[foxNum].rowCo - 2;
                                eightMoves[1].moves[0].column = foxObjects[foxNum].colCo + 2;
                                temp2[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo + 1] = '.';
                                temp2[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                                for (int c = 0; c < 7; c++)
                                    for (int d = 0; d < 7; d++)
                                        eightMoves[1].theBoard[c][d] = temp2[c][d];
                                //resetBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';
                                for (int num = 1; num < 8 && areWeThereYet == false; num++)
                                {
                                    randoms = 0;
                                    count1 = 0;
                                    count2 = 0;
                                    count3 = 0;
                                    count4 = 0;
                                    count5 = 0;
                                    count6 = 0;
                                    count7 = 0;
                                    count8 = 0;
                                    up = false;
                                    upRight = false;
                                    right = false;
                                    bottomRight = false;
                                    bottom = false;
                                    bottomLeft = false;
                                    left = false;
                                    upLeft = false;
                                    if ((eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 2) || (eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 0) || (eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 4)
                                    || (eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 3) || (eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 2) || (eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 1)
                                    || (eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 0) || (eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 4) || (eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 3)
                                    || (eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 2) || (eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 6) || (eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 5)
                                    || (eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 4) || (eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 3) || (eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 2)
                                    || (eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 6) || (eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 4))
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 3)
                                            && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 4) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 2)
                                            && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 4)
                                            && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 1)
                                            && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 6)
                                            && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 1)
                                            && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 6))
                                            {
                                                if (((temp2[eightMoves[1].moves[num-1].row - 1][eightMoves[1].moves[num-1].column] == 'S') && (temp2[eightMoves[1].moves[num-1].row - 2][eightMoves[1].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[1].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[1].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK UP RIGHT
                                        if (!(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 4) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 2)
                                        && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 4)
                                        && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 4)
                                        && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 6)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 2)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 4)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 6)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 1) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 6)
                                        && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 4)
                                        && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 4))
                                        {
                                            if (((temp2[eightMoves[1].moves[num-1].row - 1][eightMoves[1].moves[num-1].column + 1] == 'S') && (temp2[eightMoves[1].moves[num-1].row - 2][eightMoves[1].moves[num-1].column + 2] == '.'))/* && fromTop == true*/)
                                            {

                                                secondIt.row = eightMoves[1].moves[num-1].row - 2;
                                                secondIt.column = eightMoves[1].moves[num-1].column + 2;
                                                randoms++;
                                                count2 = randoms;
                                                upRight = true;

                                            }
                                        }

                                        // CHECK RIGHT
                                        if (!(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 4)
                                         && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 4)
                                         && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 6)
                                         && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 6)
                                         && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 6)
                                         && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 3)
                                         && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 4))
                                         {
                                            if ((temp2[eightMoves[1].moves[num-1].row][eightMoves[1].moves[num-1].column + 1] == 'S') && (temp2[eightMoves[1].moves[num-1].row][eightMoves[1].moves[num-1].column + 2] == '.'))
                                            {

                                                thirdIt.row = eightMoves[1].moves[num-1].row;
                                                thirdIt.column = eightMoves[1].moves[num-1].column + 2;
                                                randoms++;
                                                count3 = randoms;
                                                right = true;
                                            }
                                         }
                                        // CHECK BOTTOM RIGHT
                                        if (!(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 2)
                                        && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 4) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 5)
                                        && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 6) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 0)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 4) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 5)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 6) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 0)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 1) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 4) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 5)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 6) && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 2)
                                        && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 4)
                                        && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 4) && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 4))
                                        {
                                            if ((temp2[eightMoves[1].moves[num-1].row + 1][eightMoves[1].moves[num-1].column + 1] == 'S') && (temp2[eightMoves[1].moves[num-1].row + 2][eightMoves[1].moves[num-1].column + 2] == '.'))
                                            {
                                                fourthIt.row = eightMoves[1].moves[num-1].row + 2;
                                                fourthIt.column = eightMoves[1].moves[num-1].column + 2;
                                                randoms++;
                                                count4 = randoms;
                                                bottomRight = true;
                                            }
                                        }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 6)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 6)
                                        && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 4) && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 2)
                                        && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 4))
                                        {
                                            if ((temp2[eightMoves[1].moves[num-1].row + 1][eightMoves[1].moves[num-1].column] == 'S') && (temp2[eightMoves[1].moves[num-1].row + 2][eightMoves[1].moves[num-1].column] == '.'))
                                            {

                                                fifthIt.row = eightMoves[1].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[1].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK BOTTOM LEFT
                                        if (!(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 4)
                                        && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 5)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 4) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 6)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 6)
                                        && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 4) && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 2)
                                        && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 4))
                                        {
                                            if ((temp2[eightMoves[1].moves[num-1].row + 1][eightMoves[1].moves[num-1].column - 1] == 'S') && (temp2[eightMoves[1].moves[num-1].row + 2][eightMoves[1].moves[num-1].column - 2] == '.'))
                                            {
                                                sixthIt.row = eightMoves[1].moves[num-1].row + 2;
                                                sixthIt.column = eightMoves[1].moves[num-1].column - 2;
                                                randoms++;
                                                count6 = randoms;
                                                bottomLeft = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 3))
                                        {
                                            if ((temp2[eightMoves[1].moves[num-1].row][eightMoves[1].moves[num-1].column - 1] == 'S') && (temp2[eightMoves[1].moves[num-1].row][eightMoves[1].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[1].moves[num-1].row;
                                                seventhIt.column = eightMoves[1].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        // CHECK UPPER LEFT
                                        if (!(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 4) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 2)
                                        && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 4)
                                        && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 6)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 4) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 6)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 5)
                                        && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 4)
                                        && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 3))
                                        {
                                            if ((temp2[eightMoves[1].moves[num-1].row - 1][eightMoves[1].moves[num-1].column  - 1] == 'S') && (temp2[eightMoves[1].moves[num-1].row - 2][eightMoves[1].moves[num-1].column - 2] == '.'))
                                            {
                                                eigthIt.row = eightMoves[1].moves[num-1].row - 2;
                                                eigthIt.column = eightMoves[1].moves[num-1].column  - 2;
                                                randoms++;
                                                count8 = randoms;
                                                upLeft = true;
                                            }
                                        }
                                        if (up == false && upRight == false && right == false && bottomRight == false && bottom == false && bottomLeft == false && left == false && upLeft == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }



                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[1].moves.push_back(dummy);
                                            eightMoves[1].moves[num].row = eightMoves[1].moves[num-1].row - 2;
                                            eightMoves[1].moves[num].column = eightMoves[1].moves[num-1].column;
                                            eightMoves[1].numCap++;
                                            temp2[eightMoves[1].moves[num-1].row - 1][eightMoves[1].moves[num-1].column] = '.';
                                        }
                                        // UP RIGHT
                                        if (count2 == randomNumber)
                                        {
                                            eightMoves[1].moves.push_back(dummy);
                                            eightMoves[1].moves[num].row = eightMoves[1].moves[num-1].row - 2;
                                            eightMoves[1].moves[num].column = eightMoves[1].moves[num-1].column + 2;
                                            eightMoves[1].numCap++;
                                            temp2[eightMoves[1].moves[num-1].row - 1][eightMoves[1].moves[num-1].column + 1] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[1].moves.push_back(dummy);
                                            eightMoves[1].moves[num].row = eightMoves[1].moves[num-1].row;
                                            eightMoves[1].moves[num].column = eightMoves[1].moves[num-1].column + 2;
                                            eightMoves[1].numCap++;
                                            temp2[eightMoves[1].moves[num-1].row][eightMoves[1].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM RIGHT
                                        if (count4 == randomNumber)
                                        {
                                            eightMoves[1].moves.push_back(dummy);
                                            eightMoves[1].moves[num].row = eightMoves[1].moves[num-1].row + 2;
                                            eightMoves[1].moves[num].column = eightMoves[1].moves[num-1].column + 2;
                                            eightMoves[1].numCap++;
                                            temp2[eightMoves[1].moves[num-1].row + 1][eightMoves[1].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[1].moves.push_back(dummy);
                                            eightMoves[1].moves[num].row = eightMoves[1].moves[num-1].row + 2;
                                            eightMoves[1].moves[num].column = eightMoves[1].moves[num-1].column;
                                            eightMoves[1].numCap++;
                                            temp2[eightMoves[1].moves[num-1].row + 1][eightMoves[1].moves[num-1].column] = '.';
                                        }
                                        // BOTTOM LEFT
                                        if (count6 == randomNumber)
                                        {
                                            eightMoves[1].moves.push_back(dummy);
                                            eightMoves[1].moves[num].row = eightMoves[1].moves[num-1].row + 2;
                                            eightMoves[1].moves[num].column = eightMoves[1].moves[num-1].column - 2;
                                            eightMoves[1].numCap++;
                                            temp2[eightMoves[1].moves[num-1].row + 1][eightMoves[1].moves[num-1].column - 1] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[1].moves.push_back(dummy);
                                            eightMoves[1].moves[num].row = eightMoves[1].moves[num-1].row;
                                            eightMoves[1].moves[num].column = eightMoves[1].moves[num-1].column - 2;
                                            eightMoves[1].numCap++;
                                            temp2[eightMoves[1].moves[num-1].row][eightMoves[1].moves[num-1].column - 1] = '.';
                                        }
                                        // UP LEFT
                                        if (count8 == randomNumber)
                                        {
                                            eightMoves[1].moves.push_back(dummy);
                                            eightMoves[1].moves[num].row = eightMoves[1].moves[num-1].row - 2;
                                            eightMoves[1].moves[num].column = eightMoves[1].moves[num-1].column - 2;
                                            eightMoves[1].numCap++;
                                            temp2[eightMoves[1].moves[num-1].row - 1][eightMoves[1].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[1].theBoard[s][w] = temp2[s][w];
                                    }
                                    else
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 3)
                                            && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 4) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 2)
                                            && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 4)
                                            && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 1)
                                            && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 6)
                                            && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 1)
                                            && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 6))
                                            {
                                                if (((temp2[eightMoves[1].moves[num-1].row - 1][eightMoves[1].moves[num-1].column] == 'S') && (temp2[eightMoves[1].moves[num-1].row - 2][eightMoves[1].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[1].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[1].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK RIGHT
                                        if (!(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 4)
                                         && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 4)
                                         && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 6)
                                         && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 6)
                                         && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 6)
                                         && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 3)
                                         && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 4))
                                         {
                                            if ((temp2[eightMoves[1].moves[num-1].row][eightMoves[1].moves[num-1].column + 1] == 'S') && (temp2[eightMoves[1].moves[num-1].row][eightMoves[1].moves[num-1].column + 2] == '.'))
                                            {

                                                thirdIt.row = eightMoves[1].moves[num-1].row;
                                                thirdIt.column = eightMoves[1].moves[num-1].column + 2;
                                                randoms++;
                                                count3 = randoms;
                                                right = true;
                                            }
                                         }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 6)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 5) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 6)
                                        && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 4) && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 2)
                                        && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 3) && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 4))
                                        {
                                            if ((temp2[eightMoves[1].moves[num-1].row + 1][eightMoves[1].moves[num-1].column] == 'S') && (temp2[eightMoves[1].moves[num-1].row + 2][eightMoves[1].moves[num-1].column] == '.'))
                                            {

                                                fifthIt.row = eightMoves[1].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[1].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 0 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 1 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 2 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 3 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 0) && !(eightMoves[1].moves[num-1].row == 4 && eightMoves[1].moves[num-1].column == 1)
                                        && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 5 && eightMoves[1].moves[num-1].column == 3)
                                        && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 2) && !(eightMoves[1].moves[num-1].row == 6 && eightMoves[1].moves[num-1].column == 3))
                                        {
                                            if ((temp2[eightMoves[1].moves[num-1].row][eightMoves[1].moves[num-1].column - 1] == 'S') && (temp2[eightMoves[1].moves[num-1].row][eightMoves[1].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[1].moves[num-1].row;
                                                seventhIt.column = eightMoves[1].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        if (up == false && right == false && bottom == false && left == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }


                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[1].moves.push_back(dummy);
                                            eightMoves[1].moves[num].row = eightMoves[1].moves[num-1].row - 2;
                                            eightMoves[1].moves[num].column = eightMoves[1].moves[num-1].column;
                                            eightMoves[1].numCap++;
                                            temp2[eightMoves[1].moves[num-1].row - 1][eightMoves[1].moves[num-1].column] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[1].moves.push_back(dummy);
                                            eightMoves[1].moves[num].row = eightMoves[1].moves[num-1].row;
                                            eightMoves[1].moves[num].column = eightMoves[1].moves[num-1].column + 2;
                                            eightMoves[1].numCap++;
                                            temp2[eightMoves[1].moves[num-1].row][eightMoves[1].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[1].moves.push_back(dummy);
                                            eightMoves[1].moves[num].row = eightMoves[1].moves[num-1].row + 2;
                                            eightMoves[1].moves[num].column = eightMoves[1].moves[num-1].column;
                                            eightMoves[1].numCap++;
                                            temp2[eightMoves[1].moves[num-1].row + 1][eightMoves[1].moves[num-1].column] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[1].moves.push_back(dummy);
                                            eightMoves[1].moves[num].row = eightMoves[1].moves[num-1].row;
                                            eightMoves[1].moves[num].column = eightMoves[1].moves[num-1].column - 2;
                                            eightMoves[1].numCap++;
                                            temp2[eightMoves[1].moves[num-1].row][eightMoves[1].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[1].theBoard[s][w] = temp2[s][w];
                                    }
                                }

                            }
                        }
                    areWeThereYet = false;
                    // CHECK RIGHT
                    if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                        {
                            if ((temp3[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] == 'S') && (temp3[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 2] == '.'))
                            {
                                bool up, upRight, right, bottomRight, bottom, bottomLeft, left, upLeft;
                                eightMoves[2].numCap++;
                                eightMoves[2].moves[0].row = foxObjects[foxNum].rowCo;
                                eightMoves[2].moves[0].column = foxObjects[foxNum].colCo + 2;
                                temp3[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] = '.';
                                temp3[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                                for (int c = 0; c < 7; c++)
                                    for (int d = 0; d < 7; d++)
                                        eightMoves[2].theBoard[c][d] = temp3[c][d];
                                //resetBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';
                                for (int num = 1; num < 8 && areWeThereYet == false; num++)
                                {
                                    randoms = 0;
                                    count1 = 0;
                                    count2 = 0;
                                    count3 = 0;
                                    count4 = 0;
                                    count5 = 0;
                                    count6 = 0;
                                    count7 = 0;
                                    count8 = 0;
                                    up = false;
                                    upRight = false;
                                    right = false;
                                    bottomRight = false;
                                    bottom = false;
                                    bottomLeft = false;
                                    left = false;
                                    upLeft = false;
                                    if ((eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) || (eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) || (eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4)
                                    || (eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) || (eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 2) || (eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                    || (eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) || (eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 4) || (eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 3)
                                    || (eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 2) || (eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6) || (eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5)
                                    || (eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 4) || (eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3) || (eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2)
                                    || (eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6) || (eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                            && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2)
                                            && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                            && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                            && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6)
                                            && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                            && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 6))
                                            {
                                                if (((temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column] == 'S') && (temp3[eightMoves[2].moves[num-1].row - 2][eightMoves[2].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[2].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[2].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;

                                                }
                                            }
                                        // CHECK UP RIGHT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 4)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 4)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 4)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                        {
                                            if (((temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column + 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row - 2][eightMoves[2].moves[num-1].column + 2] == '.'))/* && fromTop == true*/)
                                            {

                                                secondIt.row = eightMoves[2].moves[num-1].row - 2;
                                                secondIt.column = eightMoves[2].moves[num-1].column + 2;
                                                randoms++;
                                                count2 = randoms;
                                                upRight = true;
                                            }
                                        }

                                        // CHECK RIGHT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4)
                                         && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                         && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6)
                                         && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                         && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6)
                                         && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                         && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                         {
                                            if ((temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 2] == '.'))
                                            {

                                                thirdIt.row = eightMoves[2].moves[num-1].row;
                                                thirdIt.column = eightMoves[2].moves[num-1].column + 2;
                                                randoms++;
                                                count3 = randoms;
                                                right = true;
                                            }
                                         }
                                        // CHECK BOTTOM RIGHT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 4)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column + 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row + 2][eightMoves[2].moves[num-1].column + 2] == '.'))
                                            {
                                                fourthIt.row = eightMoves[2].moves[num-1].row + 2;
                                                fourthIt.column = eightMoves[2].moves[num-1].column + 2;
                                                randoms++;
                                                count4 = randoms;
                                                bottomRight = true;
                                            }
                                        }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column] == 'S') && (temp3[eightMoves[2].moves[num-1].row + 2][eightMoves[2].moves[num-1].column] == '.'))
                                            {

                                                fifthIt.row = eightMoves[2].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[2].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK BOTTOM LEFT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column - 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row + 2][eightMoves[2].moves[num-1].column - 2] == '.'))
                                            {
                                                sixthIt.row = eightMoves[2].moves[num-1].row + 2;
                                                sixthIt.column = eightMoves[2].moves[num-1].column - 2;
                                                randoms++;
                                                count6 = randoms;
                                                bottomLeft = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[2].moves[num-1].row;
                                                seventhIt.column = eightMoves[2].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        // CHECK UPPER LEFT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 4)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column  - 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row - 2][eightMoves[2].moves[num-1].column - 2] == '.'))
                                            {
                                                eigthIt.row = eightMoves[2].moves[num-1].row - 2;
                                                eigthIt.column = eightMoves[2].moves[num-1].column  - 2;
                                                randoms++;
                                                count8 = randoms;
                                                upLeft = true;
                                            }
                                        }
                                        if (up == false && upRight == false && right == false && bottomRight == false && bottom == false && bottomLeft == false && left == false && upLeft == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }



                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row - 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column] = '.';
                                        }
                                        // UP RIGHT
                                        if (count2 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row - 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column + 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column + 1] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column + 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM RIGHT
                                        if (count4 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row + 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column + 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row + 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column] = '.';
                                        }
                                        // BOTTOM LEFT
                                        if (count6 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row + 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column - 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[1].moves[num-1].row + 1][eightMoves[2].moves[num-1].column - 1] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column - 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 1] = '.';
                                        }
                                        // UP LEFT
                                        if (count8 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row - 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column - 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[2].theBoard[s][w] = temp3[s][w];
                                    }
                                    else
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                            && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2)
                                            && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                            && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                            && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6)
                                            && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                            && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 6))
                                            {
                                                if (((temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column] == 'S') && (temp3[eightMoves[2].moves[num-1].row - 2][eightMoves[2].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[2].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[2].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK RIGHT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4)
                                         && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                         && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6)
                                         && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                         && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6)
                                         && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                         && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                         {
                                            if ((temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 2] == '.'))
                                            {

                                                thirdIt.row = eightMoves[2].moves[num-1].row;
                                                thirdIt.column = eightMoves[2].moves[num-1].column + 2;
                                                randoms++;
                                                count3 = randoms;
                                                right = true;
                                            }
                                         }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column] == 'S') && (temp3[eightMoves[2].moves[num-1].row + 2][eightMoves[2].moves[num-1].column] == '.'))
                                            {

                                                fifthIt.row = eightMoves[2].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[2].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[2].moves[num-1].row;
                                                seventhIt.column = eightMoves[2].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        if (up == false && right == false && bottom == false && left == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }


                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row - 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column + 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row + 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column - 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[2].theBoard[s][w] = temp3[s][w];
                                    }
                                }

                            }
                        }
                    areWeThereYet = false;
                    // CHECK BOTTOM RIGHT
                    if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4))
                        {
                            if ((temp4[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo + 1] == 'S') && (temp4[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo + 2] == '.'))
                            {
                                bool up, upRight, right, bottomRight, bottom, bottomLeft, left, upLeft;
                                eightMoves[3].numCap++;
                                eightMoves[3].moves[0].row = foxObjects[foxNum].rowCo + 2;
                                eightMoves[3].moves[0].column = foxObjects[foxNum].colCo + 2;
                                temp4[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo + 1] = '.';
                                temp4[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                                for (int c = 0; c < 7; c++)
                                    for (int d = 0; d < 7; d++)
                                        eightMoves[3].theBoard[c][d] = temp4[c][d];
                                //resetBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';
                                for (int num = 1; num < 8 && areWeThereYet == false; num++)
                                {
                                    randoms = 0;
                                    count1 = 0;
                                    count2 = 0;
                                    count3 = 0;
                                    count4 = 0;
                                    count5 = 0;
                                    count6 = 0;
                                    count7 = 0;
                                    count8 = 0;
                                    up = false;
                                    upRight = false;
                                    right = false;
                                    bottomRight = false;
                                    bottom = false;
                                    bottomLeft = false;
                                    left = false;
                                    upLeft = false;
                                    if ((eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 2) || (eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 0) || (eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 4)
                                    || (eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 3) || (eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 2) || (eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 1)
                                    || (eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 0) || (eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 4) || (eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 3)
                                    || (eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 2) || (eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 6) || (eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 5)
                                    || (eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 4) || (eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 3) || (eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 2)
                                    || (eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 6) || (eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 4))
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 3)
                                            && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 4) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 2)
                                            && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 4)
                                            && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 1)
                                            && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 6)
                                            && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 1)
                                            && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 6))
                                            {
                                                if (((temp4[eightMoves[3].moves[num-1].row - 1][eightMoves[3].moves[num-1].column] == 'S') && (temp4[eightMoves[3].moves[num-1].row - 2][eightMoves[3].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[3].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[3].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;

                                                }
                                            }
                                        // CHECK UP RIGHT
                                        if (!(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 3)
                                                && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 4) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 2)
                                                && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 4)
                                                && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 1)
                                                && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 4)
                                                && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 6)
                                                && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 2)
                                                && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 4)
                                                && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 6)
                                                && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 1) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 3)
                                                && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 6)
                                                && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 4)
                                                && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 4))
                                                {
                                                    if (((temp4[eightMoves[3].moves[num-1].row - 1][eightMoves[3].moves[num-1].column + 1] == 'S') && (temp4[eightMoves[3].moves[num-1].row - 2][eightMoves[3].moves[num-1].column + 2] == '.'))/* && fromTop == true*/)
                                                    {

                                                        secondIt.row = eightMoves[3].moves[num-1].row - 2;
                                                        secondIt.column = eightMoves[3].moves[num-1].column + 2;
                                                        randoms++;
                                                        count2 = randoms;
                                                        upRight = true;
                                                    }
                                                }

                                        // CHECK RIGHT
                                        if (!(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 4)
                                                 && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 4)
                                                 && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 6)
                                                 && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 6)
                                                 && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 6)
                                                 && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 3)
                                                 && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 4))
                                                 {
                                                    if ((temp4[eightMoves[3].moves[num-1].row][eightMoves[3].moves[num-1].column + 1] == 'S') && (temp4[eightMoves[3].moves[num-1].row][eightMoves[3].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[3].moves[num-1].row;
                                                        thirdIt.column = eightMoves[3].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM RIGHT
                                        if (!(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 2)
                                        && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 4) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 5)
                                        && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 6) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 0)
                                        && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 4) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 5)
                                        && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 6) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 0)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 1) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 4) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 5)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 6) && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 2)
                                        && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 4)
                                        && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 4) && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 4))
                                        {
                                            if ((temp4[eightMoves[3].moves[num-1].row + 1][eightMoves[3].moves[num-1].column + 1] == 'S') && (temp4[eightMoves[3].moves[num-1].row + 2][eightMoves[3].moves[num-1].column + 2] == '.'))
                                            {
                                                fourthIt.row = eightMoves[3].moves[num-1].row + 2;
                                                fourthIt.column = eightMoves[3].moves[num-1].column + 2;
                                                randoms++;
                                                count4 = randoms;
                                                bottomRight = true;
                                            }
                                        }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 6)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 6)
                                        && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 4) && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 2)
                                        && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 4))
                                        {
                                            if ((temp4[eightMoves[3].moves[num-1].row + 1][eightMoves[3].moves[num-1].column] == 'S') && (temp4[eightMoves[3].moves[num-1].row + 2][eightMoves[3].moves[num-1].column] == '.'))
                                            {

                                                fifthIt.row = eightMoves[3].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[3].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK BOTTOM LEFT
                                        if (!(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 4)
                                        && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 5)
                                        && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 4) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 6)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 6)
                                        && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 4) && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 2)
                                        && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 4))
                                        {
                                            if ((temp4[eightMoves[3].moves[num-1].row + 1][eightMoves[3].moves[num-1].column - 1] == 'S') && (temp4[eightMoves[3].moves[num-1].row + 2][eightMoves[3].moves[num-1].column - 2] == '.'))
                                            {
                                                sixthIt.row = eightMoves[3].moves[num-1].row + 2;
                                                sixthIt.column = eightMoves[3].moves[num-1].column - 2;
                                                randoms++;
                                                count6 = randoms;
                                                bottomLeft = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 3))
                                        {
                                            if ((temp4[eightMoves[3].moves[num-1].row][eightMoves[3].moves[num-1].column - 1] == 'S') && (temp4[eightMoves[3].moves[num-1].row][eightMoves[3].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[3].moves[num-1].row;
                                                seventhIt.column = eightMoves[3].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        // CHECK UPPER LEFT
                                        if (!(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 4) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 2)
                                        && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 4)
                                        && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 6)
                                        && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 4) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 6)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 5)
                                        && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 4)
                                        && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 3))
                                        {
                                            if ((temp4[eightMoves[3].moves[num-1].row - 1][eightMoves[3].moves[num-1].column  - 1] == 'S') && (temp4[eightMoves[3].moves[num-1].row - 2][eightMoves[3].moves[num-1].column - 2] == '.'))
                                            {
                                                eigthIt.row = eightMoves[3].moves[num-1].row - 2;
                                                eigthIt.column = eightMoves[3].moves[num-1].column  - 2;
                                                randoms++;
                                                count8 = randoms;
                                                upLeft = true;
                                            }
                                        }
                                        if (up == false && upLeft == false && left == false && bottomLeft == false && bottom == false && bottomRight == false && right == false && upRight == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }



                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[3].moves.push_back(dummy);
                                            eightMoves[3].moves[num].row = eightMoves[3].moves[num-1].row - 2;
                                            eightMoves[3].moves[num].column = eightMoves[3].moves[num-1].column;
                                            eightMoves[3].numCap++;
                                            temp4[eightMoves[3].moves[num-1].row - 1][eightMoves[3].moves[num-1].column] = '.';
                                        }
                                        // UP RIGHT
                                        if (count2 == randomNumber)
                                        {
                                            eightMoves[3].moves.push_back(dummy);
                                            eightMoves[3].moves[num].row = eightMoves[3].moves[num-1].row - 2;
                                            eightMoves[3].moves[num].column = eightMoves[3].moves[num-1].column + 2;
                                            eightMoves[3].numCap++;
                                            temp4[eightMoves[3].moves[num-1].row - 1][eightMoves[3].moves[num-1].column + 1] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[3].moves.push_back(dummy);
                                            eightMoves[3].moves[num].row = eightMoves[3].moves[num-1].row;
                                            eightMoves[3].moves[num].column = eightMoves[3].moves[num-1].column + 2;
                                            eightMoves[3].numCap++;
                                            temp4[eightMoves[3].moves[num-1].row][eightMoves[3].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM RIGHT
                                        if (count4 == randomNumber)
                                        {
                                            eightMoves[3].moves.push_back(dummy);
                                            eightMoves[3].moves[num].row = eightMoves[3].moves[num-1].row + 2;
                                            eightMoves[3].moves[num].column = eightMoves[3].moves[num-1].column + 2;
                                            eightMoves[3].numCap++;
                                            temp4[eightMoves[3].moves[num-1].row + 1][eightMoves[3].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[3].moves.push_back(dummy);
                                            eightMoves[3].moves[num].row = eightMoves[3].moves[num-1].row + 2;
                                            eightMoves[3].moves[num].column = eightMoves[3].moves[num-1].column;
                                            eightMoves[3].numCap++;
                                            temp4[eightMoves[3].moves[num-1].row + 1][eightMoves[3].moves[num-1].column] = '.';
                                        }
                                        // BOTTOM LEFT
                                        if (count6 == randomNumber)
                                        {
                                            eightMoves[3].moves.push_back(dummy);
                                            eightMoves[3].moves[num].row = eightMoves[3].moves[num-1].row + 2;
                                            eightMoves[3].moves[num].column = eightMoves[3].moves[num-1].column - 2;
                                            eightMoves[3].numCap++;
                                            temp4[eightMoves[3].moves[num-1].row + 1][eightMoves[3].moves[num-1].column - 1] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[3].moves.push_back(dummy);
                                            eightMoves[3].moves[num].row = eightMoves[3].moves[num-1].row;
                                            eightMoves[3].moves[num].column = eightMoves[3].moves[num-1].column - 2;
                                            eightMoves[3].numCap++;
                                            temp4[eightMoves[3].moves[num-1].row][eightMoves[3].moves[num-1].column - 1] = '.';
                                        }
                                        // UP LEFT
                                        if (count8 == randomNumber)
                                        {
                                            eightMoves[3].moves.push_back(dummy);
                                            eightMoves[3].moves[num].row = eightMoves[3].moves[num-1].row - 2;
                                            eightMoves[3].moves[num].column = eightMoves[3].moves[num-1].column - 2;
                                            eightMoves[3].numCap++;
                                            temp4[eightMoves[3].moves[num-1].row - 1][eightMoves[3].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[3].theBoard[s][w] = temp4[s][w];
                                    }
                                    else
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 3)
                                            && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 4) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 2)
                                            && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 4)
                                            && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 1)
                                            && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 6)
                                            && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 1)
                                            && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 6))
                                            {
                                                if (((temp4[eightMoves[3].moves[num-1].row - 1][eightMoves[3].moves[num-1].column] == 'S') && (temp4[eightMoves[3].moves[num-1].row - 2][eightMoves[3].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[3].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[3].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK RIGHT
                                        if (!(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 4)
                                                 && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 4)
                                                 && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 6)
                                                 && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 6)
                                                 && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 6)
                                                 && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 3)
                                                 && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 4))
                                                 {
                                                    if ((temp4[eightMoves[3].moves[num-1].row][eightMoves[3].moves[num-1].column + 1] == 'S') && (temp4[eightMoves[3].moves[num-1].row][eightMoves[3].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[3].moves[num-1].row;
                                                        thirdIt.column = eightMoves[3].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 6)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 5) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 6)
                                        && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 4) && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 2)
                                        && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 3) && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 4))
                                        {
                                            if ((temp4[eightMoves[3].moves[num-1].row + 1][eightMoves[3].moves[num-1].column] == 'S') && (temp4[eightMoves[3].moves[num-1].row + 2][eightMoves[3].moves[num-1].column] == '.'))
                                            {

                                                fifthIt.row = eightMoves[3].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[3].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 0 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 1 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 2 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 3 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 0) && !(eightMoves[3].moves[num-1].row == 4 && eightMoves[3].moves[num-1].column == 1)
                                        && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 5 && eightMoves[3].moves[num-1].column == 3)
                                        && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 2) && !(eightMoves[3].moves[num-1].row == 6 && eightMoves[3].moves[num-1].column == 3))
                                        {
                                            if ((temp4[eightMoves[3].moves[num-1].row][eightMoves[3].moves[num-1].column - 1] == 'S') && (temp4[eightMoves[3].moves[num-1].row][eightMoves[3].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[3].moves[num-1].row;
                                                seventhIt.column = eightMoves[3].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        if (up == false && right == false && bottom == false && left == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }


                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[3].moves.push_back(dummy);
                                            eightMoves[3].moves[num].row = eightMoves[3].moves[num-1].row - 2;
                                            eightMoves[3].moves[num].column = eightMoves[3].moves[num-1].column;
                                            eightMoves[3].numCap++;
                                            temp4[eightMoves[3].moves[num-1].row - 1][eightMoves[3].moves[num-1].column] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[3].moves.push_back(dummy);
                                            eightMoves[3].moves[num].row = eightMoves[3].moves[num-1].row;
                                            eightMoves[3].moves[num].column = eightMoves[3].moves[num-1].column + 2;
                                            eightMoves[3].numCap++;
                                            temp4[eightMoves[3].moves[num-1].row][eightMoves[3].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[3].moves.push_back(dummy);
                                            eightMoves[3].moves[num].row = eightMoves[3].moves[num-1].row + 2;
                                            eightMoves[3].moves[num].column = eightMoves[3].moves[num-1].column;
                                            eightMoves[3].numCap++;
                                            temp4[eightMoves[3].moves[num-1].row + 1][eightMoves[3].moves[num-1].column] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[3].moves.push_back(dummy);
                                            eightMoves[3].moves[num].row = eightMoves[3].moves[num-1].row;
                                            eightMoves[3].moves[num].column = eightMoves[3].moves[num-1].column - 2;
                                            eightMoves[3].numCap++;
                                            temp4[eightMoves[3].moves[num-1].row][eightMoves[3].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[3].theBoard[s][w] = temp4[s][w];
                                    }
                                }

                            }
                        }
                    areWeThereYet = false;
                    // CHECK BOTTOM
                    if (!(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                        {
                            if ((temp5[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] == 'S') && (temp5[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo] == '.'))
                            {
                                bool up, upRight, right, bottomRight, bottom, bottomLeft, left, upLeft;
                                eightMoves[4].numCap++;
                                eightMoves[4].moves[0].row = foxObjects[foxNum].rowCo + 2;
                                eightMoves[4].moves[0].column = foxObjects[foxNum].colCo;

                                temp5[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] = '.';
                                temp5[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                                for (int c = 0; c < 7; c++)
                                    for (int d = 0; d < 7; d++)
                                        eightMoves[4].theBoard[c][d] = temp5[c][d];
                                //resetBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';
                                for (int num = 1; num < 8 && areWeThereYet == false; num++)
                                {
                                    randoms = 0;
                                    count1 = 0;
                                    count2 = 0;
                                    count3 = 0;
                                    count4 = 0;
                                    count5 = 0;
                                    count6 = 0;
                                    count7 = 0;
                                    count8 = 0;
                                    up = false;
                                    upRight = false;
                                    right = false;
                                    bottomRight = false;
                                    bottom = false;
                                    bottomLeft = false;
                                    left = false;
                                    upLeft = false;
                                    if ((eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) || (eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) || (eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4)
                                    || (eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) || (eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 2) || (eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                    || (eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) || (eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 4) || (eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 3)
                                    || (eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 2) || (eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6) || (eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5)
                                    || (eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 4) || (eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3) || (eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2)
                                    || (eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6) || (eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                            && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2)
                                            && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                            && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                            && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6)
                                            && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                            && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 6))
                                            {
                                                if (((temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column] == 'S') && (temp5[eightMoves[4].moves[num-1].row - 2][eightMoves[4].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[4].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[4].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;

                                                }
                                            }
                                        // CHECK UP RIGHT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                                && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2)
                                                && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                                && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                                && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 4)
                                                && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6)
                                                && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 2)
                                                && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 4)
                                                && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                                && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 3)
                                                && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6)
                                                && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 4)
                                                && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                                {
                                                    if (((temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column + 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row - 2][eightMoves[4].moves[num-1].column + 2] == '.'))/* && fromTop == true*/)
                                                    {

                                                        secondIt.row = eightMoves[4].moves[num-1].row - 2;
                                                        secondIt.column = eightMoves[4].moves[num-1].column + 2;
                                                        randoms++;
                                                        count2 = randoms;
                                                        upRight = true;
                                                    }
                                                }

                                        // CHECK RIGHT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4)
                                                 && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                                 && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6)
                                                 && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                                 && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6)
                                                 && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                                 && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                                 {
                                                    if ((temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column + 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[4].moves[num-1].row;
                                                        thirdIt.column = eightMoves[4].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM RIGHT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2)
                                                && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                                && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5)
                                                && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0)
                                                && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 3)
                                                && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5)
                                                && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0)
                                                && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 3)
                                                && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5)
                                                && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2)
                                                && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 4)
                                                && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3)
                                                && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4))
                                                {
                                                    if ((temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column + 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row + 2][eightMoves[4].moves[num-1].column + 2] == '.'))
                                                    {
                                                        fourthIt.row = eightMoves[4].moves[num-1].row + 2;
                                                        fourthIt.column = eightMoves[4].moves[num-1].column + 2;
                                                        randoms++;
                                                        count4 = randoms;
                                                        bottomRight = true;
                                                    }
                                                }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2)
                                        && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                        {
                                            if ((temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column] == 'S') && (temp5[eightMoves[4].moves[num-1].row + 2][eightMoves[4].moves[num-1].column] == '.'))
                                            {

                                                fifthIt.row = eightMoves[4].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[4].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK BOTTOM LEFT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2)
                                        && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                        {
                                            if ((temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column - 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row + 2][eightMoves[4].moves[num-1].column - 2] == '.'))
                                            {
                                                sixthIt.row = eightMoves[4].moves[num-1].row + 2;
                                                sixthIt.column = eightMoves[4].moves[num-1].column - 2;
                                                randoms++;
                                                count6 = randoms;
                                                bottomLeft = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3))
                                        {
                                            if ((temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column - 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[4].moves[num-1].row;
                                                seventhIt.column = eightMoves[4].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        // CHECK UPPER LEFT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2)
                                        && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 4)
                                        && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3))
                                        {
                                            if ((temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column  - 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row - 2][eightMoves[4].moves[num-1].column - 2] == '.'))
                                            {
                                                eigthIt.row = eightMoves[4].moves[num-1].row - 2;
                                                eigthIt.column = eightMoves[4].moves[num-1].column  - 2;
                                                randoms++;
                                                count8 = randoms;
                                                upLeft = true;
                                            }
                                        }
                                        if (up == false && upRight == false && right == false && bottomRight == false && bottom == false && bottomLeft == false && left == false && upLeft == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }



                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row - 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column] = '.';
                                        }
                                        // UP RIGHT
                                        if (count2 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row - 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column + 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column + 1] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column + 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM RIGHT
                                        if (count4 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row + 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column + 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row + 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column] = '.';
                                        }
                                        // BOTTOM LEFT
                                        if (count6 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row + 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column - 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column - 1] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column - 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column - 1] = '.';
                                        }
                                        // UP LEFT
                                        if (count8 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row - 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column - 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[4].theBoard[s][w] = temp5[s][w];
                                    }
                                    else
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                            && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2)
                                            && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                            && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                            && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6)
                                            && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                            && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 6))
                                            {
                                                if (((temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column] == 'S') && (temp5[eightMoves[4].moves[num-1].row - 2][eightMoves[4].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[4].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[4].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK RIGHT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4)
                                                 && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                                 && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6)
                                                 && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                                 && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6)
                                                 && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                                 && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                                 {
                                                    if ((temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column + 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[4].moves[num-1].row;
                                                        thirdIt.column = eightMoves[4].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2)
                                        && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                        {
                                            if ((temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column] == 'S') && (temp5[eightMoves[4].moves[num-1].row + 2][eightMoves[4].moves[num-1].column] == '.'))
                                            {

                                                fifthIt.row = eightMoves[4].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[4].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3))
                                        {
                                            if ((temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column - 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[4].moves[num-1].row;
                                                seventhIt.column = eightMoves[4].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        if (up == false && right == false && bottom == false && left == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }


                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row - 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column + 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row + 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column - 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[4].theBoard[s][w] = temp5[s][w];
                                    }
                                }

                            }
                        }
                    areWeThereYet = false;
                    // CHECK BOTTOM LEFT
                    if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                        {
                            if ((temp6[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo - 1] == 'S') && (temp6[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo - 2] == '.'))
                            {
                                bool up, upRight, right, bottomRight, bottom, bottomLeft, left, upLeft;
                                eightMoves[5].numCap++;
                                eightMoves[5].moves[0].row = foxObjects[foxNum].rowCo + 2;
                                eightMoves[5].moves[0].column = foxObjects[foxNum].colCo - 2;

                                temp6[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo - 1] = '.';
                                temp6[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                                for (int c = 0; c < 7; c++)
                                    for (int d = 0; d < 7; d++)
                                        eightMoves[5].theBoard[c][d] = temp6[c][d];
                                //resetBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';
                                for (int num = 1; num < 8 && areWeThereYet == false; num++)
                                {
                                    randoms = 0;
                                    count1 = 0;
                                    count2 = 0;
                                    count3 = 0;
                                    count4 = 0;
                                    count5 = 0;
                                    count6 = 0;
                                    count7 = 0;
                                    count8 = 0;
                                    up = false;
                                    upRight = false;
                                    right = false;
                                    bottomRight = false;
                                    bottom = false;
                                    bottomLeft = false;
                                    left = false;
                                    upLeft = false;
                                    if ((eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 2) || (eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 0) || (eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 4)
                                    || (eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 3) || (eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 2) || (eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 1)
                                    || (eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 0) || (eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 4) || (eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 3)
                                    || (eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 2) || (eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 6) || (eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 5)
                                    || (eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 4) || (eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 3) || (eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 2)
                                    || (eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 6) || (eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 4))
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 3)
                                            && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 4) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 2)
                                            && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 4)
                                            && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 1)
                                            && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 6)
                                            && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 1)
                                            && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 6))
                                            {
                                                if (((temp6[eightMoves[5].moves[num-1].row - 1][eightMoves[5].moves[num-1].column] == 'S') && (temp6[eightMoves[5].moves[num-1].row - 2][eightMoves[5].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[5].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[5].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;

                                                }
                                            }
                                        // CHECK UP RIGHT
                                        if (!(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 3)
                                                && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 4) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 2)
                                                && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 4)
                                                && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 1)
                                                && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 4)
                                                && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 6)
                                                && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 2)
                                                && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 4)
                                                && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 6)
                                                && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 1) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 3)
                                                && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 6)
                                                && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 4)
                                                && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 4))
                                                {
                                                    if (((temp6[eightMoves[5].moves[num-1].row - 1][eightMoves[5].moves[num-1].column + 1] == 'S') && (temp6[eightMoves[5].moves[num-1].row - 2][eightMoves[5].moves[num-1].column + 2] == '.'))/* && fromTop == true*/)
                                                    {

                                                        secondIt.row = eightMoves[5].moves[num-1].row - 2;
                                                        secondIt.column = eightMoves[5].moves[num-1].column + 2;
                                                        randoms++;
                                                        count2 = randoms;
                                                        upRight = true;
                                                    }
                                                }

                                        // CHECK RIGHT
                                        if (!(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 4)
                                                 && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 4)
                                                 && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 6)
                                                 && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 6)
                                                 && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 6)
                                                 && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 3)
                                                 && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 4))
                                                 {
                                                    if ((temp6[eightMoves[5].moves[num-1].row][eightMoves[5].moves[num-1].column + 1] == 'S') && (temp6[eightMoves[5].moves[num-1].row][eightMoves[5].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[5].moves[num-1].row;
                                                        thirdIt.column = eightMoves[5].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM RIGHT
                                        if (!(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 2)
                                                && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 4) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 1)
                                                && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 5)
                                                && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 6) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 0)
                                                && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 3)
                                                && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 4) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 5)
                                                && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 6) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 0)
                                                && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 1) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 3)
                                                && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 4) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 5)
                                                && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 6) && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 2)
                                                && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 4)
                                                && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 3)
                                                && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 4) && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 4))
                                                {
                                                    if ((temp6[eightMoves[5].moves[num-1].row + 1][eightMoves[5].moves[num-1].column + 1] == 'S') && (temp6[eightMoves[5].moves[num-1].row + 2][eightMoves[5].moves[num-1].column + 2] == '.'))
                                                    {
                                                        fourthIt.row = eightMoves[5].moves[num-1].row + 2;
                                                        fourthIt.column = eightMoves[5].moves[num-1].column + 2;
                                                        randoms++;
                                                        count4 = randoms;
                                                        bottomRight = true;
                                                    }
                                                }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 1)
                                                && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 6)
                                                && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 1)
                                                && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 6)
                                                && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 3)
                                                && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 4) && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 2)
                                                && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 4))
                                                {
                                                    if ((temp6[eightMoves[5].moves[num-1].row + 1][eightMoves[5].moves[num-1].column] == 'S') && (temp6[eightMoves[5].moves[num-1].row + 2][eightMoves[5].moves[num-1].column] == '.'))
                                                    {

                                                        fifthIt.row = eightMoves[5].moves[num-1].row + 2;
                                                        fifthIt.column = eightMoves[5].moves[num-1].column;
                                                        randoms++;
                                                        count5 = randoms;
                                                        bottom = true;
                                                    }
                                                }
                                        // CHECK BOTTOM LEFT
                                        if (!(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 3)
                                        && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 4)
                                        && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 1)
                                        && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 5)
                                        && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 1)
                                        && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 3)
                                        && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 4) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 6)
                                        && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 1)
                                        && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 3)
                                        && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 6)
                                        && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 3)
                                        && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 4) && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 2)
                                        && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 4))
                                        {
                                            if ((temp6[eightMoves[5].moves[num-1].row + 1][eightMoves[5].moves[num-1].column - 1] == 'S') && (temp6[eightMoves[5].moves[num-1].row + 2][eightMoves[5].moves[num-1].column - 2] == '.'))
                                            {
                                                sixthIt.row = eightMoves[4].moves[num-1].row + 2;
                                                sixthIt.column = eightMoves[4].moves[num-1].column - 2;
                                                randoms++;
                                                count6 = randoms;
                                                bottomLeft = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 3)
                                        && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 3)
                                        && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 1)
                                        && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 1)
                                        && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 1)
                                        && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 3)
                                        && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 3))
                                        {
                                            if ((temp6[eightMoves[5].moves[num-1].row][eightMoves[5].moves[num-1].column - 1] == 'S') && (temp6[eightMoves[5].moves[num-1].row][eightMoves[5].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[5].moves[num-1].row;
                                                seventhIt.column = eightMoves[5].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        // CHECK UPPER LEFT
                                        if (!(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 3)
                                        && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 4) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 2)
                                        && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 4)
                                        && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 1)
                                        && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 3)
                                        && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 6)
                                        && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 1)
                                        && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 3)
                                        && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 4) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 6)
                                        && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 1)
                                        && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 5)
                                        && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 4)
                                        && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 3))
                                        {
                                            if ((temp6[eightMoves[5].moves[num-1].row - 1][eightMoves[5].moves[num-1].column  - 1] == 'S') && (temp6[eightMoves[5].moves[num-1].row - 2][eightMoves[5].moves[num-1].column - 2] == '.'))
                                            {
                                                eigthIt.row = eightMoves[5].moves[num-1].row - 2;
                                                eigthIt.column = eightMoves[5].moves[num-1].column  - 2;
                                                randoms++;
                                                count8 = randoms;
                                                upLeft = true;
                                            }
                                        }
                                        if (up == false && upRight == false && right == false && bottomRight == false && bottom == false && bottomLeft == false && left == false && upLeft == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }



                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[5].moves.push_back(dummy);
                                            eightMoves[5].moves[num].row = eightMoves[5].moves[num-1].row - 2;
                                            eightMoves[5].moves[num].column = eightMoves[5].moves[num-1].column;
                                            eightMoves[5].numCap++;
                                            temp6[eightMoves[5].moves[num-1].row - 1][eightMoves[5].moves[num-1].column] = '.';
                                        }
                                        // UP RIGHT
                                        if (count2 == randomNumber)
                                        {
                                            eightMoves[5].moves.push_back(dummy);
                                            eightMoves[5].moves[num].row = eightMoves[5].moves[num-1].row - 2;
                                            eightMoves[5].moves[num].column = eightMoves[5].moves[num-1].column + 2;
                                            eightMoves[5].numCap++;
                                            temp6[eightMoves[5].moves[num-1].row - 1][eightMoves[5].moves[num-1].column + 1] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[5].moves.push_back(dummy);
                                            eightMoves[5].moves[num].row = eightMoves[5].moves[num-1].row;
                                            eightMoves[5].moves[num].column = eightMoves[5].moves[num-1].column + 2;
                                            eightMoves[5].numCap++;
                                            temp6[eightMoves[5].moves[num-1].row][eightMoves[5].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM RIGHT
                                        if (count4 == randomNumber)
                                        {
                                            eightMoves[5].moves.push_back(dummy);
                                            eightMoves[5].moves[num].row = eightMoves[5].moves[num-1].row + 2;
                                            eightMoves[5].moves[num].column = eightMoves[5].moves[num-1].column + 2;
                                            eightMoves[5].numCap++;
                                            temp6[eightMoves[5].moves[num-1].row + 1][eightMoves[5].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[5].moves.push_back(dummy);
                                            eightMoves[5].moves[num].row = eightMoves[5].moves[num-1].row + 2;
                                            eightMoves[5].moves[num].column = eightMoves[5].moves[num-1].column;
                                            eightMoves[5].numCap++;
                                            temp6[eightMoves[5].moves[num-1].row + 1][eightMoves[5].moves[num-1].column] = '.';
                                        }
                                        // BOTTOM LEFT
                                        if (count6 == randomNumber)
                                        {
                                            eightMoves[5].moves.push_back(dummy);
                                            eightMoves[5].moves[num].row = eightMoves[5].moves[num-1].row + 2;
                                            eightMoves[5].moves[num].column = eightMoves[5].moves[num-1].column - 2;
                                            eightMoves[5].numCap++;
                                            temp6[eightMoves[5].moves[num-1].row + 1][eightMoves[5].moves[num-1].column - 1] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[5].moves.push_back(dummy);
                                            eightMoves[5].moves[num].row = eightMoves[5].moves[num-1].row;
                                            eightMoves[5].moves[num].column = eightMoves[5].moves[num-1].column - 2;
                                            eightMoves[5].numCap++;
                                            temp6[eightMoves[5].moves[num-1].row][eightMoves[5].moves[num-1].column - 1] = '.';
                                        }
                                        // UP LEFT
                                        if (count8 == randomNumber)
                                        {
                                            eightMoves[5].moves.push_back(dummy);
                                            eightMoves[5].moves[num].row = eightMoves[5].moves[num-1].row - 2;
                                            eightMoves[5].moves[num].column = eightMoves[5].moves[num-1].column - 2;
                                            eightMoves[5].numCap++;
                                            temp6[eightMoves[5].moves[num-1].row - 1][eightMoves[5].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[5].theBoard[s][w] = temp6[s][w];
                                    }
                                    else
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 3)
                                            && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 4) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 2)
                                            && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 4)
                                            && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 1)
                                            && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 6)
                                            && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 1)
                                            && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 6))
                                            {
                                                if (((temp6[eightMoves[5].moves[num-1].row - 1][eightMoves[5].moves[num-1].column] == 'S') && (temp6[eightMoves[5].moves[num-1].row - 2][eightMoves[5].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[5].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[5].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK RIGHT
                                        if (!(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 4)
                                                 && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 4)
                                                 && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 6)
                                                 && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 6)
                                                 && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 6)
                                                 && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 3)
                                                 && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 4))
                                                 {
                                                    if ((temp6[eightMoves[5].moves[num-1].row][eightMoves[5].moves[num-1].column + 1] == 'S') && (temp6[eightMoves[5].moves[num-1].row][eightMoves[5].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[5].moves[num-1].row;
                                                        thirdIt.column = eightMoves[5].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 1)
                                                && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 6)
                                                && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 1)
                                                && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 5) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 6)
                                                && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 3)
                                                && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 4) && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 2)
                                                && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 3) && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 4))
                                                {
                                                    if ((temp6[eightMoves[5].moves[num-1].row + 1][eightMoves[5].moves[num-1].column] == 'S') && (temp6[eightMoves[5].moves[num-1].row + 2][eightMoves[5].moves[num-1].column] == '.'))
                                                    {

                                                        fifthIt.row = eightMoves[5].moves[num-1].row + 2;
                                                        fifthIt.column = eightMoves[5].moves[num-1].column;
                                                        randoms++;
                                                        count5 = randoms;
                                                        bottom = true;
                                                    }
                                                }
                                        // CHECK LEFT
                                        if (!(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 0 && eightMoves[5].moves[num-1].column == 3)
                                        && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 1 && eightMoves[5].moves[num-1].column == 3)
                                        && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 2 && eightMoves[5].moves[num-1].column == 1)
                                        && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 3 && eightMoves[5].moves[num-1].column == 1)
                                        && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 0) && !(eightMoves[5].moves[num-1].row == 4 && eightMoves[5].moves[num-1].column == 1)
                                        && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 5 && eightMoves[5].moves[num-1].column == 3)
                                        && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 2) && !(eightMoves[5].moves[num-1].row == 6 && eightMoves[5].moves[num-1].column == 3))
                                        {
                                            if ((temp6[eightMoves[5].moves[num-1].row][eightMoves[5].moves[num-1].column - 1] == 'S') && (temp6[eightMoves[5].moves[num-1].row][eightMoves[5].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[5].moves[num-1].row;
                                                seventhIt.column = eightMoves[5].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        if (up == false && right == false && bottom == false && left == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }


                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[5].moves.push_back(dummy);
                                            eightMoves[5].moves[num].row = eightMoves[5].moves[num-1].row - 2;
                                            eightMoves[5].moves[num].column = eightMoves[5].moves[num-1].column;
                                            eightMoves[5].numCap++;
                                            temp6[eightMoves[5].moves[num-1].row - 1][eightMoves[5].moves[num-1].column] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[5].moves.push_back(dummy);
                                            eightMoves[5].moves[num].row = eightMoves[5].moves[num-1].row;
                                            eightMoves[5].moves[num].column = eightMoves[5].moves[num-1].column + 2;
                                            eightMoves[5].numCap++;
                                            temp6[eightMoves[5].moves[num-1].row][eightMoves[5].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[5].moves.push_back(dummy);
                                            eightMoves[5].moves[num].row = eightMoves[5].moves[num-1].row + 2;
                                            eightMoves[5].moves[num].column = eightMoves[5].moves[num-1].column;
                                            eightMoves[5].numCap++;
                                            temp6[eightMoves[5].moves[num-1].row + 1][eightMoves[5].moves[num-1].column] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[5].moves.push_back(dummy);
                                            eightMoves[5].moves[num].row = eightMoves[5].moves[num-1].row;
                                            eightMoves[5].moves[num].column = eightMoves[5].moves[num-1].column - 2;
                                            eightMoves[5].numCap++;
                                            temp6[eightMoves[5].moves[num-1].row][eightMoves[5].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[5].theBoard[s][w] = temp6[s][w];
                                    }
                                }

                            }
                        }
                    areWeThereYet = false;
                    // CHECK LEFT
                    if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3))
                        {
                            if ((temp7[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] == 'S') && (temp7[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 2] == '.'))
                            {
                                bool up, upRight, right, bottomRight, bottom, bottomLeft, left, upLeft;
                                eightMoves[6].numCap++;
                                eightMoves[6].moves[0].row = foxObjects[foxNum].rowCo;
                                eightMoves[6].moves[0].column = foxObjects[foxNum].colCo - 2;

                                temp7[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] = '.';
                                temp7[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                                for (int c = 0; c < 7; c++)
                                    for (int d = 0; d < 7; d++)
                                        eightMoves[6].theBoard[c][d] = temp7[c][d];
                                //resetBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';
                                for (int num = 1; num < 8 && areWeThereYet == false; num++)
                                {
                                    randoms = 0;
                                    count1 = 0;
                                    count2 = 0;
                                    count3 = 0;
                                    count4 = 0;
                                    count5 = 0;
                                    count6 = 0;
                                    count7 = 0;
                                    count8 = 0;
                                    up = false;
                                    upRight = false;
                                    right = false;
                                    bottomRight = false;
                                    bottom = false;
                                    bottomLeft = false;
                                    left = false;
                                    upLeft = false;
                                    if ((eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) || (eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) || (eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4)
                                    || (eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) || (eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 2) || (eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                    || (eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) || (eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 4) || (eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 3)
                                    || (eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 2) || (eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6) || (eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5)
                                    || (eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 4) || (eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3) || (eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2)
                                    || (eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6) || (eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                            && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2)
                                            && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                            && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                            && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6)
                                            && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                            && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 6))
                                            {
                                                if (((temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column] == 'S') && (temp7[eightMoves[6].moves[num-1].row - 2][eightMoves[6].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[6].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[6].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;

                                                }
                                            }
                                        // CHECK UP RIGHT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 4)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 4)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 4)
                                                && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                                {
                                                    if (((temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column + 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row - 2][eightMoves[6].moves[num-1].column + 2] == '.'))/* && fromTop == true*/)
                                                    {

                                                        secondIt.row = eightMoves[6].moves[num-1].row - 2;
                                                        secondIt.column = eightMoves[6].moves[num-1].column + 2;
                                                        randoms++;
                                                        count2 = randoms;
                                                        upRight = true;
                                                    }
                                                }

                                        // CHECK RIGHT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4)
                                                 && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                                 && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6)
                                                 && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                                 && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6)
                                                 && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                                 && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                                 {
                                                    if ((temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column + 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[6].moves[num-1].row;
                                                        thirdIt.column = eightMoves[6].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM RIGHT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 4)
                                                && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4))
                                                {
                                                    if ((temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column + 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row + 2][eightMoves[6].moves[num-1].column + 2] == '.'))
                                                    {
                                                        fourthIt.row = eightMoves[6].moves[num-1].row + 2;
                                                        fourthIt.column = eightMoves[6].moves[num-1].column + 2;
                                                        randoms++;
                                                        count4 = randoms;
                                                        bottomRight = true;
                                                    }
                                                }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                                {
                                                    if ((temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column] == 'S') && (temp7[eightMoves[6].moves[num-1].row + 2][eightMoves[6].moves[num-1].column] == '.'))
                                                    {

                                                        fifthIt.row = eightMoves[6].moves[num-1].row + 2;
                                                        fifthIt.column = eightMoves[6].moves[num-1].column;
                                                        randoms++;
                                                        count5 = randoms;
                                                        bottom = true;
                                                    }
                                                }
                                        // CHECK BOTTOM LEFT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                                {
                                                    if ((temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column - 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row + 2][eightMoves[6].moves[num-1].column - 2] == '.'))
                                                    {
                                                        sixthIt.row = eightMoves[4].moves[num-1].row + 2;
                                                        sixthIt.column = eightMoves[4].moves[num-1].column - 2;
                                                        randoms++;
                                                        count6 = randoms;
                                                        bottomLeft = true;
                                                    }
                                                }
                                        // CHECK LEFT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3))
                                        {
                                            if ((temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column - 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[6].moves[num-1].row;
                                                seventhIt.column = eightMoves[6].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        // CHECK UPPER LEFT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2)
                                        && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                        && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6)
                                        && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                        && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5)
                                        && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 4)
                                        && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3))
                                        {
                                            if ((temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column  - 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row - 2][eightMoves[6].moves[num-1].column - 2] == '.'))
                                            {
                                                eigthIt.row = eightMoves[6].moves[num-1].row - 2;
                                                eigthIt.column = eightMoves[6].moves[num-1].column  - 2;
                                                randoms++;
                                                count8 = randoms;
                                                upLeft = true;
                                            }
                                        }
                                        if (up == false && upRight == false && right == false && bottomRight == false && bottom == false && bottomLeft == false && left == false && upLeft == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }



                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row - 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column] = '.';
                                        }
                                        // UP RIGHT
                                        if (count2 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row - 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column + 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column + 1] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column + 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM RIGHT
                                        if (count4 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row + 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column + 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row + 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column] = '.';
                                        }
                                        // BOTTOM LEFT
                                        if (count6 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row + 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column - 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column - 1] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column - 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column - 1] = '.';
                                        }
                                        // UP LEFT
                                        if (count8 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row - 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column - 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[6].theBoard[s][w] = temp7[s][w];
                                    }
                                    else
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                            && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2)
                                            && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                            && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                            && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6)
                                            && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                            && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 6))
                                            {
                                                if (((temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column] == 'S') && (temp7[eightMoves[6].moves[num-1].row - 2][eightMoves[6].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[6].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[6].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK RIGHT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4)
                                                 && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                                 && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6)
                                                 && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                                 && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6)
                                                 && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                                 && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                                 {
                                                    if ((temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column + 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[6].moves[num-1].row;
                                                        thirdIt.column = eightMoves[6].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                                {
                                                    if ((temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column] == 'S') && (temp7[eightMoves[6].moves[num-1].row + 2][eightMoves[6].moves[num-1].column] == '.'))
                                                    {

                                                        fifthIt.row = eightMoves[6].moves[num-1].row + 2;
                                                        fifthIt.column = eightMoves[6].moves[num-1].column;
                                                        randoms++;
                                                        count5 = randoms;
                                                        bottom = true;
                                                    }
                                                }
                                        // CHECK LEFT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3))
                                        {
                                            if ((temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column - 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[6].moves[num-1].row;
                                                seventhIt.column = eightMoves[6].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        if (up == false && right == false && bottom == false && left == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }


                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row - 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column + 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row + 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column - 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[6].theBoard[s][w] = temp7[s][w];
                                    }
                                }

                            }
                        }
                    areWeThereYet = false;
                    // CHECK UPPER LEFT
                    if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3))
                        {
                            if ((temp8[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo - 1] == 'S') && (temp8[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo - 2] == '.'))
                            {
                                bool up, upRight, right, bottomRight, bottom, bottomLeft, left, upLeft;
                                eightMoves[7].numCap++;
                                eightMoves[7].moves[0].row = foxObjects[foxNum].rowCo - 2;
                                eightMoves[7].moves[0].column = foxObjects[foxNum].colCo - 2;
                                temp8[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo - 1] = '.';
                                temp8[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                                for (int c = 0; c < 7; c++)
                                    for (int d = 0; d < 7; d++)
                                        eightMoves[7].theBoard[c][d] = temp8[c][d];
                                //resetBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';
                                for (int num = 1; num < 8 && areWeThereYet == false; num++)
                                {

                                    randoms = 0;
                                    count1 = 0;
                                    count2 = 0;
                                    count3 = 0;
                                    count4 = 0;
                                    count5 = 0;
                                    count6 = 0;
                                    count7 = 0;
                                    count8 = 0;
                                    up = false;
                                    upRight = false;
                                    right = false;
                                    bottomRight = false;
                                    bottom = false;
                                    bottomLeft = false;
                                    left = false;
                                    upLeft = false;
                                    if ((eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 2) || (eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 0) || (eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 4)
                                    || (eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 3) || (eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 2) || (eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 1)
                                    || (eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 0) || (eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 4) || (eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 3)
                                    || (eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 2) || (eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 6) || (eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 5)
                                    || (eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 4) || (eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 3) || (eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 2)
                                    || (eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 6) || (eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 4))
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 3)
                                            && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 4) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 2)
                                            && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 4)
                                            && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 1)
                                            && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 6)
                                            && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 1)
                                            && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 6))
                                            {
                                                if (((temp8[eightMoves[7].moves[num-1].row - 1][eightMoves[7].moves[num-1].column] == 'S') && (temp8[eightMoves[7].moves[num-1].row - 2][eightMoves[7].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[7].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[7].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;

                                                }
                                            }
                                        // CHECK UP RIGHT
                                        if (!(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 4) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 2)
                                                && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 4)
                                                && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 4)
                                                && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 6)
                                                && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 2)
                                                && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 4)
                                                && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 6)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 1) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 6)
                                                && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 4)
                                                && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 4))
                                                {
                                                    if (((temp8[eightMoves[7].moves[num-1].row - 1][eightMoves[7].moves[num-1].column + 1] == 'S') && (temp8[eightMoves[7].moves[num-1].row - 2][eightMoves[7].moves[num-1].column + 2] == '.'))/* && fromTop == true*/)
                                                    {

                                                        secondIt.row = eightMoves[7].moves[num-1].row - 2;
                                                        secondIt.column = eightMoves[7].moves[num-1].column + 2;
                                                        randoms++;
                                                        count2 = randoms;
                                                        upRight = true;
                                                    }
                                                }

                                        // CHECK RIGHT
                                        if (!(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 4)
                                                 && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 4)
                                                 && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 6)
                                                 && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 6)
                                                 && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 6)
                                                 && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 3)
                                                 && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 4))
                                                 {
                                                    if ((temp8[eightMoves[7].moves[num-1].row][eightMoves[7].moves[num-1].column + 1] == 'S') && (temp8[eightMoves[7].moves[num-1].row][eightMoves[7].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[7].moves[num-1].row;
                                                        thirdIt.column = eightMoves[7].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM RIGHT
                                        if (!(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 2)
                                                && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 4) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 5)
                                                && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 6) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 0)
                                                && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 4) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 5)
                                                && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 6) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 0)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 1) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 4) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 5)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 6) && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 2)
                                                && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 4)
                                                && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 4) && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 4))
                                                {
                                                    if ((temp8[eightMoves[7].moves[num-1].row + 1][eightMoves[7].moves[num-1].column + 1] == 'S') && (temp8[eightMoves[7].moves[num-1].row + 2][eightMoves[7].moves[num-1].column + 2] == '.'))
                                                    {
                                                        fourthIt.row = eightMoves[7].moves[num-1].row + 2;
                                                        fourthIt.column = eightMoves[7].moves[num-1].column + 2;
                                                        randoms++;
                                                        count4 = randoms;
                                                        bottomRight = true;
                                                    }
                                                }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 6)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 6)
                                                && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 4) && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 2)
                                                && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 4))
                                                {
                                                    if ((temp8[eightMoves[7].moves[num-1].row + 1][eightMoves[7].moves[num-1].column] == 'S') && (temp8[eightMoves[7].moves[num-1].row + 2][eightMoves[7].moves[num-1].column] == '.'))
                                                    {

                                                        fifthIt.row = eightMoves[7].moves[num-1].row + 2;
                                                        fifthIt.column = eightMoves[7].moves[num-1].column;
                                                        randoms++;
                                                        count5 = randoms;
                                                        bottom = true;
                                                    }
                                                }
                                        // CHECK BOTTOM LEFT
                                        if (!(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 4)
                                                && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 5)
                                                && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 4) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 6)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 6)
                                                && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 4) && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 2)
                                                && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 4))
                                                {
                                                    if ((temp8[eightMoves[7].moves[num-1].row + 1][eightMoves[7].moves[num-1].column - 1] == 'S') && (temp8[eightMoves[7].moves[num-1].row + 2][eightMoves[7].moves[num-1].column - 2] == '.'))
                                                    {
                                                        sixthIt.row = eightMoves[4].moves[num-1].row + 2;
                                                        sixthIt.column = eightMoves[4].moves[num-1].column - 2;
                                                        randoms++;
                                                        count6 = randoms;
                                                        bottomLeft = true;
                                                    }
                                                }
                                        // CHECK LEFT
                                        if (!(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 3))
                                                {
                                                    if ((temp8[eightMoves[7].moves[num-1].row][eightMoves[7].moves[num-1].column - 1] == 'S') && (temp8[eightMoves[7].moves[num-1].row][eightMoves[7].moves[num-1].column - 2] == '.'))
                                                    {

                                                        seventhIt.row = eightMoves[7].moves[num-1].row;
                                                        seventhIt.column = eightMoves[7].moves[num-1].column - 2;
                                                        randoms++;
                                                        count7 = randoms;
                                                        left = true;
                                                    }
                                                }
                                        // CHECK UPPER LEFT
                                        if (!(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 3)
                                        && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 4) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 2)
                                        && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 4)
                                        && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 1)
                                        && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 3)
                                        && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 6)
                                        && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 1)
                                        && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 3)
                                        && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 4) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 6)
                                        && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 1)
                                        && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 5)
                                        && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 4)
                                        && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 3))
                                        {
                                            if ((temp8[eightMoves[7].moves[num-1].row - 1][eightMoves[7].moves[num-1].column  - 1] == 'S') && (temp8[eightMoves[7].moves[num-1].row - 2][eightMoves[7].moves[num-1].column - 2] == '.'))
                                            {
                                                eigthIt.row = eightMoves[7].moves[num-1].row - 2;
                                                eigthIt.column = eightMoves[7].moves[num-1].column  - 2;
                                                randoms++;
                                                count8 = randoms;
                                                upLeft = true;
                                            }
                                        }
                                        if (up == false && upRight == false && right == false && bottomRight == false && bottom == false && bottomLeft == false && left == false && upLeft == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }



                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[7].moves.push_back(dummy);
                                            eightMoves[7].moves[num].row = eightMoves[7].moves[num-1].row - 2;
                                            eightMoves[7].moves[num].column = eightMoves[7].moves[num-1].column;
                                            eightMoves[7].numCap++;
                                            temp8[eightMoves[7].moves[num-1].row - 1][eightMoves[7].moves[num-1].column] = '.';
                                        }
                                        // UP RIGHT
                                        if (count2 == randomNumber)
                                        {
                                            eightMoves[7].moves.push_back(dummy);
                                            eightMoves[7].moves[num].row = eightMoves[7].moves[num-1].row - 2;
                                            eightMoves[7].moves[num].column = eightMoves[7].moves[num-1].column + 2;
                                            eightMoves[7].numCap++;
                                            temp8[eightMoves[7].moves[num-1].row - 1][eightMoves[7].moves[num-1].column + 1] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[7].moves.push_back(dummy);
                                            eightMoves[7].moves[num].row = eightMoves[7].moves[num-1].row;
                                            eightMoves[7].moves[num].column = eightMoves[7].moves[num-1].column + 2;
                                            eightMoves[7].numCap++;
                                            temp8[eightMoves[7].moves[num-1].row][eightMoves[7].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM RIGHT
                                        if (count4 == randomNumber)
                                        {
                                            eightMoves[7].moves.push_back(dummy);
                                            eightMoves[7].moves[num].row = eightMoves[7].moves[num-1].row + 2;
                                            eightMoves[7].moves[num].column = eightMoves[7].moves[num-1].column + 2;
                                            eightMoves[7].numCap++;
                                            temp8[eightMoves[7].moves[num-1].row + 1][eightMoves[7].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[7].moves.push_back(dummy);
                                            eightMoves[7].moves[num].row = eightMoves[7].moves[num-1].row + 2;
                                            eightMoves[7].moves[num].column = eightMoves[7].moves[num-1].column;
                                            eightMoves[7].numCap++;
                                            temp8[eightMoves[7].moves[num-1].row + 1][eightMoves[7].moves[num-1].column] = '.';
                                        }
                                        // BOTTOM LEFT
                                        if (count6 == randomNumber)
                                        {
                                            eightMoves[7].moves.push_back(dummy);
                                            eightMoves[7].moves[num].row = eightMoves[7].moves[num-1].row + 2;
                                            eightMoves[7].moves[num].column = eightMoves[7].moves[num-1].column - 2;
                                            eightMoves[7].numCap++;
                                            temp8[eightMoves[7].moves[num-1].row + 1][eightMoves[7].moves[num-1].column - 1] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[7].moves.push_back(dummy);
                                            eightMoves[7].moves[num].row = eightMoves[7].moves[num-1].row;
                                            eightMoves[7].moves[num].column = eightMoves[7].moves[num-1].column - 2;
                                            eightMoves[7].numCap++;
                                            temp8[eightMoves[7].moves[num-1].row][eightMoves[7].moves[num-1].column - 1] = '.';
                                        }
                                        // UP LEFT
                                        if (count8 == randomNumber)
                                        {
                                            eightMoves[7].moves.push_back(dummy);
                                            eightMoves[7].moves[num].row = eightMoves[7].moves[num-1].row - 2;
                                            eightMoves[7].moves[num].column = eightMoves[7].moves[num-1].column - 2;
                                            eightMoves[7].numCap++;
                                            temp8[eightMoves[7].moves[num-1].row - 1][eightMoves[7].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[7].theBoard[s][w] = temp8[s][w];
                                    }
                                    else
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 3)
                                            && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 4) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 2)
                                            && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 4)
                                            && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 1)
                                            && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 6)
                                            && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 1)
                                            && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 6))
                                            {
                                                if (((temp8[eightMoves[7].moves[num-1].row - 1][eightMoves[7].moves[num-1].column] == 'S') && (temp8[eightMoves[7].moves[num-1].row - 2][eightMoves[7].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[7].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[7].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK RIGHT
                                        if (!(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 4)
                                                 && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 4)
                                                 && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 6)
                                                 && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 6)
                                                 && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 6)
                                                 && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 3)
                                                 && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 4))
                                                 {
                                                    if ((temp8[eightMoves[7].moves[num-1].row][eightMoves[7].moves[num-1].column + 1] == 'S') && (temp8[eightMoves[7].moves[num-1].row][eightMoves[7].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[7].moves[num-1].row;
                                                        thirdIt.column = eightMoves[7].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 6)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 5) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 6)
                                                && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 4) && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 2)
                                                && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 3) && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 4))
                                                {
                                                    if ((temp8[eightMoves[7].moves[num-1].row + 1][eightMoves[7].moves[num-1].column] == 'S') && (temp8[eightMoves[7].moves[num-1].row + 2][eightMoves[7].moves[num-1].column] == '.'))
                                                    {

                                                        fifthIt.row = eightMoves[7].moves[num-1].row + 2;
                                                        fifthIt.column = eightMoves[7].moves[num-1].column;
                                                        randoms++;
                                                        count5 = randoms;
                                                        bottom = true;
                                                    }
                                                }
                                        // CHECK LEFT
                                        if (!(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 0 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 1 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 2 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 3 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 0) && !(eightMoves[7].moves[num-1].row == 4 && eightMoves[7].moves[num-1].column == 1)
                                                && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 5 && eightMoves[7].moves[num-1].column == 3)
                                                && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 2) && !(eightMoves[7].moves[num-1].row == 6 && eightMoves[7].moves[num-1].column == 3))
                                                {
                                                    if ((temp8[eightMoves[7].moves[num-1].row][eightMoves[7].moves[num-1].column - 1] == 'S') && (temp8[eightMoves[7].moves[num-1].row][eightMoves[7].moves[num-1].column - 2] == '.'))
                                                    {

                                                        seventhIt.row = eightMoves[7].moves[num-1].row;
                                                        seventhIt.column = eightMoves[7].moves[num-1].column - 2;
                                                        randoms++;
                                                        count7 = randoms;
                                                        left = true;
                                                    }
                                                }
                                        if (up == false && right == false && bottom == false && left == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }


                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[7].moves.push_back(dummy);
                                            eightMoves[7].moves[num].row = eightMoves[7].moves[num-1].row - 2;
                                            eightMoves[7].moves[num].column = eightMoves[7].moves[num-1].column;
                                            eightMoves[7].numCap++;
                                            temp8[eightMoves[7].moves[num-1].row - 1][eightMoves[7].moves[num-1].column] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[7].moves.push_back(dummy);
                                            eightMoves[7].moves[num].row = eightMoves[7].moves[num-1].row;
                                            eightMoves[7].moves[num].column = eightMoves[7].moves[num-1].column + 2;
                                            eightMoves[7].numCap++;
                                            temp8[eightMoves[7].moves[num-1].row][eightMoves[7].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[7].moves.push_back(dummy);
                                            eightMoves[7].moves[num].row = eightMoves[7].moves[num-1].row + 2;
                                            eightMoves[7].moves[num].column = eightMoves[7].moves[num-1].column;
                                            eightMoves[7].numCap++;
                                            temp8[eightMoves[7].moves[num-1].row + 1][eightMoves[7].moves[num-1].column] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[7].moves.push_back(dummy);
                                            eightMoves[7].moves[num].row = eightMoves[7].moves[num-1].row;
                                            eightMoves[7].moves[num].column = eightMoves[7].moves[num-1].column - 2;
                                            eightMoves[7].numCap++;
                                            temp8[eightMoves[7].moves[num-1].row][eightMoves[7].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[7].theBoard[s][w] = temp8[s][w];
                                    }
                                }

                            }
                        }
                    // FINAL COMPARISON TO SEE WHICH MOVE SET HAS THE MOST CAPTURING MOVES
                    int highCap = -1;
                    for (int col = 0; col < 8; col++)
                    {
                        if(eightMoves[col].numCap > highCap)
                            highCap = eightMoves[col].numCap;
                    }
                    int var = 0;
                    for (int u = 0; u < 8; u++)
                    {
                        if (eightMoves[u].numCap == highCap)
                        {
                            var = eightMoves[u].moves.size() - 1;
                            foxObjects[foxNum].finalRow = eightMoves[u].moves[var].row;
                            foxObjects[foxNum].finalColumn = eightMoves[u].moves[var].column;
                            foxObjects[foxNum].numCaptured = highCap;
                            for (int theRow = 0; theRow < 7; theRow++)
                                for (int theColumn = 0; theColumn < 7; theColumn++)
                                    foxObjects[foxNum].tempBoard[theRow][theColumn] = eightMoves[u].theBoard[theRow][theColumn];

                            foxObjects[foxNum].tempBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                            foxObjects[foxNum].tempBoard[foxObjects[foxNum].finalRow][foxObjects[foxNum].finalColumn] = 'F';
                        }
                    }

                    // CHECK TO SEE IF NONE OF THE ABOVE DIRECTIONS (CROSS) YIELDED A MOVE TO PRODUCE A RANDOM MOVE
                    if (!((gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] == 'S') && (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo] == '.'))
                        && !((gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo + 1] == 'S') && (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo + 2] == '.'))
                        && !((gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] == 'S') && (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 2] == '.'))
                        && !((gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo + 1] == 'S') && (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo + 2] == '.'))
                        && !((gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] == 'S') && (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo] == '.'))
                        && !((gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo - 1] == 'S') && (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo - 2] == '.'))
                        && !((gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] == 'S') && (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 2] == '.'))
                        && !((gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo - 1] == 'S') && (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo - 2] == '.')))
                        {
                            notNearASheep = true;
                        }

                }
                else if ((foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3) || (foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2) || (foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                         || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1) || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 3) || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5)
                         || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 2) || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 4)
                         || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6) || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1) || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 3)
                         || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) || (foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) || (foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4)
                         || (foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3))
                {
                    areWeThereYet = false;
                    // CHECK UP
                    if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 6))
                        {
                            if ((temp1[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] == 'S') && (temp1[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo] == '.'))
                            {
                                bool up, upRight, right, bottomRight, bottom, bottomLeft, left, upLeft;
                                eightMoves[0].numCap++;
                                eightMoves[0].moves[0].row = foxObjects[foxNum].rowCo - 2;
                                eightMoves[0].moves[0].column = foxObjects[foxNum].colCo;
                                temp1[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';
                                temp1[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                                for (int c = 0; c < 7; c++)
                                    for (int d = 0; d < 7; d++)
                                        eightMoves[0].theBoard[c][d] = temp1[c][d];
                                //resetBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';
                                for (int num = 1; num < 8 && areWeThereYet == false; num++)
                                {

                                    randoms = 0;
                                    count1 = 0;
                                    count2 = 0;
                                    count3 = 0;
                                    count4 = 0;
                                    count5 = 0;
                                    count6 = 0;
                                    count7 = 0;
                                    count8 = 0;
                                    up = false;
                                    upRight = false;
                                    right = false;
                                    bottomRight = false;
                                    bottom = false;
                                    bottomLeft = false;
                                    left = false;
                                    upLeft = false;
                                    if ((eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) || (eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) || (eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4)
                                    || (eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) || (eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 2) || (eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                    || (eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) || (eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 4) || (eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 3)
                                    || (eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 2) || (eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6) || (eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5)
                                    || (eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 4) || (eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3) || (eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2)
                                    || (eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6) || (eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                    {
                                        // CHECK UP
                                        /*for (int z = 0; z < 7; z++)
                                            for (int c = 0; c < 7; c++)
                                            {
                                                temp1[z][c] = resetBoard[z][c];
                                            }*/
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                            && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2)
                                            && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                            && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                            && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6)
                                            && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                            && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 6))
                                            {
                                                if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[0].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[0].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }

                                        // CHECK UP RIGHT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                        {
                                            if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column + 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column + 2] == '.'))/* && fromTop == true*/)
                                            {

                                                secondIt.row = eightMoves[0].moves[num-1].row - 2;
                                                secondIt.column = eightMoves[0].moves[num-1].column + 2;
                                                randoms++;
                                                count2 = randoms;
                                                upRight = true;
                                            }
                                        }

                                        // CHECK RIGHT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4)
                                         && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                         && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6)
                                         && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                         && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6)
                                         && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                         && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                         {
                                            if ((temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column + 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column + 2] == '.'))
                                            {

                                                thirdIt.row = eightMoves[0].moves[num-1].row;
                                                thirdIt.column = eightMoves[0].moves[num-1].column + 2;
                                                randoms++;
                                                count3 = randoms;
                                                right = true;
                                            }
                                         }
                                        // CHECK BOTTOM RIGHT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column + 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row + 2][eightMoves[0].moves[num-1].column + 2] == '.'))
                                            {
                                                fourthIt.row = eightMoves[0].moves[num-1].row + 2;
                                                fourthIt.column = eightMoves[0].moves[num-1].column + 2;
                                                randoms++;
                                                count4 = randoms;
                                                bottomRight = true;
                                            }
                                        }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row + 2][eightMoves[0].moves[num-1].column] == '.'))
                                            {

                                                fifthIt.row = eightMoves[0].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[0].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK BOTTOM LEFT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column - 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row + 2][eightMoves[0].moves[num-1].column - 2] == '.'))
                                            {
                                                sixthIt.row = eightMoves[0].moves[num-1].row + 2;
                                                sixthIt.column = eightMoves[0].moves[num-1].column - 2;
                                                randoms++;
                                                count6 = randoms;
                                                bottomLeft = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column - 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[0].moves[num-1].row;
                                                seventhIt.column = eightMoves[0].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        // CHECK UPPER LEFT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 4)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column  - 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column - 2] == '.'))
                                            {
                                                eigthIt.row = eightMoves[0].moves[num-1].row - 2;
                                                eigthIt.column = eightMoves[0].moves[num-1].column  - 2;
                                                randoms++;
                                                count8 = randoms;
                                                upLeft = true;
                                            }
                                        }
                                        if (up == false && upRight == false && right == false && bottomRight == false && bottom == false && bottomLeft == false && left == false && upLeft == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }



                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] = '.';

                                        }
                                        // UP RIGHT
                                        if (count2 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column + 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column + 1] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column + 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM RIGHT
                                        if (count4 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row + 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column + 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row + 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column] = '.';
                                        }
                                        // BOTTOM LEFT
                                        if (count6 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row + 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column - 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column - 1] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column - 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column - 1] = '.';
                                        }
                                        // UP LEFT
                                        if (count8 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column - 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[0].theBoard[s][w] = temp1[s][w];
                                    }
                                    else
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                            && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2)
                                            && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                            && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                            && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6)
                                            && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                            && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 6))
                                            {
                                                if (((temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row - 2][eightMoves[0].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[0].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[0].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK RIGHT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 4)
                                         && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 4)
                                         && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 6)
                                         && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                         && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6)
                                         && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                         && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                         {
                                            if ((temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column + 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column + 2] == '.'))
                                            {

                                                thirdIt.row = eightMoves[0].moves[num-1].row;
                                                thirdIt.column = eightMoves[0].moves[num-1].column + 2;
                                                randoms++;
                                                count3 = randoms;
                                                right = true;
                                            }
                                         }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 5) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 6)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 4) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 4))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column] == 'S') && (temp1[eightMoves[0].moves[num-1].row + 2][eightMoves[0].moves[num-1].column] == '.'))
                                            {

                                                fifthIt.row = eightMoves[0].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[0].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 0 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 1 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 2 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 3 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 0) && !(eightMoves[0].moves[num-1].row == 4 && eightMoves[0].moves[num-1].column == 1)
                                        && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 5 && eightMoves[0].moves[num-1].column == 3)
                                        && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 2) && !(eightMoves[0].moves[num-1].row == 6 && eightMoves[0].moves[num-1].column == 3))
                                        {
                                            if ((temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column - 1] == 'S') && (temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[0].moves[num-1].row;
                                                seventhIt.column = eightMoves[0].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        if (up == false && right == false && bottom == false && left == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }


                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row - 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row - 1][eightMoves[0].moves[num-1].column] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column + 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row + 2;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row + 1][eightMoves[0].moves[num-1].column] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[0].moves.push_back(dummy);
                                            eightMoves[0].moves[num].row = eightMoves[0].moves[num-1].row;
                                            eightMoves[0].moves[num].column = eightMoves[0].moves[num-1].column - 2;
                                            eightMoves[0].numCap++;
                                            temp1[eightMoves[0].moves[num-1].row][eightMoves[0].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[0].theBoard[s][w] = temp1[s][w];
                                    }

                                }

                            }
                        }

                    areWeThereYet = false;
                    // CHECK RIGHT
                    if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                        {
                            if ((temp3[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] == 'S') && (temp3[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 2] == '.'))
                            {
                                bool up, upRight, right, bottomRight, bottom, bottomLeft, left, upLeft;
                                eightMoves[2].numCap++;
                                eightMoves[2].moves[0].row = foxObjects[foxNum].rowCo;
                                eightMoves[2].moves[0].column = foxObjects[foxNum].colCo + 2;
                                temp3[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] = '.';
                                temp3[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                                for (int c = 0; c < 7; c++)
                                    for (int d = 0; d < 7; d++)
                                        eightMoves[2].theBoard[c][d] = temp3[c][d];
                                //resetBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';
                                for (int num = 1; num < 8 && areWeThereYet == false; num++)
                                {

                                    randoms = 0;
                                    count1 = 0;
                                    count2 = 0;
                                    count3 = 0;
                                    count4 = 0;
                                    count5 = 0;
                                    count6 = 0;
                                    count7 = 0;
                                    count8 = 0;
                                    up = false;
                                    upRight = false;
                                    right = false;
                                    bottomRight = false;
                                    bottom = false;
                                    bottomLeft = false;
                                    left = false;
                                    upLeft = false;

                                    if ((eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) || (eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) || (eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4)
                                    || (eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) || (eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 2) || (eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                    || (eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) || (eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 4) || (eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 3)
                                    || (eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 2) || (eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6) || (eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5)
                                    || (eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 4) || (eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3) || (eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2)
                                    || (eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6) || (eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                            && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2)
                                            && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                            && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                            && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6)
                                            && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                            && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 6))
                                            {
                                                if (((temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column] == 'S') && (temp3[eightMoves[2].moves[num-1].row - 2][eightMoves[2].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {
                                                    firstIt.row = eightMoves[2].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[2].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;

                                                }
                                            }
                                        // CHECK UP RIGHT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                                && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2)
                                                && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                                && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                                && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 4)
                                                && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6)
                                                && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 2)
                                                && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 4)
                                                && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                                && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 3)
                                                && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6)
                                                && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 4)
                                                && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                                {
                                                    if (((temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column + 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row - 2][eightMoves[2].moves[num-1].column + 2] == '.'))/* && fromTop == true*/)
                                                    {

                                                        secondIt.row = eightMoves[2].moves[num-1].row - 2;
                                                        secondIt.column = eightMoves[2].moves[num-1].column + 2;
                                                        randoms++;
                                                        count2 = randoms;
                                                        upRight = true;
                                                    }
                                                }

                                        // CHECK RIGHT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4)
                                         && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                         && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6)
                                         && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                         && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6)
                                         && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                         && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                         {
                                            if ((temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 2] == '.'))
                                            {
                                                thirdIt.row = eightMoves[2].moves[num-1].row;
                                                thirdIt.column = eightMoves[2].moves[num-1].column + 2;
                                                randoms++;
                                                count3 = randoms;
                                                right = true;
                                            }
                                         }
                                        // CHECK BOTTOM RIGHT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 4)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column + 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row + 2][eightMoves[2].moves[num-1].column + 2] == '.'))
                                            {
                                                fourthIt.row = eightMoves[2].moves[num-1].row + 2;
                                                fourthIt.column = eightMoves[2].moves[num-1].column + 2;
                                                randoms++;
                                                count4 = randoms;
                                                bottomRight = true;
                                            }
                                        }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column] == 'S') && (temp3[eightMoves[2].moves[num-1].row + 2][eightMoves[2].moves[num-1].column] == '.'))
                                            {
                                                fifthIt.row = eightMoves[2].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[2].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK BOTTOM LEFT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column - 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row + 2][eightMoves[2].moves[num-1].column - 2] == '.'))
                                            {
                                                sixthIt.row = eightMoves[2].moves[num-1].row + 2;
                                                sixthIt.column = eightMoves[2].moves[num-1].column - 2;
                                                randoms++;
                                                count6 = randoms;
                                                bottomLeft = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 2] == '.'))
                                            {
                                                seventhIt.row = eightMoves[2].moves[num-1].row;
                                                seventhIt.column = eightMoves[2].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        // CHECK UPPER LEFT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 4)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column  - 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row - 2][eightMoves[2].moves[num-1].column - 2] == '.'))
                                            {
                                                eigthIt.row = eightMoves[2].moves[num-1].row - 2;
                                                eigthIt.column = eightMoves[2].moves[num-1].column  - 2;
                                                randoms++;
                                                count8 = randoms;
                                                upLeft = true;
                                            }
                                        }
                                        if (up == false && upRight == false && right == false && bottomRight == false && bottom == false && bottomLeft == false && left == false && upLeft == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }



                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row - 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column] = '.';
                                        }
                                        // UP RIGHT
                                        if (count2 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row - 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column + 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column + 1] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column + 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM RIGHT
                                        if (count4 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row + 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column + 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row + 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column] = '.';
                                        }
                                        // BOTTOM LEFT
                                        if (count6 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row + 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column - 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[1].moves[num-1].row + 1][eightMoves[2].moves[num-1].column - 1] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column - 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 1] = '.';
                                        }
                                        // UP LEFT
                                        if (count8 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row - 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column - 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[2].theBoard[s][w] = temp3[s][w];
                                    }
                                    else /*if ((eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3) || (eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2) || (eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                         || (eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1) || (eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 3) || (eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5)
                                         || (eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) || (eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 2) || (eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 4)
                                         || (eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6) || (eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1) || (eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 3)
                                         || (eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5) || (eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) || (eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 4)
                                         || (eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3))*/
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                            && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2)
                                            && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                            && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                            && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6)
                                            && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                            && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 6))
                                            {
                                                if (((temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column] == 'S') && (temp3[eightMoves[2].moves[num-1].row - 2][eightMoves[2].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[2].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[2].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK RIGHT
                                        // HERE IT IS

                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 4)
                                                 && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 4)
                                                 && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 6)
                                                 && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                                 && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6)
                                                 && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                                 && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                                 {
                                                    if ((temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 2] == '.'))
                                                    {
                                                        thirdIt.row = eightMoves[2].moves[num-1].row;
                                                        thirdIt.column = eightMoves[2].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 5) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 6)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 4) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 4))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column] == 'S') && (temp3[eightMoves[2].moves[num-1].row + 2][eightMoves[2].moves[num-1].column] == '.'))
                                            {
                                                fifthIt.row = eightMoves[2].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[2].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 0 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 1 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 2 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 3 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 0) && !(eightMoves[2].moves[num-1].row == 4 && eightMoves[2].moves[num-1].column == 1)
                                        && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 5 && eightMoves[2].moves[num-1].column == 3)
                                        && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 2) && !(eightMoves[2].moves[num-1].row == 6 && eightMoves[2].moves[num-1].column == 3))
                                        {
                                            if ((temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 2] == '.'))
                                            {
                                                seventhIt.row = eightMoves[2].moves[num-1].row;
                                                seventhIt.column = eightMoves[2].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        if (/*/!((temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 2] == '.'))
                                            && !((temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column] == 'S') && (temp3[eightMoves[2].moves[num-1].row + 2][eightMoves[2].moves[num-1].column] == '.'))
                                            && !((temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 1] == 'S') && (temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 2] == '.'))
                                            && !((temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column] == 'S') && (temp3[eightMoves[2].moves[num-1].row - 2][eightMoves[2].moves[num-1].column] == '.'))*/
                                            up == false && right == false && bottom == false && left == false)
                                            {
                                                areWeThereYet = true;
                                                break;
                                            }


                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row - 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row - 1][eightMoves[2].moves[num-1].column] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column + 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row + 2;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row + 1][eightMoves[2].moves[num-1].column] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[2].moves.push_back(dummy);
                                            eightMoves[2].moves[num].row = eightMoves[2].moves[num-1].row;
                                            eightMoves[2].moves[num].column = eightMoves[2].moves[num-1].column - 2;
                                            eightMoves[2].numCap++;
                                            temp3[eightMoves[2].moves[num-1].row][eightMoves[2].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[2].theBoard[s][w] = temp3[s][w];
                                    }
                                }

                            }
                        }

                    areWeThereYet = false;
                    // CHECK BOTTOM
                    if (!(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                        {
                            if ((temp5[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] == 'S') && (temp5[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo] == '.'))
                            {
                                bool up, upRight, right, bottomRight, bottom, bottomLeft, left, upLeft;
                                eightMoves[4].numCap++;
                                eightMoves[4].moves[0].row = foxObjects[foxNum].rowCo + 2;
                                eightMoves[4].moves[0].column = foxObjects[foxNum].colCo;

                                temp5[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] = '.';
                                temp5[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                                for (int c = 0; c < 7; c++)
                                    for (int d = 0; d < 7; d++)
                                        eightMoves[4].theBoard[c][d] = temp5[c][d];
                                //resetBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';


                                for (int num = 1; num < 8 && areWeThereYet == false; num++)
                                {



                                    randoms = 0;
                                    count1 = 0;
                                    count2 = 0;
                                    count3 = 0;
                                    count4 = 0;
                                    count5 = 0;
                                    count6 = 0;
                                    count7 = 0;
                                    count8 = 0;
                                    up = false;
                                    upRight = false;
                                    right = false;
                                    bottomRight = false;
                                    bottom = false;
                                    bottomLeft = false;
                                    left = false;
                                    upLeft = false;
                                    if ((eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) || (eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) || (eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4)
                                    || (eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) || (eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 2) || (eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                    || (eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) || (eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 4) || (eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 3)
                                    || (eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 2) || (eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6) || (eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5)
                                    || (eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 4) || (eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3) || (eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2)
                                    || (eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6) || (eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                            && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2)
                                            && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                            && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                            && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6)
                                            && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                            && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 6))
                                            {
                                                if (((temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column] == 'S') && (temp5[eightMoves[4].moves[num-1].row - 2][eightMoves[4].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[4].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[4].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;

                                                }
                                            }
                                        // CHECK UP RIGHT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                                && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2)
                                                && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                                && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                                && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 4)
                                                && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6)
                                                && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 2)
                                                && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 4)
                                                && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                                && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 3)
                                                && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6)
                                                && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 4)
                                                && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                                {
                                                    if (((temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column + 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row - 2][eightMoves[4].moves[num-1].column + 2] == '.'))/* && fromTop == true*/)
                                                    {

                                                        secondIt.row = eightMoves[4].moves[num-1].row - 2;
                                                        secondIt.column = eightMoves[4].moves[num-1].column + 2;
                                                        randoms++;
                                                        count2 = randoms;
                                                        upRight = true;
                                                    }
                                                }

                                        // CHECK RIGHT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4)
                                                 && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                                 && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6)
                                                 && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                                 && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6)
                                                 && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                                 && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                                 {
                                                    if ((temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column + 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[4].moves[num-1].row;
                                                        thirdIt.column = eightMoves[4].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM RIGHT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2)
                                                && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                                && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5)
                                                && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0)
                                                && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 3)
                                                && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5)
                                                && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0)
                                                && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 3)
                                                && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5)
                                                && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2)
                                                && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 4)
                                                && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3)
                                                && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4))
                                                {
                                                    if ((temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column + 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row + 2][eightMoves[4].moves[num-1].column + 2] == '.'))
                                                    {
                                                        fourthIt.row = eightMoves[4].moves[num-1].row + 2;
                                                        fourthIt.column = eightMoves[4].moves[num-1].column + 2;
                                                        randoms++;
                                                        count4 = randoms;
                                                        bottomRight = true;
                                                    }
                                                }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2)
                                        && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                        {
                                            if ((temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column] == 'S') && (temp5[eightMoves[4].moves[num-1].row + 2][eightMoves[4].moves[num-1].column] == '.'))
                                            {

                                                fifthIt.row = eightMoves[4].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[4].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK BOTTOM LEFT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2)
                                        && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                        {
                                            if ((temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column - 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row + 2][eightMoves[4].moves[num-1].column - 2] == '.'))
                                            {
                                                sixthIt.row = eightMoves[4].moves[num-1].row + 2;
                                                sixthIt.column = eightMoves[4].moves[num-1].column - 2;
                                                randoms++;
                                                count6 = randoms;
                                                bottomLeft = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3))
                                        {
                                            if ((temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column - 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[4].moves[num-1].row;
                                                seventhIt.column = eightMoves[4].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        // CHECK UPPER LEFT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2)
                                        && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 4)
                                        && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3))
                                        {
                                            if ((temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column  - 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row - 2][eightMoves[4].moves[num-1].column - 2] == '.'))
                                            {
                                                eigthIt.row = eightMoves[4].moves[num-1].row - 2;
                                                eigthIt.column = eightMoves[4].moves[num-1].column  - 2;
                                                randoms++;
                                                count8 = randoms;
                                                upLeft = true;
                                            }
                                        }
                                        if (up == false && upRight == false && right == false && bottomRight == false && bottom == false && bottomLeft == false && left == false && upLeft == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }



                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row - 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column] = '.';
                                        }
                                        // UP RIGHT
                                        if (count2 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row - 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column + 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column + 1] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column + 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM RIGHT
                                        if (count4 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row + 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column + 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row + 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column] = '.';
                                        }
                                        // BOTTOM LEFT
                                        if (count6 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row + 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column - 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column - 1] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column - 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column - 1] = '.';
                                        }
                                        // UP LEFT
                                        if (count8 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row - 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column - 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[4].theBoard[s][w] = temp5[s][w];
                                    }
                                    else
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                            && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2)
                                            && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                            && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                            && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6)
                                            && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                            && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 6))
                                            {
                                                if (((temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column] == 'S') && (temp5[eightMoves[4].moves[num-1].row - 2][eightMoves[4].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[4].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[4].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK RIGHT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 4)
                                                 && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 4)
                                                 && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 6)
                                                 && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                                 && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6)
                                                 && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                                 && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                                 {
                                                    if ((temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column + 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[4].moves[num-1].row;
                                                        thirdIt.column = eightMoves[4].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 5) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 6)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 4) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2)
                                        && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 4))
                                        {
                                            if ((temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column] == 'S') && (temp5[eightMoves[4].moves[num-1].row + 2][eightMoves[4].moves[num-1].column] == '.'))
                                            {

                                                fifthIt.row = eightMoves[4].moves[num-1].row + 2;
                                                fifthIt.column = eightMoves[4].moves[num-1].column;
                                                randoms++;
                                                count5 = randoms;
                                                bottom = true;
                                            }
                                        }
                                        // CHECK LEFT
                                        if (!(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 0 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 1 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 2 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 3 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 0) && !(eightMoves[4].moves[num-1].row == 4 && eightMoves[4].moves[num-1].column == 1)
                                        && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 5 && eightMoves[4].moves[num-1].column == 3)
                                        && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 2) && !(eightMoves[4].moves[num-1].row == 6 && eightMoves[4].moves[num-1].column == 3))
                                        {
                                            if ((temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column - 1] == 'S') && (temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[4].moves[num-1].row;
                                                seventhIt.column = eightMoves[4].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        if (up == false && right == false && bottom == false && left == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }



                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = 0;

                                        randomNumber = (rand()%randoms) + 1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row - 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row - 1][eightMoves[4].moves[num-1].column] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column + 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row + 2;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row + 1][eightMoves[4].moves[num-1].column] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[4].moves.push_back(dummy);
                                            eightMoves[4].moves[num].row = eightMoves[4].moves[num-1].row;
                                            eightMoves[4].moves[num].column = eightMoves[4].moves[num-1].column - 2;
                                            eightMoves[4].numCap++;
                                            temp5[eightMoves[4].moves[num-1].row][eightMoves[4].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[4].theBoard[s][w] = temp5[s][w];
                                    }
                                }


                            }
                        }
                    areWeThereYet = false;
                    // CHECK LEFT
                    if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3))
                        {
                            if ((temp7[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] == 'S') && (temp7[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 2] == '.'))
                            {
                                bool up, upRight, right, bottomRight, bottom, bottomLeft, left, upLeft;
                                eightMoves[6].numCap++;
                                eightMoves[6].moves[0].row = foxObjects[foxNum].rowCo;
                                eightMoves[6].moves[0].column = foxObjects[foxNum].colCo - 2;

                                temp7[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] = '.';
                                temp7[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                                for (int c = 0; c < 7; c++)
                                    for (int d = 0; d < 7; d++)
                                        eightMoves[6].theBoard[c][d] = temp7[c][d];
                                //resetBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] = '.';
                                for (int num = 1; num < 8 && areWeThereYet == false; num++)
                                {



                                    randoms = 0;
                                    count1 = 0;
                                    count2 = 0;
                                    count3 = 0;
                                    count4 = 0;
                                    count5 = 0;
                                    count6 = 0;
                                    count7 = 0;
                                    count8 = 0;
                                    up = false;
                                    upRight = false;
                                    right = false;
                                    bottomRight = false;
                                    bottom = false;
                                    bottomLeft = false;
                                    left = false;
                                    upLeft = false;

                                    if ((eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) || (eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) || (eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4)
                                    || (eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) || (eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 2) || (eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                    || (eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) || (eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 4) || (eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 3)
                                    || (eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 2) || (eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6) || (eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5)
                                    || (eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 4) || (eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3) || (eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2)
                                    || (eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6) || (eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                            && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2)
                                            && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                            && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                            && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6)
                                            && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                            && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 6))
                                            {
                                                if (((temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column] == 'S') && (temp7[eightMoves[6].moves[num-1].row - 2][eightMoves[6].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[6].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[6].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK UP RIGHT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 4)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 4)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 4)
                                                && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                                {
                                                    if (((temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column + 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row - 2][eightMoves[6].moves[num-1].column + 2] == '.'))/* && fromTop == true*/)
                                                    {

                                                        secondIt.row = eightMoves[6].moves[num-1].row - 2;
                                                        secondIt.column = eightMoves[6].moves[num-1].column + 2;
                                                        randoms++;
                                                        count2 = randoms;
                                                        upRight = true;
                                                    }
                                                }

                                        // CHECK RIGHT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4)
                                                 && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                                 && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6)
                                                 && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                                 && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6)
                                                 && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                                 && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                                 {
                                                    if ((temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column + 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[6].moves[num-1].row;
                                                        thirdIt.column = eightMoves[6].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM RIGHT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 4)
                                                && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4))
                                                {
                                                    if ((temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column + 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row + 2][eightMoves[6].moves[num-1].column + 2] == '.'))
                                                    {
                                                        fourthIt.row = eightMoves[6].moves[num-1].row + 2;
                                                        fourthIt.column = eightMoves[6].moves[num-1].column + 2;
                                                        randoms++;
                                                        count4 = randoms;
                                                        bottomRight = true;
                                                    }
                                                }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                                {
                                                    if ((temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column] == 'S') && (temp7[eightMoves[6].moves[num-1].row + 2][eightMoves[6].moves[num-1].column] == '.'))
                                                    {

                                                        fifthIt.row = eightMoves[6].moves[num-1].row + 2;
                                                        fifthIt.column = eightMoves[6].moves[num-1].column;
                                                        randoms++;
                                                        count5 = randoms;
                                                        bottom = true;
                                                    }
                                                }
                                        // CHECK BOTTOM LEFT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                                {
                                                    if ((temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column - 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row + 2][eightMoves[6].moves[num-1].column - 2] == '.'))
                                                    {
                                                        sixthIt.row = eightMoves[4].moves[num-1].row + 2;
                                                        sixthIt.column = eightMoves[4].moves[num-1].column - 2;
                                                        randoms++;
                                                        count6 = randoms;
                                                        bottomLeft = true;
                                                    }
                                                }
                                        // CHECK LEFT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3))
                                        {
                                            if ((temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column - 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[6].moves[num-1].row;
                                                seventhIt.column = eightMoves[6].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        // CHECK UPPER LEFT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2)
                                        && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                        && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6)
                                        && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                        && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5)
                                        && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 4)
                                        && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3))
                                        {
                                            if ((temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column  - 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row - 2][eightMoves[6].moves[num-1].column - 2] == '.'))
                                            {
                                                eigthIt.row = eightMoves[6].moves[num-1].row - 2;
                                                eigthIt.column = eightMoves[6].moves[num-1].column  - 2;
                                                randoms++;
                                                count8 = randoms;
                                                upLeft = true;
                                            }
                                        }
                                        if (up == false && upRight == false && right == false && bottomRight == false && bottom == false && bottomLeft == false && left == false && upLeft == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }



                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row - 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column] = '.';
                                        }
                                        // UP RIGHT
                                        if (count2 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row - 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column + 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column + 1] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column + 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM RIGHT
                                        if (count4 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row + 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column + 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row + 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column] = '.';
                                        }
                                        // BOTTOM LEFT
                                        if (count6 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row + 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column - 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column - 1] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column - 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column - 1] = '.';
                                        }
                                        // UP LEFT
                                        if (count8 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row - 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column - 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[6].theBoard[s][w] = temp7[s][w];
                                    }
                                    else
                                    {
                                        // CHECK UP
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                            && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2)
                                            && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                            && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                            && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6)
                                            && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                            && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 6))
                                            {
                                                if (((temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column] == 'S') && (temp7[eightMoves[6].moves[num-1].row - 2][eightMoves[6].moves[num-1].column] == '.'))/* && fromTop == true*/)
                                                {

                                                    firstIt.row = eightMoves[6].moves[num-1].row - 2;
                                                    firstIt.column = eightMoves[6].moves[num-1].column;
                                                    randoms++;
                                                    count1 = randoms;
                                                    up = true;
                                                }
                                            }
                                        // CHECK RIGHT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 4)
                                                 && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 4)
                                                 && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 6)
                                                 && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                                 && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6)
                                                 && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                                 && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                                 {
                                                    if ((temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column + 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column + 2] == '.'))
                                                    {

                                                        thirdIt.row = eightMoves[6].moves[num-1].row;
                                                        thirdIt.column = eightMoves[6].moves[num-1].column + 2;
                                                        randoms++;
                                                        count3 = randoms;
                                                        right = true;
                                                    }
                                                 }
                                        // CHECK BOTTOM
                                        if (!(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1)
                                                && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 5) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 6)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                                && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 4) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2)
                                                && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 4))
                                                {
                                                    if ((temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column] == 'S') && (temp7[eightMoves[6].moves[num-1].row + 2][eightMoves[6].moves[num-1].column] == '.'))
                                                    {

                                                        fifthIt.row = eightMoves[6].moves[num-1].row + 2;
                                                        fifthIt.column = eightMoves[6].moves[num-1].column;
                                                        randoms++;
                                                        count5 = randoms;
                                                        bottom = true;
                                                    }
                                                }
                                        // CHECK LEFT
                                        if (!(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 0 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 1 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 2 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 3 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 0) && !(eightMoves[6].moves[num-1].row == 4 && eightMoves[6].moves[num-1].column == 1)
                                        && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 5 && eightMoves[6].moves[num-1].column == 3)
                                        && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 2) && !(eightMoves[6].moves[num-1].row == 6 && eightMoves[6].moves[num-1].column == 3))
                                        {
                                            if ((temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column - 1] == 'S') && (temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column - 2] == '.'))
                                            {

                                                seventhIt.row = eightMoves[6].moves[num-1].row;
                                                seventhIt.column = eightMoves[6].moves[num-1].column - 2;
                                                randoms++;
                                                count7 = randoms;
                                                left = true;
                                            }
                                        }
                                        if (up == false && right == false && bottom == false && left == false)
                                        {
                                            areWeThereYet = true;
                                            break;
                                        }


                                        // PUTTING THE NEXT MOVE IN THE MOVE SET
                                        int randomNumber = (rand()%randoms)+1;
                                        // UP
                                        if (count1 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row - 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row - 1][eightMoves[6].moves[num-1].column] = '.';
                                        }
                                        // RIGHT
                                        if (count3 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column + 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column + 1] = '.';
                                        }
                                        // BOTTOM
                                        if (count5 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row + 2;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row + 1][eightMoves[6].moves[num-1].column] = '.';
                                        }
                                        // LEFT
                                        if (count7 == randomNumber)
                                        {
                                            eightMoves[6].moves.push_back(dummy);
                                            eightMoves[6].moves[num].row = eightMoves[6].moves[num-1].row;
                                            eightMoves[6].moves[num].column = eightMoves[6].moves[num-1].column - 2;
                                            eightMoves[6].numCap++;
                                            temp7[eightMoves[6].moves[num-1].row][eightMoves[6].moves[num-1].column - 1] = '.';
                                        }
                                        for (int s = 0; s < 7; s++)
                                            for (int w = 0; w < 7; w++)
                                                eightMoves[6].theBoard[s][w] = temp7[s][w];
                                    }
                                }


                            }
                        }

                    // FINAL COMPARISON TO SEE WHICH MOVE SET HAS THE MOST CAPTURING MOVES
                    int highCap = 0;
                    for (int col = 0; col < 8; col++)
                    {
                        if(eightMoves[col].numCap > highCap)
                        {
                            highCap = eightMoves[col].numCap;
                        }

                    }
                    int var = 0;
                        for (int u = 0; u < 8; u++)
                        {
                            if (eightMoves[u].numCap == highCap)
                            {
                                var = eightMoves[u].moves.size() - 1;
                                foxObjects[foxNum].finalRow = eightMoves[u].moves[var].row;
                                foxObjects[foxNum].finalColumn = eightMoves[u].moves[var].column;
                                foxObjects[foxNum].numCaptured = highCap;
                                for (int theRow = 0; theRow < 7; theRow++)
                                {
                                    for (int theColumn = 0; theColumn < 7; theColumn++)
                                        foxObjects[foxNum].tempBoard[theRow][theColumn] = eightMoves[u].theBoard[theRow][theColumn];
                                }
                                foxObjects[foxNum].tempBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                                foxObjects[foxNum].tempBoard[foxObjects[foxNum].finalRow][foxObjects[foxNum].finalColumn] = 'F';
                            }



                        }

                    // CHECK TO SEE IF NONE OF THE ABOVE DIRECTIONS (PLUS) YIELDED A MOVE TO PRODUCE A RANDOM MOVE
                    if (!((gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] == 'S') && (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo] == '.'))
                        && !((gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] == 'S') && (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 2] == '.'))
                        && !((gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] == 'S') && (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo] == '.'))
                        && !((gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] == 'S') && (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 2] == '.')))
                        {
                            notNearASheep = true;
                        }
                }



                // IF THE FOX IS NOT NEAR A SHEEP FOR CAPTURE, THEN THE FOX CHECKS IF IT CAN THREATEN SHEEP
                if( notNearASheep == true)
                {
                    for (int rowNum = 0; rowNum < 7; rowNum++)
                    {
                        for (int colNum = 0; colNum < 7; colNum++)
                        {
                            foxObjects[foxNum].tempBoard[rowNum][colNum] = gameBoard[rowNum][colNum];
                        }
                    }
                    threats arrayCrossDirections[8];
                    for (int x = 0; x < 8; x++)
                    {
                        arrayCrossDirections[x].moveSet.row = 0;
                        arrayCrossDirections[x].moveSet.column = 0;
                        /////// Create a threat counter initialized at zero.
                        arrayCrossDirections[x].numThreatened = 0;
                    }

                    threats arrayPlusDirections[4];
                    for (int x = 0; x < 4; x++)
                    {
                        arrayPlusDirections[x].moveSet.row = 0;
                        arrayPlusDirections[x].moveSet.column = 0;
                        arrayPlusDirections[x].numThreatened = 0;
                    }

                    if ((foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) || (foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4)
                    || (foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 2) || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                    || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 4) || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 3)
                    || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 2) || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6) || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5)
                    || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 4) || (foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3) || (foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2)
                    || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6) || (foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                    {
                        // CHECK UP
                        if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 6))
                        {
                            /////// If there are no captures moves and
                            /////// if there is a sheep adjacent to a legal move space,
                            /////// move to that space. If there are multiple sheep that can be threatened, add one to
                            /////// the threat counter for each possible threatened sheep found.
                            if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] == '.')
                            {
                                if (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[0].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayCrossDirections[0].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayCrossDirections[0].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayCrossDirections[0].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayCrossDirections[0].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayCrossDirections[0].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayCrossDirections[0].numThreatened++;
                                arrayCrossDirections[0].moveSet.row = foxObjects[foxNum].rowCo - 1;
                                arrayCrossDirections[0].moveSet.column = foxObjects[foxNum].colCo;
                            }
                        }



                        // CHECK UP RIGHT
                        if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                        {
                            if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo + 1] == '.')
                            {
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[1].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[1].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayCrossDirections[1].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo + 2] == 'S')
                                    arrayCrossDirections[1].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayCrossDirections[1].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo + 2] == 'S')
                                    arrayCrossDirections[1].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 2] == 'S')
                                    arrayCrossDirections[1].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayCrossDirections[1].numThreatened++;
                                arrayCrossDirections[1].moveSet.row = foxObjects[foxNum].rowCo - 1;
                                arrayCrossDirections[1].moveSet.column = foxObjects[foxNum].colCo + 1;
                            }
                        }




                        // CHECK RIGHT
                        if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                        {
                            if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] == '.')
                            {
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayCrossDirections[2].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo + 2] == 'S')
                                    arrayCrossDirections[2].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 2] == 'S')
                                    arrayCrossDirections[2].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayCrossDirections[2].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo + 2] == 'S')
                                    arrayCrossDirections[2].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[2].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[2].numThreatened++;
                                arrayCrossDirections[2].moveSet.row = foxObjects[foxNum].rowCo;
                                arrayCrossDirections[2].moveSet.column = foxObjects[foxNum].colCo + 1;
                            }
                        }




                        // CHECK BOTTOM RIGHT
                        if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4))
                        {
                            if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo + 1] == '.')
                            {
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[3].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[3].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayCrossDirections[3].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo + 2] == 'S')
                                    arrayCrossDirections[3].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo + 2] == 'S')
                                    arrayCrossDirections[3].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 2] == 'S')
                                    arrayCrossDirections[3].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayCrossDirections[3].numThreatened++;
                                arrayCrossDirections[3].moveSet.row = foxObjects[foxNum].rowCo + 1;
                                arrayCrossDirections[3].moveSet.column = foxObjects[foxNum].colCo + 1;
                            }
                        }




                        // CHECK BOTTOM
                        if (!(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                        {
                            if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] == '.')
                            {
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayCrossDirections[4].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayCrossDirections[4].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayCrossDirections[4].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[4].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayCrossDirections[4].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayCrossDirections[4].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayCrossDirections[4].numThreatened++;
                                arrayCrossDirections[4].moveSet.row = foxObjects[foxNum].rowCo + 1;
                                arrayCrossDirections[4].moveSet.column = foxObjects[foxNum].colCo;
                            }
                        }




                        // CHECK BOTTOM LEFT
                        if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                        {
                            if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo - 1] == '.')
                            {
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayCrossDirections[5].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 2] == 'S')
                                    arrayCrossDirections[5].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo - 2] == 'S')
                                    arrayCrossDirections[5].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo - 2] == 'S')
                                    arrayCrossDirections[5].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayCrossDirections[5].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[5].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[5].numThreatened++;
                                arrayCrossDirections[5].moveSet.row = foxObjects[foxNum].rowCo + 1;
                                arrayCrossDirections[5].moveSet.column = foxObjects[foxNum].colCo - 1;
                            }
                        }




                        // CHECK LEFT
                        if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3))
                        {
                            if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] == '.')
                            {
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[6].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayCrossDirections[6].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo - 2] == 'S')
                                    arrayCrossDirections[6].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 2] == 'S')
                                    arrayCrossDirections[6].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo - 2] == 'S')
                                    arrayCrossDirections[6].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayCrossDirections[6].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[6].numThreatened++;
                                arrayCrossDirections[6].moveSet.row = foxObjects[foxNum].rowCo;
                                arrayCrossDirections[6].moveSet.column = foxObjects[foxNum].colCo - 1;
                            }
                        }




                        // CHECK UPPER LEFT
                        if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3))
                        {
                            if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo - 1] == '.')
                            {
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[7].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo] == 'S')
                                    arrayCrossDirections[7].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayCrossDirections[7].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo - 2] == 'S')
                                    arrayCrossDirections[7].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo - 2] == 'S')
                                    arrayCrossDirections[7].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 2] == 'S')
                                    arrayCrossDirections[7].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayCrossDirections[7].numThreatened++;
                                arrayCrossDirections[7].moveSet.row = foxObjects[foxNum].rowCo - 1;
                                arrayCrossDirections[7].moveSet.column = foxObjects[foxNum].colCo - 1;
                            }
                        }



                        /////// Loop through every possible way
                        /////// the fox could go while comparing the threat counter to a new temporary counter in the loop
                        /////// to see which counter is larger. If the temporary counter is larger, set the threat counter
                        /////// equal to the temporary counter. After the loop is finished, loop through the possible ways
                        /////// again and compare the threat counter to the temporary counter. If they are equal, have the fox
                        /////// choose that set of moves to make.
                        int highThreat = 0;
                        for (int s = 0; s < 8; s++)
                        {
                            if (arrayCrossDirections[s].numThreatened > highThreat)
                                highThreat = arrayCrossDirections[s].numThreatened;
                        }
                        for (int y = 0; y < 8; y++)
                        {
                            if (arrayCrossDirections[y].numThreatened == highThreat)
                            {
                                foxObjects[foxNum].numThreatened = arrayCrossDirections[y].numThreatened;
                                foxObjects[foxNum].finalRow = arrayCrossDirections[y].moveSet.row;
                                foxObjects[foxNum].finalColumn = arrayCrossDirections[y].moveSet.column;
                            }
                        }
                        foxObjects[foxNum].tempBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                        foxObjects[foxNum].tempBoard[foxObjects[foxNum].finalRow][foxObjects[foxNum].finalColumn] = 'F';

                    }
                    else if ((foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3) || (foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2) || (foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                         || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1) || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 3) || (foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5)
                         || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 2) || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 4)
                         || (foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6) || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1) || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 3)
                         || (foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) || (foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) || (foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4)
                         || (foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3))
                         {
                             // CHECK UP
                             if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                            && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2)
                            && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                            && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                            && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6)
                            && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                            && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 6))
                            {
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] == '.')
                                 {
                                        if (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo] == 'S')
                                            arrayPlusDirections[0].numThreatened++;
                                        if (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo - 1] == 'S')
                                            arrayPlusDirections[0].numThreatened++;
                                        if (gameBoard[foxObjects[foxNum].rowCo - 2][foxObjects[foxNum].colCo + 1] == 'S')
                                            arrayPlusDirections[0].numThreatened++;
                                        if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo - 1] == 'S')
                                            arrayPlusDirections[0].numThreatened++;
                                        if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo + 1] == 'S')
                                            arrayPlusDirections[0].numThreatened++;
                                        if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] == 'S')
                                            arrayPlusDirections[0].numThreatened++;
                                        if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] == 'S')
                                            arrayPlusDirections[0].numThreatened++;
                                        arrayPlusDirections[0].moveSet.row = foxObjects[foxNum].rowCo - 1;
                                        arrayPlusDirections[0].moveSet.column = foxObjects[foxNum].colCo;
                                 }
                            }





                        // CHECK RIGHT
                        if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                        {
                            if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] == '.')
                            {
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayPlusDirections[1].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo + 2] == 'S')
                                    arrayPlusDirections[1].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 2] == 'S')
                                    arrayPlusDirections[1].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayPlusDirections[1].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo + 2] == 'S')
                                    arrayPlusDirections[1].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] == 'S')
                                    arrayPlusDirections[1].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] == 'S')
                                    arrayPlusDirections[1].numThreatened++;
                                arrayPlusDirections[1].moveSet.row = foxObjects[foxNum].rowCo;
                                arrayPlusDirections[1].moveSet.column = foxObjects[foxNum].colCo + 1;
                            }
                        }




                        // CHECK BOTTOM
                        if (!(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 5) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 6)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 4) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 4))
                        {
                            if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] == '.')
                            {
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayPlusDirections[2].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayPlusDirections[2].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayPlusDirections[2].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo] == 'S')
                                    arrayPlusDirections[2].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 2][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayPlusDirections[2].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayPlusDirections[2].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo + 1] == 'S')
                                    arrayPlusDirections[2].numThreatened++;
                                arrayPlusDirections[2].moveSet.row = foxObjects[foxNum].rowCo + 1;
                                arrayPlusDirections[2].moveSet.column = foxObjects[foxNum].colCo;
                            }
                        }




                        // CHECK LEFT
                        if (!(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 0 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 1 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 2 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 3 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 0) && !(foxObjects[foxNum].rowCo == 4 && foxObjects[foxNum].colCo == 1)
                        && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 5 && foxObjects[foxNum].colCo == 3)
                        && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 2) && !(foxObjects[foxNum].rowCo == 6 && foxObjects[foxNum].colCo == 3))
                        {
                            if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 1] == '.')
                            {
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo] == 'S')
                                    arrayPlusDirections[3].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayPlusDirections[3].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo - 1][foxObjects[foxNum].colCo - 2] == 'S')
                                    arrayPlusDirections[3].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo - 2] == 'S')
                                    arrayPlusDirections[3].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo - 2] == 'S')
                                    arrayPlusDirections[3].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo - 1] == 'S')
                                    arrayPlusDirections[3].numThreatened++;
                                if (gameBoard[foxObjects[foxNum].rowCo + 1][foxObjects[foxNum].colCo] == 'S')
                                    arrayPlusDirections[3].numThreatened++;
                                arrayPlusDirections[3].moveSet.row = foxObjects[foxNum].rowCo;
                                arrayPlusDirections[3].moveSet.column = foxObjects[foxNum].colCo - 1;
                            }
                        }




                        int highThreat = 0;
                        for (int s = 0; s < 4; s++)
                        {
                            if (arrayPlusDirections[s].numThreatened > highThreat)
                                highThreat = arrayPlusDirections[s].numThreatened;
                        }
                        for (int y = 0; y < 4; y++)
                        {
                            if (arrayPlusDirections[y].numThreatened == highThreat)
                            {
                                foxObjects[foxNum].numThreatened = arrayPlusDirections[y].numThreatened;
                                foxObjects[foxNum].finalRow = arrayPlusDirections[y].moveSet.row;
                                foxObjects[foxNum].finalColumn = arrayPlusDirections[y].moveSet.column;
                            }
                        }
                        foxObjects[foxNum].tempBoard[foxObjects[foxNum].rowCo][foxObjects[foxNum].colCo] = '.';
                        foxObjects[foxNum].tempBoard[foxObjects[foxNum].finalRow][foxObjects[foxNum].finalColumn] = 'F';
                    }

                } // End of if's for cap and threat
            } // End of foxes loop


            /////// This fox and the other fox will need to be compared according to how many sheep each can either capture or threaten.
            /////// Whichever has more sheep that it can either capture or threaten (capturing a sheep will automatically outweigh a threat),
            /////// that fox will make a move.
            if (howManyFoxes == 2)
            {
                if (foxObjects[0].numCaptured > foxObjects[1].numCaptured)
                {
                    oldPos = letterArray[foxObjects[0].colCo];
                    oldPosition = numberArray[foxObjects[0].rowCo];
                    officialRow = foxObjects[0].finalRow;
                    officialColumn = foxObjects[0].finalColumn;
                    for (int x = 0; x < 7; x++)
                        for (int y = 0; y < 7; y++)
                            gameBoard[x][y] = foxObjects[0].tempBoard[x][y];
                }
                else if (foxObjects[1].numCaptured > foxObjects[0].numCaptured)
                {
                    oldPos = letterArray[foxObjects[1].colCo];
                    oldPosition = numberArray[foxObjects[1].rowCo];
                    officialRow = foxObjects[1].finalRow;
                    officialColumn = foxObjects[1].finalColumn;
                    for (int x = 0; x < 7; x++)
                        for (int y = 0; y < 7; y++)
                            gameBoard[x][y] = foxObjects[1].tempBoard[x][y];
                }
                else if ((foxObjects[0].numCaptured == foxObjects[1].numCaptured) && (foxObjects[0].numCaptured > 0 && foxObjects[1].numCaptured > 0))
                {
                    int randNum = 0;
                    randNum = (rand()%2) + 1;
                    if (randNum == 1)
                    {
                        oldPos = letterArray[foxObjects[0].colCo];
                        oldPosition = numberArray[foxObjects[0].rowCo];
                        officialRow = foxObjects[0].finalRow;
                        officialColumn = foxObjects[0].finalColumn;
                        for (int x = 0; x < 7; x++)
                            for (int y = 0; y < 7; y++)
                                gameBoard[x][y] = foxObjects[0].tempBoard[x][y];
                    }
                    else if (randNum == 2)
                    {
                        oldPos = letterArray[foxObjects[1].colCo];
                        oldPosition = numberArray[foxObjects[1].rowCo];
                        officialRow = foxObjects[1].finalRow;
                        officialColumn = foxObjects[1].finalColumn;
                        for (int x = 0; x < 7; x++)
                            for (int y = 0; y < 7; y++)
                                gameBoard[x][y] = foxObjects[1].tempBoard[x][y];
                    }
                }
                if ((foxObjects[0].numCaptured == 0 && foxObjects[1].numCaptured == 0) && (foxObjects[0].numThreatened > foxObjects[1].numThreatened))
                {
                    oldPos = letterArray[foxObjects[0].colCo];
                    oldPosition = numberArray[foxObjects[0].rowCo];
                    officialRow = foxObjects[0].finalRow;
                    officialColumn = foxObjects[0].finalColumn;
                    for (int x = 0; x < 7; x++)
                            for (int y = 0; y < 7; y++)
                                gameBoard[x][y] = foxObjects[0].tempBoard[x][y];
                }
                else if ((foxObjects[0].numCaptured == 0 && foxObjects[1].numCaptured == 0) && (foxObjects[1].numThreatened > foxObjects[0].numThreatened))
                {
                    oldPos = letterArray[foxObjects[1].colCo];
                    oldPosition = numberArray[foxObjects[1].rowCo];
                    officialRow = foxObjects[1].finalRow;
                    officialColumn = foxObjects[1].finalColumn;
                    for (int x = 0; x < 7; x++)
                            for (int y = 0; y < 7; y++)
                                gameBoard[x][y] = foxObjects[1].tempBoard[x][y];
                }
                else if ((foxObjects[0].numCaptured == 0 && foxObjects[1].numCaptured == 0) && (foxObjects[0].numThreatened == foxObjects[1].numThreatened) && (foxObjects[0].numThreatened > 0 && foxObjects[1].numThreatened > 0))
                {
                    int randNumThreat = 0;
                    randNumThreat = (rand()%2) + 1;
                    if (randNumThreat == 1)
                    {
                        oldPos = letterArray[foxObjects[0].colCo];
                        oldPosition = numberArray[foxObjects[0].rowCo];
                        officialRow = foxObjects[0].finalRow;
                        officialColumn = foxObjects[0].finalColumn;
                        for (int x = 0; x < 7; x++)
                                for (int y = 0; y < 7; y++)
                                    gameBoard[x][y] = foxObjects[0].tempBoard[x][y];
                    }
                    else if (randNumThreat == 2)
                    {
                        oldPos = letterArray[foxObjects[1].colCo];
                        oldPosition = numberArray[foxObjects[1].rowCo];
                        officialRow = foxObjects[1].finalRow;
                        officialColumn = foxObjects[1].finalColumn;
                        for (int x = 0; x < 7; x++)
                                for (int y = 0; y < 7; y++)
                                    gameBoard[x][y] = foxObjects[1].tempBoard[x][y];
                    }

                }

                /////// If no captures or threats are possible, the fox will move to a random legal position.
                if ((foxObjects[0].numCaptured == 0 && foxObjects[1].numCaptured == 0) && (foxObjects[0].numThreatened == 0 && foxObjects[1].numThreatened == 0))
                {
                    oldPos = letterArray[fox1.colCo];
                    oldPosition = numberArray[fox1.rowCo];
                    if ((fox1.rowCo == 0 && fox1.colCo == 2) || (fox1.rowCo == 2 && fox1.colCo == 0) || (fox1.rowCo == 0 && fox1.colCo == 4)
                        || (fox1.rowCo == 1 && fox1.colCo == 3) || (fox1.rowCo == 2 && fox1.colCo == 2) || (fox1.rowCo == 3 && fox1.colCo == 1)
                        || (fox1.rowCo == 4 && fox1.colCo == 0) || (fox1.rowCo == 2 && fox1.colCo == 4) || (fox1.rowCo == 3 && fox1.colCo == 3)
                        || (fox1.rowCo == 4 && fox1.colCo == 2) || (fox1.rowCo == 2 && fox1.colCo == 6) || (fox1.rowCo == 3 && fox1.colCo == 5)
                        || (fox1.rowCo == 4 && fox1.colCo == 4) || (fox1.rowCo == 5 && fox1.colCo == 3) || (fox1.rowCo == 6 && fox1.colCo == 2)
                        || (fox1.rowCo == 4 && fox1.colCo == 6) || (fox1.rowCo == 6 && fox1.colCo == 4))
                        {
                            int possibilities = 0;
                            int theRandomNum = 0;
                            int randomNums[8];

                            for (int a = 0; a < 8; a++)
                                randomNums[a] = 0;




                            if (gameBoard[fox1.rowCo - 1][fox1.colCo] == '.')
                            {
                                possibilities++;
                                randomNums[0] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo - 1][fox1.colCo + 1] == '.')
                            {
                                possibilities++;
                                randomNums[1] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo][fox1.colCo + 1] == '.')
                            {
                                possibilities++;
                                randomNums[2] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo + 1][fox1.colCo + 1] == '.')
                            {
                                possibilities++;
                                randomNums[3] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo + 1][fox1.colCo] == '.')
                            {
                                possibilities++;
                                randomNums[4] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo + 1][fox1.colCo - 1] == '.')
                            {
                                possibilities++;
                                randomNums[5] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo][fox1.colCo - 1] == '.')
                            {
                                possibilities++;
                                randomNums[6] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo - 1][fox1.colCo - 1] == '.')
                            {
                                possibilities++;
                                randomNums[7] = possibilities;
                            }

                            theRandomNum = (rand()%possibilities) + 1;
                            if (theRandomNum == randomNums[0])
                            {
                                officialRow = fox1.rowCo - 1;
                                officialColumn = fox1.colCo;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo - 1][fox1.colCo] = 'F';
                            }
                            else if (theRandomNum == randomNums[1])
                            {
                                officialRow = fox1.rowCo - 1;
                                officialColumn = fox1.colCo + 1;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo - 1][fox1.colCo + 1] = 'F';
                            }
                            else if (theRandomNum == randomNums[2])
                            {
                                officialRow = fox1.rowCo;
                                officialColumn = fox1.colCo + 1;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo][fox1.colCo + 1] = 'F';
                            }
                            else if (theRandomNum == randomNums[3])
                            {
                                officialRow = fox1.rowCo + 1;
                                officialColumn = fox1.colCo + 1;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo + 1][fox1.colCo + 1] = 'F';
                            }
                            else if (theRandomNum == randomNums[4])
                            {
                                officialRow = fox1.rowCo + 1;
                                officialColumn = fox1.colCo;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo + 1][fox1.colCo] = 'F';
                            }
                            else if (theRandomNum == randomNums[5])
                            {
                                officialRow = fox1.rowCo + 1;
                                officialColumn = fox1.colCo - 1;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo + 1][fox1.colCo - 1] = 'F';
                            }
                            else if (theRandomNum == randomNums[6])
                            {
                                officialRow = fox1.rowCo;
                                officialColumn = fox1.colCo - 1;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo][fox1.colCo - 1] = 'F';
                            }
                            else if (theRandomNum == randomNums[7])
                            {
                                officialRow = fox1.rowCo - 1;
                                officialColumn = fox1.colCo + 1;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo - 1][fox1.colCo + 1] = 'F';
                            }
                        }
                        else if ((fox1.rowCo == 0 && fox1.colCo == 3) || (fox1.rowCo == 1 && fox1.colCo == 2) || (fox1.rowCo == 1 && fox1.colCo == 4)
                             || (fox1.rowCo == 2 && fox1.colCo == 1) || (fox1.rowCo == 2 && fox1.colCo == 3) || (fox1.rowCo == 2 && fox1.colCo == 5)
                             || (fox1.rowCo == 3 && fox1.colCo == 0) || (fox1.rowCo == 3 && fox1.colCo == 2) || (fox1.rowCo == 3 && fox1.colCo == 4)
                             || (fox1.rowCo == 3 && fox1.colCo == 6) || (fox1.rowCo == 4 && fox1.colCo == 1) || (fox1.rowCo == 4 && fox1.colCo == 3)
                             || (fox1.rowCo == 4 && fox1.colCo == 5) || (fox1.rowCo == 5 && fox1.colCo == 2) || (fox1.rowCo == 5 && fox1.colCo == 4)
                             || (fox1.rowCo == 6 && fox1.colCo == 3))
                             {
                                    int possibilities = 0;
                                    int theRandomNum = 0;
                                    int randomNums[4];

                                    for (int a = 0; a < 4; a++)
                                        randomNums[a] = 0;

                                    if (gameBoard[fox1.rowCo - 1][fox1.colCo] == '.')
                                    {
                                        possibilities++;
                                        randomNums[0] = possibilities;
                                    }
                                    if (gameBoard[fox1.rowCo][fox1.colCo + 1] == '.')
                                    {
                                        possibilities++;
                                        randomNums[1] = possibilities;
                                    }
                                    if (gameBoard[fox1.rowCo + 1][fox1.colCo] == '.')
                                    {
                                        possibilities++;
                                        randomNums[2] = possibilities;
                                    }
                                    if (gameBoard[fox1.rowCo][fox1.colCo - 1] == '.')
                                    {
                                        possibilities++;
                                        randomNums[3] = possibilities;
                                    }

                                    theRandomNum = (rand()%possibilities) + 1;
                                    if (theRandomNum == randomNums[0])
                                    {
                                        officialRow = fox1.rowCo - 1;
                                        officialColumn = fox1.colCo;
                                        gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                        gameBoard[fox1.rowCo - 1][fox1.colCo] = 'F';
                                    }
                                    else if (theRandomNum == randomNums[1])
                                    {
                                        officialRow = fox1.rowCo;
                                        officialColumn = fox1.colCo + 1;
                                        gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                        gameBoard[fox1.rowCo][fox1.colCo + 1] = 'F';
                                    }
                                    else if (theRandomNum == randomNums[2])
                                    {
                                        officialRow = fox1.rowCo + 1;
                                        officialColumn = fox1.colCo;
                                        gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                        gameBoard[fox1.rowCo + 1][fox1.colCo] = 'F';
                                    }
                                    else if (theRandomNum == randomNums[3])
                                    {
                                        officialRow = fox1.rowCo;
                                        officialColumn = fox1.colCo - 1;
                                        gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                        gameBoard[fox1.rowCo][fox1.colCo - 1] = 'F';
                                    }


                             }

                }
            }
            else if (howManyFoxes == 1)
            {
                if (foxObjects[0].numCaptured > 0)
                {
                    oldPos = letterArray[foxObjects[0].colCo];
                    oldPosition = numberArray[foxObjects[0].rowCo];
                    officialRow = foxObjects[0].finalRow;
                    officialColumn = foxObjects[0].finalColumn;
                    for (int x = 0; x < 7; x++)
                        for (int y = 0; y < 7; y++)
                            gameBoard[x][y] = foxObjects[0].tempBoard[x][y];
                }
                if (foxObjects[0].numCaptured == 0 && foxObjects[0].numThreatened > 0)
                {
                    oldPos = letterArray[foxObjects[0].colCo];
                    oldPosition = numberArray[foxObjects[0].rowCo];
                    officialRow = foxObjects[0].finalRow;
                    officialColumn = foxObjects[0].finalColumn;
                    for (int x = 0; x < 7; x++)
                            for (int y = 0; y < 7; y++)
                                gameBoard[x][y] = foxObjects[0].tempBoard[x][y];
                }

                /////// If no captures or threats are possible, the fox will move to a random legal position.
                if (foxObjects[0].numCaptured == 0 && foxObjects[0].numThreatened == 0)
                {
                    oldPos = letterArray[fox1.colCo];
                    oldPosition = numberArray[fox1.rowCo];
                    if ((fox1.rowCo == 0 && fox1.colCo == 2) || (fox1.rowCo == 2 && fox1.colCo == 0) || (fox1.rowCo == 0 && fox1.colCo == 4)
                        || (fox1.rowCo == 1 && fox1.colCo == 3) || (fox1.rowCo == 2 && fox1.colCo == 2) || (fox1.rowCo == 3 && fox1.colCo == 1)
                        || (fox1.rowCo == 4 && fox1.colCo == 0) || (fox1.rowCo == 2 && fox1.colCo == 4) || (fox1.rowCo == 3 && fox1.colCo == 3)
                        || (fox1.rowCo == 4 && fox1.colCo == 2) || (fox1.rowCo == 2 && fox1.colCo == 6) || (fox1.rowCo == 3 && fox1.colCo == 5)
                        || (fox1.rowCo == 4 && fox1.colCo == 4) || (fox1.rowCo == 5 && fox1.colCo == 3) || (fox1.rowCo == 6 && fox1.colCo == 2)
                        || (fox1.rowCo == 4 && fox1.colCo == 6) || (fox1.rowCo == 6 && fox1.colCo == 4))
                        {
                            int possibilities = 0;
                            int theRandomNum = 0;
                            int randomNums[8];

                            for (int a = 0; a < 8; a++)
                                randomNums[a] = 0;




                            if (gameBoard[fox1.rowCo - 1][fox1.colCo] == '.')
                            {
                                possibilities++;
                                randomNums[0] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo - 1][fox1.colCo + 1] == '.')
                            {
                                possibilities++;
                                randomNums[1] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo][fox1.colCo + 1] == '.')
                            {
                                possibilities++;
                                randomNums[2] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo + 1][fox1.colCo + 1] == '.')
                            {
                                possibilities++;
                                randomNums[3] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo + 1][fox1.colCo] == '.')
                            {
                                possibilities++;
                                randomNums[4] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo + 1][fox1.colCo - 1] == '.')
                            {
                                possibilities++;
                                randomNums[5] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo][fox1.colCo - 1] == '.')
                            {
                                possibilities++;
                                randomNums[6] = possibilities;
                            }
                            if (gameBoard[fox1.rowCo - 1][fox1.colCo - 1] == '.')
                            {
                                possibilities++;
                                randomNums[7] = possibilities;
                            }

                            theRandomNum = (rand()%possibilities) + 1;
                            if (theRandomNum == randomNums[0])
                            {
                                officialRow = fox1.rowCo - 1;
                                officialColumn = fox1.colCo;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo - 1][fox1.colCo] = 'F';
                            }
                            else if (theRandomNum == randomNums[1])
                            {
                                officialRow = fox1.rowCo - 1;
                                officialColumn = fox1.colCo + 1;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo - 1][fox1.colCo + 1] = 'F';
                            }
                            else if (theRandomNum == randomNums[2])
                            {
                                officialRow = fox1.rowCo;
                                officialColumn = fox1.colCo + 1;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo][fox1.colCo + 1] = 'F';
                            }
                            else if (theRandomNum == randomNums[3])
                            {
                                officialRow = fox1.rowCo + 1;
                                officialColumn = fox1.colCo + 1;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo + 1][fox1.colCo + 1] = 'F';
                            }
                            else if (theRandomNum == randomNums[4])
                            {
                                officialRow = fox1.rowCo + 1;
                                officialColumn = fox1.colCo;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo + 1][fox1.colCo] = 'F';
                            }
                            else if (theRandomNum == randomNums[5])
                            {
                                officialRow = fox1.rowCo + 1;
                                officialColumn = fox1.colCo - 1;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo + 1][fox1.colCo - 1] = 'F';
                            }
                            else if (theRandomNum == randomNums[6])
                            {
                                officialRow = fox1.rowCo;
                                officialColumn = fox1.colCo - 1;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo][fox1.colCo - 1] = 'F';
                            }
                            else if (theRandomNum == randomNums[7])
                            {
                                officialRow = fox1.rowCo - 1;
                                officialColumn = fox1.colCo + 1;
                                gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                gameBoard[fox1.rowCo - 1][fox1.colCo + 1] = 'F';
                            }
                        }
                        else if ((fox1.rowCo == 0 && fox1.colCo == 3) || (fox1.rowCo == 1 && fox1.colCo == 2) || (fox1.rowCo == 1 && fox1.colCo == 4)
                             || (fox1.rowCo == 2 && fox1.colCo == 1) || (fox1.rowCo == 2 && fox1.colCo == 3) || (fox1.rowCo == 2 && fox1.colCo == 5)
                             || (fox1.rowCo == 3 && fox1.colCo == 0) || (fox1.rowCo == 3 && fox1.colCo == 2) || (fox1.rowCo == 3 && fox1.colCo == 4)
                             || (fox1.rowCo == 3 && fox1.colCo == 6) || (fox1.rowCo == 4 && fox1.colCo == 1) || (fox1.rowCo == 4 && fox1.colCo == 3)
                             || (fox1.rowCo == 4 && fox1.colCo == 5) || (fox1.rowCo == 5 && fox1.colCo == 2) || (fox1.rowCo == 5 && fox1.colCo == 4)
                             || (fox1.rowCo == 6 && fox1.colCo == 3))
                             {
                                    int possibilities = 0;
                                    int theRandomNum = 0;
                                    int randomNums[4];

                                    for (int a = 0; a < 4; a++)
                                        randomNums[a] = 0;

                                    if (gameBoard[fox1.rowCo - 1][fox1.colCo] == '.')
                                    {
                                        possibilities++;
                                        randomNums[0] = possibilities;
                                    }
                                    if (gameBoard[fox1.rowCo][fox1.colCo + 1] == '.')
                                    {
                                        possibilities++;
                                        randomNums[1] = possibilities;
                                    }
                                    if (gameBoard[fox1.rowCo + 1][fox1.colCo] == '.')
                                    {
                                        possibilities++;
                                        randomNums[2] = possibilities;
                                    }
                                    if (gameBoard[fox1.rowCo][fox1.colCo - 1] == '.')
                                    {
                                        possibilities++;
                                        randomNums[3] = possibilities;
                                    }

                                    theRandomNum = (rand()%possibilities) + 1;
                                    if (theRandomNum == randomNums[0])
                                    {
                                        officialRow = fox1.rowCo - 1;
                                        officialColumn = fox1.colCo;
                                        gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                        gameBoard[fox1.rowCo - 1][fox1.colCo] = 'F';
                                    }
                                    else if (theRandomNum == randomNums[1])
                                    {
                                        officialRow = fox1.rowCo;
                                        officialColumn = fox1.colCo + 1;
                                        gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                        gameBoard[fox1.rowCo][fox1.colCo + 1] = 'F';
                                    }
                                    else if (theRandomNum == randomNums[2])
                                    {
                                        officialRow = fox1.rowCo + 1;
                                        officialColumn = fox1.colCo;
                                        gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                        gameBoard[fox1.rowCo + 1][fox1.colCo] = 'F';
                                    }
                                    else if (theRandomNum == randomNums[3])
                                    {
                                        officialRow = fox1.rowCo;
                                        officialColumn = fox1.colCo - 1;
                                        gameBoard[fox1.rowCo][fox1.colCo] = '.';
                                        gameBoard[fox1.rowCo][fox1.colCo - 1] = 'F';
                                    }


                             }

                }
            }



				//////// Match the letter and number arrays with the new board positions of the fox and
				//////// set the newPos and newPosition variables equal to their corresponding letter and number.

				newPos = letterArray[officialColumn];
				newPosition = numberArray[officialRow];

				//////// Output the fox's move.
				cout << "\nThe foxes move: " << oldPos << oldPosition << "-" << newPos << newPosition << endl;

}
