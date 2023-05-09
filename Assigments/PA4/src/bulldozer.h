#ifndef BULLDOZER_H
#define BULLDOZER_H

#include <iostream>
#include "bulldozer.h"
#include "Robot.h"
using namespace std;

class bulldozer : public Robot
{
public:
	bulldozer();
	int getDamage();
private:
	int type;
	int strength;
	int hitpoints;
};
#endif