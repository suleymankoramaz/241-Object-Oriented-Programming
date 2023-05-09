#ifndef OUTPUT_H
#define OUTPUT_H
#include <string>
#include "gate.h"
using namespace std;
class output : public gate
{
	public:
		//default constructor
		output(){};

		//constructor that takes name
		output(string newName);

		//virtual function
		int evaluate();
};

#endif