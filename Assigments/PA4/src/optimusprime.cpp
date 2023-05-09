#include "humanic.h"
#include "optimusprime.h"


//-------------------CONSTRUCTOR-------------------//
optimusprime::optimusprime()
{
	setType(0);
	setHit(100);
	setStrength(10);
}

//-----------------ATTACK FUNCTION-----------------//
int optimusprime::getDamage()
{
	//total damage in one attack
	int damage;

	//damage algorithm
	damage = (rand() % getStrength()) + 1;

	//Attack twice
	if(strongAttack()){
		cout<<getType()<<" inflict a strong attack!"<<endl;
		damage = damage*2;
	}

	//Tactical attack
	if(nuke()){
		cout<<getType()<<" inflicting a tactical nuke attack!"<<endl;
		damage = damage + 50;
	}

	cout << getType() << " attacks for " <<
	damage << " points!" << endl;

	return damage;
}

//-------------------STRONG ATTACK FUNCTION-------------------//
//---------with 15% chance robot can attack twice-------------//
bool optimusprime::strongAttack()
{
	int r = rand()%100;
	if(r<15)
		return true;
	return false;
}

//-------------------TACTICAL ATTACK FUNCTION-------------------//
//---------with 10% chance robot can bobus 50 damage-----------//
bool optimusprime::nuke()
{
	int r = rand()%10;
	if(r == 1)
		return true;
	return false;
}