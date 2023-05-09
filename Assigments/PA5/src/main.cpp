#include "logic.h"

using namespace std;

int main()
{
    //create logic machine object
    logic l1;

    //create circuit from file
    l1.readfile_circuit();

    //calculate and print output
    l1.program();
    return 0;
}