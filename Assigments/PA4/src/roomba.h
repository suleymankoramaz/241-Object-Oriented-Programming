#ifndef ROOMBA_H
#define ROOMBA_H

#include <iostream>
#include "Robot.h"
#include "roomba.h"
using namespace std;

class roomba : public Robot
{
public:
	roomba();
	int getDamage();
private:
	int type;
	int strength;
	int hitpoints;
};

#endif