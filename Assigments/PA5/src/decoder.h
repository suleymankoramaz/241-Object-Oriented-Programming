#ifndef DECODER_H
#define DECODER_H
#include <vector>
#include "gate.h"
using namespace std;
class decoder : public gate	
{
	public:
		//default constructor
		decoder(){};

		//constructor that takes inputs
		decoder(vector<gate*> ins);

		//virtual function	
		int evaluate();
};

#endif