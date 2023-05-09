#ifndef INPUT_H
#define INPUT_H
#include <string>
#include "gate.h"
using namespace std;

class input : public gate
{
	public:
		//default constructor
		input(){};

		//constructor that takes name
		input(string newName);

		//virtual function
		int evaluate();
};

#endif