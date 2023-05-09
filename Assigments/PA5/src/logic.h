#ifndef LOGIC_H
#define LOGIC_H
#include <string>
#include <vector>
#include "gate.h"
using namespace std;

class logic
{
	public:
		//default constructor 
		logic(){};

		//function reads circuit.txt file
		void readfile_circuit();

		//function reads input.txt file and print outputs
		void program();

		//functions create and return gate pointer
		gate* create_gate(vector<string> ids,string name);
		gate* create_gate_io(string name,int type);

		//function print the output to terminal
		void print_terminal(int out);
	private:
		//vector of input gates
		vector<gate*> inputs;

		//vector of output gates
		vector<gate*> outputs;

		//vector of all gates
		vector<gate*> gates; 

		//pointer of decoder
		gate* my_decoder;

		//index of flipflop in gates vector
		int ff_index;
};

#endif