#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include <iostream>
#include "humanic.h"
#include "optimusprime.h"
using namespace std;

class optimusprime : public humanic
{
public:
	optimusprime();
	int getDamage();
	bool strongAttack();
	bool nuke();
private:
	int type;
	int strength;
	int hitpoints;
	
};

#endif