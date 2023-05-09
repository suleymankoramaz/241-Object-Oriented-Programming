#include <string>
#include "output.h"
using namespace std;

//constructor
output::output(string newName)
{
	//set name
	setName(newName);
}

//return data
int output::evaluate()
{
	return getData();
}