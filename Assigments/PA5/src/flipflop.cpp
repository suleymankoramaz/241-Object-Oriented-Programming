#include <string>
#include "flipflop.h"
#include <vector>
#include <iostream>
using namespace std;

flipflop::flipflop(string newName,vector<gate*> ins)
{
	//set name
	setName(newName);
	//set inputs
	setIn(ins);
	//set output of flipflop
	setData(0);
	setType(5);
}

int flipflop::evaluate()
{
	//flip-flop must evaluated just one time in one process
	if(getCounter() == 0){
		//value of input
		int x;

		//increase counter
		counter_();

		//evaluate input 
		x = getIn(0)->evaluate();

		//return value
		if((x == 1 && getData() == 0) || (x == 0 && getData() == 1)){
			setData(1);
			return 1;
		}
		else{
			setData(0);
			return 0;
		}
	}

	//if flip-flop evaluated before return data value without evaluate
	else
		return getData();
}