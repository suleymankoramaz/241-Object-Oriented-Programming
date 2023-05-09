#include "bulldozer.h"
#include "Robot.h"


//-------------------CONSTRUCTOR-------------------//
bulldozer::bulldozer()
{
	setType(3);
	setHit(100);
	setStrength(10);
}

//-----------------ATTACK FUNCTION-----------------//
int bulldozer::getDamage()
{
	//total damage in one attack
	int damage;	
	
	//damage algorithm
	damage = (rand() % getStrength()) + 1;
	cout << getType() << " attacks for " <<
	damage << " points!" << endl;

	return damage;
}