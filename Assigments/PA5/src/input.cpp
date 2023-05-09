#include <string>
#include "input.h"
using namespace std;

//constructor
input::input(string newName)
{
	//set name
	setName(newName);
}

//return data
int input::evaluate()
{		
	return getData();
}