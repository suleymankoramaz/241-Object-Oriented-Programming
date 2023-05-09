#ifndef OR_GATE_H
#define OR_GATE_H
#include <vector>
#include <string>
#include "gate.h"
using namespace std;

class or_gate : public gate
{
	public:
		//default constructor
		or_gate(){};

		//constructor that takes name and inputs
		or_gate(string newName,vector<gate*> ins);
		
		//virtual function
		int evaluate();
};

#endif