#include <string>
#include "not_gate.h"
#include <vector>
#include <iostream>
using namespace std;

//constructor
not_gate::not_gate(string newName,vector<gate*> ins)
{
	//set name
	setName(newName);
	//set inputs
	setIn(ins);
}

int not_gate::evaluate()
{	
	//value of input data
	int x;

	//evaluate input 
	x = getIn(0)->evaluate();

	//return value
	if(x == 0)
		return 1;
	return 0;
}