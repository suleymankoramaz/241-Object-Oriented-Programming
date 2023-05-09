#ifndef NOT_GATE_H
#define NOT_GATE_H
#include <vector>
#include <string>
#include "gate.h"
using namespace std;

class not_gate : public gate
{
	public:
		//default constructor
		not_gate(){};

		//constructor that takes name and inputs
		not_gate(string newName,std::vector<gate*> ins);
		
		//virtual function
		int evaluate();
};

#endif