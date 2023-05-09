#include <iostream>
#include <ctime>
using namespace std;


//function definitions
int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);

//-------------------------//
//------Main function------//
//-------------------------//
int main()
{
	//game scores
	int humanScore = 0,
		computerScore = 0;

	do
	{
		//human play
		humanScore    = humanScore    + humanTurn(humanScore);
		

		//game end check
		if(humanScore>=100){
			cout<<"You won the game!"<<endl;
			break;
		}
		cout<<"Your score is "<<humanScore<<" computer's turn.\n\n"<<endl;


		//computer play
		computerScore = computerScore + computerTurn(computerScore);
		

		//game end check
		if(computerScore>=100){
			cout<<"computer won the game!"<<endl;
			break;
		}
		cout<<"Computer's score is "<<computerScore<<" your turn.\n\n"<<endl;

	}while(1);

	return 0;
}

//-------------------------//
//--------Functions--------//
//-------------------------//

//human play function
int humanTurn(int humanTotalScore)
{
	char input;     //roll or hold inputs
	int  random;	//rolled number
	int  score = 0;	//instant score
	srand(time(0));

	do
	{
		cout<<"Score is "<<score<<endl;

		//player select roll or hold
		cout<<"If you want roll type 'r' , if you want hold type 'h'."<<endl;
		cin>>input;

		//player rolled
		if(input == 'r'){
			random = 1+rand()%5;
			cout<<"You rolled "<<random<<endl;

			//rolled 1 and lose turn
			if(random == 1){
				score = 0;
				break;
			}

			//add the rolled number that is not 1 to score
			else{
				score = score + random;
			}
		}

		//player holded score
		if(input == 'h'){
			break;
		}
	}while(1);
	return score;
}

//computer play function
int computerTurn(int computerTotalScore)
{
	int random1;	//computer select roll(1) or hold(0) 
	int random;		//rolled number
	int score = 0;	//instant score
	srand(time(0));

	do
	{
		cout<<"Computer score is "<<score<<endl;

		//computer select roll or hold
		random1 = rand()%1;

		//computer rolled
		if(random1 == 1){
			random = 1+rand()%5;
			cout<<"Computer rolled "<<random<<endl;

			//computer rolled 1 and lose turn
			if(random == 1){
				score = 0;
				break;
			}

			//computer rolled number that is not 1
			else{
				score = score + random;
			}
		} 

		//computer holded
		if(random1 == 0){
			break;
		}
	}while(1);
	return score;
}
