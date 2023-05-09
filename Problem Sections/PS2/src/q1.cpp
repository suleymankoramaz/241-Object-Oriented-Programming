#include <iostream>
#include <ctime>
using namespace std;

const int duels = 10000;

void aaronTurn(int aaron,int& bob,int& charlie,int& count);
void bobTurn(int& aaron,int bob,int& charlie,int& count);
void charlieTurn(int& aaron,int& bob,int charlie,int& count);

int main()
{
	srand(time(0));
	int shoot,		
		count,		//value checks that there is only one man left	
		countA=0,	//value checks that how many times Aaron won
		countB=0,	//value checks that how many times Bob won
		countC=0,	//value checks that how many times Charlie won
		aaron,
		bob,
		charlie;	
				
	for(int i=0;i<duels;i++){	//loop simulates 10,000 duels
		count = 3;	//all men are alive
		aaron=1;
		bob=1;
		charlie=1;
		while(count>1){		//loop continuing until just one man is alive

			if(aaron==1)	//Aaron's turn(if he is alive)
				aaronTurn(aaron,bob,charlie,count);
			
			if(bob==1)	//Bob's turn(if he is alive)
				bobTurn(aaron,bob,charlie,count);
			
			if(charlie==1)	//Charlie's turn(if he is alive)
				charlieTurn(aaron,bob,charlie,count);
			
		}//END OF THE DUEL

		if(aaron==1)
			countA++;	//Aaron won
		
		if(bob==1)
			countB++;   //Bob won
		
		if(charlie==1)
			countC++;	//Charlie won
	}//END OF THE 10,000 DUELS

	//Printing results
	cout<<"Aaron won "<<countA<<"/10000 duels."<<endl;
	cout<<"Bob won "<<countB<<"/10000 duels."<<endl;
	cout<<"Charlie won "<<countC<<"/10000 duels."<<endl;
	return 0;
}

void aaronTurn(int aaron,int& bob,int& charlie,int& count)
{
	int shoot;
	if(charlie==1){		//Shoot Charlie if he is alive
		shoot=rand()%3;	//posible 'shoot' values = 0,1,2
		if(shoot==0){	//if shoot is 0 shoot is accurate
			charlie=0;	//Charlie died
			count--;	
		}
	}
	else if(bob==1){	//Shoot Bob if Charlie is dead and Bob is alive 
		shoot=rand()%3;	
		if(shoot==0){
			bob=0;	//Bob died
			count--;
		}
	}
}
void bobTurn(int& aaron,int bob,int& charlie,int& count)
{
	int shoot;
	if(charlie==1){		//Shoot Charlie if he is alive
		shoot=rand()%2;
		if(shoot==0){
			charlie=0;	//Charlie died 
			count--;
		}
	}
	else if(aaron==1){	//Shoot Aaron if Charlie is dead and Aaron is alive
		shoot=rand()%2;
		if(shoot==0){
			aaron=0;	//Aaron died
			count--;
		}
	}
}
void charlieTurn(int& aaron,int& bob,int charlie,int& count)
{
	if(bob==1){		//Shoot Bob if he is live
		bob=0;		//Bob died for sure because Charlie never misses
		count--;
	}
	else if(aaron==1){	//Shoot Aaron if Bob is dead and Aaron is alive
		aaron=0;		//Aaron died
		count--;
	}
}