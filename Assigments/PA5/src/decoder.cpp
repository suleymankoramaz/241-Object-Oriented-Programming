#include "decoder.h"
#include <vector>
#include <iostream>

//constructor
decoder::decoder(vector<gate*> ins)
{
	//set inputs
	setIn(ins);
}

//return function
int decoder::evaluate()
{
	//value of input data
	int x1,x2;

	//outputs of decoder
	int d1,d2,d3,d4;

	//evaluate inputs
	x1 = getIn(0)->evaluate();
	x2 = getIn(1)->evaluate();
	

	//calculate outputs
	if(x1 == 0 && x2 == 0){
		d1 = 1;
		d2 = 0;
		d3 = 0;
		d4 = 0;
	}
	if(x1 == 0 && x2 == 1){
		d1 = 0;
		d2 = 1;
		d3 = 0;
		d4 = 0;
	}
	if(x1 == 1 && x2 == 0){
		d1 = 0;
		d2 = 0;
		d3 = 1;
		d4 = 0;
	}	
	if(x1 == 1 && x2 == 1){
		d1 = 0;
		d2 = 0;
		d3 = 0;
		d4 = 1;
	}

	//return value
	return d1*1000 + d2*100 + d3*10 + d4;
}