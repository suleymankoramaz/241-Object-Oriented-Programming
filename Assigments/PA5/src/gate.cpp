#include <string>
#include "gate.h"
#include <vector>
#include <iostream>
using namespace std;

//-----------SETTERS-------------//

void gate::setData(int newData){data = newData;}

void gate::setType(int t){type = t;}
	
void gate::setName(string newName){name = newName;}

//void gate::setA(int a1){a = a1;}

void gate::setCounter(int c){counter = c;}

void gate::setIn(vector<gate*> ins)
{
	for(int i=0;i<ins.size();i++)
		inputs.push_back(ins[i]);
}

//-----------GETTERS-------------//

int gate::getData(){return data;}

int gate::getType(){return type;}

//int gate::getA(){return a;}

void gate::counter_(){counter++;}

int gate::getCounter(){return counter;}

string gate::getName(){return name;}

gate* gate::getIn(int index)
{
	return inputs[index];
}

//-----OUTPUT OF FLIPFLIP--------//
//int gate::a = 0;
