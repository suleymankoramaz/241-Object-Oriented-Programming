#ifndef GATE_H
#define GATE_H
#include <string>
#include <vector>

using namespace std;
class gate
{
	public:
		//default constructor of base class
		gate(){};

		//----------------SETTERS----------------//

		//set name
		void setName(string newName);
		//-------------------------//

		//set data value
		void setData(int newData);
		//-------------------------//

		//set type
		void setType(int t);
		//-------------------------//
		
		//set vector of inputs which connected to that gate
		void setIn(vector<gate*> ins);
		//-------------------------//

		//set counter(for flipflop) 
		void setCounter(int c);
		//---------------------------------------//


		//----------------GETTERS----------------//

		//return name
		string getName();
		//-------------------------//
	
		//return data value
		int getData();
		//-------------------------//

		//return type
		int getType();
		//-------------------------//

		//return vector of inputs which connected to that gate
		gate* getIn(int index);
		//-------------------------//

		//return counter(for flipflop)
		int getCounter();
		//---------------------------------------//


		//---------------FUNCTIONS---------------//

		//increase counter when flipflop evaluated//
		void counter_();
		//----------------------------------------//
	
	
		//virtual function that evaluate value of data from connected inputs//
		//------------------------------------------------------------------//
		virtual int evaluate()=0;
		//------------------------------------------------------------------//

	private:
		//data holds number of evaluate flipflop
		int counter;

		int type;

		//data holds name
		string name;

		//data holds output value 0-1
		int data;

		//vector of inputs which connected to that gate
		vector<gate*> inputs;
};

#endif