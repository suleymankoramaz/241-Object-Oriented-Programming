#ifndef ROBOCOP_H
#define ROBOCOP_H

#include <iostream>
#include "humanic.h"
#include "robocop.h"
using namespace std;

class robocop : public humanic
{
public:
	robocop();
	int getDamage();
	bool nuke();
private:
	int type;
	int strength;
	int hitpoints;
	
};

#endif