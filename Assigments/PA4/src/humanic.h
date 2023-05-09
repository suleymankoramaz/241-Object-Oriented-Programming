#ifndef HUMANIC_H
#define HUMANIC_H

#include <iostream>
#include "Robot.h"
#include "humanic.h"
using namespace std;

class humanic : public Robot
{
public:
	virtual bool nuke()=0;
};

#endif