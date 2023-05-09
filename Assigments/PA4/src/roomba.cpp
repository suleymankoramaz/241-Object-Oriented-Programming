#include "Robot.h"
#include "roomba.h"


//-------------------CONSTRUCTOR-------------------//
roomba::roomba()
{
	setType(2);
	setHit(100);
	setStrength(5);
}

//-----------------ATTACK FUNCTION-----------------//
int roomba::getDamage()
{
	//total damage in one attack
	int damage;
	
	//damage algorithm
	cout<<getType()<<" attacks twice!"<<endl;
	damage = (rand() % getStrength()) + 1;
	//ROOMBA ATTACK TWICE
	damage = damage + (rand() % getStrength()) + 1;

	cout << getType() << " attacks for " <<
	damage << " points!" << endl;

	return damage;
}