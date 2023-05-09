#include <iostream>
#include <cstdlib>
using namespace std;
//------------------------------------------------------------------------------------//
//Class that holds hot dog stands ID and how many hot dogs the stand has sold that day//
//------------------------------------------------------------------------------------//

class HotDogStand
{
public:
	HotDogStand();
	HotDogStand(int newID, int newNumSold);
	int getID();
	void setID(int newID);
	void justSold();
	int getNumSold();
	static int getTotalSold();

private:
	static int totalSold;
	int numSold;
	int ID;
};

int HotDogStand::totalSold = 0;

//default constructor initializes the ID and numSold to zero
HotDogStand::HotDogStand()
{
	numSold=0;
	ID=0;
}

//contructor initializes the ID and numSold
HotDogStand::HotDogStand(int newID, int newNumSold)
{
	numSold=newNumSold;
	ID=newID;
}

//returns the ID number of this stand
int HotDogStand::getID()
{
	return ID;
}

//set ID number of this stand
void HotDogStand::setID(int newID)
{
	ID=newID;
}

//increments the numSold this stand has sold by one
void HotDogStand::justSold()
{
	numSold++;
	totalSold++;
}

//return numsold this stand
int HotDogStand::getNumSold()
{
	return numSold;
}

//return total number of hot dogs sold by all stands
int HotDogStand::getTotalSold()
{
	return totalSold;
}

int main()
{
	HotDogStand s1(1,0),s2(2,0),s3(3,0);

	s1.justSold();
	s2.justSold();
	s3.justSold();
	s3.justSold();
	s3.justSold();
	s2.justSold();

	cout<<"Stand "<<s1.getID()<<" sold "<<s1.getNumSold()<<endl;
	cout<<"Stand "<<s2.getID()<<" sold "<<s2.getNumSold()<<endl;
	cout<<"Stand "<<s3.getID()<<" sold "<<s3.getNumSold()<<endl;
	cout<<"Total sold = "<<s1.getTotalSold()<<endl;
	cout<<"Total sold = "<<HotDogStand::getTotalSold()<<endl;

	s3.justSold();
	s2.justSold();
	s1.justSold();
	s1.justSold();

	cout<<"Stand "<<s1.getID()<<" sold "<<s1.getNumSold()<<endl;
	cout<<"Stand "<<s2.getID()<<" sold "<<s2.getNumSold()<<endl;
	cout<<"Stand "<<s3.getID()<<" sold "<<s3.getNumSold()<<endl;
	cout<<"Total sold = "<<s1.getTotalSold()<<endl;
	cout<<"Total sold = "<<HotDogStand::getTotalSold()<<endl;
	return 0;
}