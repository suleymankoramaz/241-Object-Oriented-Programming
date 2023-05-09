#include <string>
#include "and_gate.h"
#include <vector>
#include <iostream>
using namespace std;

//constructor
and_gate::and_gate(string newName,vector<gate*> ins)
{
	//set name
	setName(newName);
	//set inputs 
	setIn(ins);
}

//return function
int and_gate::evaluate()
{	
	//values of input data
	int x1,x2;

	//evaluate input gates
	x1 = getIn(0)->evaluate();
	x2 = getIn(1)->evaluate();	

	//return value
	if(x1 == 1 && x2 == 1)
		return 1;
	return 0;
}