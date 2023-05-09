#include "humanic.h"
#include "robocop.h"

//-------------------CONSTRUCTOR-------------------//
robocop::robocop()
{
	setType(1);
	setHit(100);
	setStrength(10);
}


//-----------------ATTACK FUNCTION-----------------//
int robocop::getDamage()
{
	//total damage in one attack
	int damage;
	
	//damage algorithm
	damage = (rand() % getStrength()) + 1;

	//Tactical attack
	if(nuke()){
		cout<<getType()<<" inflicting a tactical nuke attack!"<<endl;
		damage = damage + 50;
	}
	
	cout << getType() << " attacks for " <<
	damage << " points!" << endl;

	return damage;
}

//-------------------TACTICAL ATTACK FUNCTION-------------------//
//---------with 10% chance robot can bobus 50 damage-----------//
bool robocop::nuke()
{
	int r = rand()%10;
	if(r == 1)
		return true;
	return false;
}