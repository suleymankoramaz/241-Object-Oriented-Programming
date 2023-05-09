#ifndef AND_GATE_H
#define AND_GATE_H
#include <vector>
#include <string>
#include "gate.h"
using namespace std;

class and_gate : public gate	
{
	public:
		//default constructor
		and_gate(){};

		//constructor that takes name and inputs 
		and_gate(string newName,vector<gate*> ins);

		//virtual function
		int evaluate();
};

#endif