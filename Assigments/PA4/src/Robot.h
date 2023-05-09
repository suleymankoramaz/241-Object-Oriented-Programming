#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
using namespace std;

class Robot
{
public:
	Robot(){};
	virtual int getDamage() = 0;

	int getHit();
	int getStrength();
	string getType();
	
	void setType(int newType);
	void setHit(int newHit);
	void setStrength(int newStrength);
	
	friend void match(Robot&r1,Robot& r2);
private:
	int type;
	int strength;
	int hitpoints;
};

#endif