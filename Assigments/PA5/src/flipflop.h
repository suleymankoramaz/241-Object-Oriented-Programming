#ifndef FLIPFLOP_H
#define FLIPFLOP_H
#include <vector>
#include <string>
#include "gate.h"
using namespace std;

class flipflop : public gate	
{
	public:
		//default constructor
		flipflop(){setType(5); setData(0);};

		//consturctor that takes name and inputs
		flipflop(string newName,vector<gate*> ins);

		//virtual function
		int evaluate();
};

#endif