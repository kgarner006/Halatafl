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
	string input = ".F.F.S.SS.SS.SS.SSSS..SSS..SSSSSS";

	istringstream str(input);

    gameStats stats = manageTestGame(str);

    if ((!stats.gameOver)
    && (stats.numSheep == 19)
    && (stats.numFoxes >= 1))
    {
        return 0;
    }
    else
        return 1;
}
