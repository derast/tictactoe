#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;


const int FIRST_DIMENSION_SIZE = 4;
const int SECOND_DIMENSION_SIZE = 4;
const int X_USER = 1;  //Integer const to control x user turn to play
const int O_USER = 2;  //Integer const to control o user turn to play
const int CHECK_BY_COLUMN = 1;
const int CHECK_BY_ROW = 2;


int verifyCinInput(istream& cin);


int verifyCinInput(istream& cin)
{
    if(cin.fail())
    {
        cin.clear();  //clear error flags
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  //skip max() characters to the next new line
        cout<<"Wrong user input\n";
        return 1;
    }
    return 0;
}