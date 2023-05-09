#include "Robot.h"
#include <string>
#include <iostream>
using namespace std;

//---------------GETTER FUNCTIONS------------------//
int Robot::getHit(){return hitpoints;}

int Robot::getStrength(){return strength;}

string Robot::getType()
{
	switch (type)
		{
			case 0: return "optimusprime";
			case 1: return "robocop";
			case 2: return "roomba";
			case 3: return "bulldozer";
		}
	return "unknown";
}

//---------------SETTER FUNCTIONS------------------//
void Robot::setHit(int newHit){hitpoints = newHit;}

void Robot::setType(int newType){type = newType;}

void Robot::setStrength(int newStrength){strength = newStrength;}



//----------------------MATCH FUNCTION------------------------//
//in this function robots fight by attacing each other in turn//
//-------------------until one of them dies-------------------//
void match(Robot& r1, Robot& r2)
{	
	//loop until one of them dies
	while(r1.getHit()>0 && r2.getHit()>0){

		//print hitpoints 
		cout<<endl<<r1.getType()<<" hitpoints = "<<r1.getHit()<<endl;
		cout<<r2.getType()<<" hitpoints = "<<r2.getHit()<<endl<<endl;

		//First robot attack 
		r2.setHit(r2.getHit() - r1.getDamage());

		//Control if second robot alive
		if(r2.getHit() <= 0)
			break;

		//Second robot attack
		r1.setHit(r1.getHit() - r2.getDamage());
	}

	//Second robot won
	if(r1.getHit()<=0)
		cout<<r2.getType()<<" won!"<<endl;
	//First robot won
	else
		cout<<r1.getType()<<" won!"<<endl;
}