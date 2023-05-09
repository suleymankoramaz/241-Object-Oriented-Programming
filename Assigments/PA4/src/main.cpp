#include <iostream>
#include "Robot.h"
#include "bulldozer.h"
#include "roomba.h"
#include "optimusprime.h"
#include "humanic.h"
#include "robocop.h"
using namespace std;

int main()
{
	optimusprime r0;
	robocop r1;
	roomba r2;
	bulldozer r3;

	cout<<"Type of r0 : "<<r0.getType()<<endl
	    <<"Hitpoints of r0 : "<<r0.getHit()<<endl
	    <<"Strength of r0 : "<<r0.getStrength()<<endl<<endl;

	cout<<"Type of r1 : "<<r1.getType()<<endl
	    <<"Hitpoints of r1 : "<<r1.getHit()<<endl
	    <<"Strength of r1 : "<<r1.getStrength()<<endl<<endl;

	cout<<"Type of r2 : "<<r2.getType()<<endl
	    <<"Hitpoints of r2 : "<<r2.getHit()<<endl
	    <<"Strength of r2 : "<<r2.getStrength()<<endl<<endl;

	cout<<"Type of r3 : "<<r3.getType()<<endl
	    <<"Hitpoints of r3 : "<<r3.getHit()<<endl
	    <<"Strength of r3 : "<<r3.getStrength()<<endl<<endl;


	match(r0,r1);
	match(r2,r3);

	return 0;
}