#include "manager.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// This function will call the manageGame function with an input stream.
int main(int argc, char** argv)
{
    //// Call the manageGame function and end the program when manageGame is done.
    if (argc > 1) {
        ifstream in(argv[1]);

        manageGame(in);
    } else
        manageGame(cin);


    return 0;
}
