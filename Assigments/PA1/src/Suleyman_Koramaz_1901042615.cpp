#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void randG(vector<int>& secret,int size);
void input(vector<int>& user,vector<char>& control);
void print(const vector<int> secret,const vector<int>& user,bool& end);
void clean(vector<int>& user,vector<char>& control);
int error_input(const vector<int> secret,const vector<char> control);

int main(int argc,char** argv)
{
	//----------------ERROR CONTROL MAIN ARGUMENTS----------------//
	//less or more parameters
	if(argc!=3){
		cout<<"E0"<<endl;
		return 0;
	}
	//wrong parameters 
	if(argv[1][0]!='-' || 
	  (argv[1][1]!='r' && argv[1][1]!='u') ){
		cout<<"E0"<<endl;
		return 0;     
	}
	//wrong parameter value fallowing -r
	if(argv[1][1]=='r'){
		if(argv[2][1]!='\0'){
			cout<<"E0"<<endl;
			return 0;
		}
		if(argv[2][0]=='0'){
			cout<<"E0"<<endl;
			return 0;
		}
	}
	//wrong parameter value fallowing -u
	if(argv[1][1]=='u'){
		int j=1;
		do{
			for(int i=0;i<j;i++){
				if(argv[2][i]==argv[2][j]){
					cout<<"E0"<<endl;
			        return 0;
				}
			}
		    j++;
		}while(argv[2][j]!='\0');	
	}
    //------------------------------------------------------------//

	srand(time(0));       //function for random number generator
	int N,                //secret number size
		i=0,              //value used in do-while loop
		itrtions = 0,     //user iterations counter
		err;              //value used for check error in user input 
	bool end;             //value controls end (win or lose)

	vector<int> secret,   //vector that holds secret number
				user;     //vector that holds user input(int)
	vector<char> control; //vector that holds user input(char)
	
	//random secret number generator
	if(argv[1][1]=='r'){
		N = (int)argv[2][0]-(int)'0';
		randG(secret,N);
	}
	//taking secret number from main call argument
	else if(argv[1][1]=='u'){

		//push 'char' values in secret after convert 'int'
		do{	
			secret.push_back((int)argv[2][i]-(int)'0'); 
			i++;
		}while(argv[2][i]!='\0');
        
		N = secret.size();
	}
	for(int i=0;i<secret.size();i++){
		cout<<secret[i];
	}
	cout<<endl;
	//game lasting max 100 iterations
	while(itrtions<101){
		input(user,control); //user input

		//----error check for input----//
		err = error_input(secret,control);
		if(err==1){    //input has more or less digit
			cout<<"E1"<<endl;
			return 0;
		}
		if(err==2){    //input has non-int value
			cout<<"E2"<<endl;
			return 0;
		}
		if(err==0){    //input is not unique number
			cout<<"E1"<<endl;
			return 0;
		}
		//-----------------------------//

		system("clear\n");       //cleaning terminal after input
		print(secret,user,end);  //print count values (C_exact,C_missplaced) and check end 
		clean(user,control);     //cleaning input vectors for next input
		itrtions++;
		if(end==true){    //user found secret number
			cout<<"FOUND "<<itrtions<<endl;
			break;
		}
	}
	if(end==false)     //user cannot find secret number in 100 iterations 
		cout<<"FAILED"<<endl;
	return 0;
}

//Random secret number generator
void randG(vector<int>& secret,int size)
{
	bool ok;       //value checks number is unique or not
	int count,     //count value for check all digits
	        x;     //random number 
	x=1+rand()%9;          //first number is between 1 and 9 because it cannot be 0
	secret.push_back(x);   //push first number 

    //push other numbers
	for(int i=1;i<size;i++){
		//do-while loop until correct number generated
		do{
			count=0;
			x=rand()%10;    //number is between 0 and 9
			secret.push_back(x);
            //for loop to compare the generated number with the previous ones
			for(int j=0;j<i;j++){
				if(secret[i]==secret[j])
					count++;
			}
			//check number is okey or not okey
			if(count==0){
				ok=true;
			}		
			else{
				ok=false;
				secret.pop_back(); //if number is not okey remove 
			}
		}while(ok!=true);
	}
}
//User input function
void input(vector<int>& user,vector<char>& control)
{
	int x;    //Converted int input digit
	char ch;  //input digit
	//do-while loop push user input to vectors
	do{
		cin.get(ch);  
		if(ch!=' ' && ch!='\n'){
			x = (int)ch - (int)'0';   //converting int
			user.push_back(x);        //push converted input digit to user input vector
			control.push_back(ch);    //push input digit to user input vector(char vector)
		}
    }while('\n' != ch);  //loop ended when user input end
}
//function prints count values and checks end
void print(const vector<int> secret,const vector<int>& user,bool& end)
{
	int countEx=0, //C_exact
		countMp=0; //C_missplaced

    //loop that check input digits C_exact or C_missplaced
	for(int i=0;i<secret.size();i++){
		if(user[i]==secret[i])
			countEx++;
		else{
			//loop compares instant digit with all digits
			for(int j=0;j<secret.size();j++){
				if(user[i]==secret[j])
					countMp++;
			}
		}	
	}
	cout<<countEx<<" "<<countMp<<endl; //printing results

	//end control
	if(countEx==secret.size() && countMp==0)
		end=true;
	else
		end=false;
}
//Clean user input vector for next input
void clean(vector<int>& user,vector<char>& control)
{
	int temp=user.size();   //value that holds vector size
	for(int i=0;i<temp;i++)
	{
		user.pop_back();
		control.pop_back();
	}
}
//error control function for user input
int error_input(const vector<int> secret,const vector<char> control)
{
	//control digits int or not for all digits
	for(int i=0;i<control.size();i++){
		if(control[i]>57 || control[i]<48)
			return 2;
	}

	//control input size equal to secret number size or not
	if(control.size()!=secret.size())
		return 1;
	int j=1; //value for do-while loop that holds instant vector digit
	do{
		//loop that control instant vector digit equal to previous vector digits (unique number check)
		for(int i=0;i<j;i++){
			if(control[i]==control[j]){
		        return 0;
			}
		}
	    j++;
	}while(control[j]!='\0');  //loop ends when vector end

	return 3; //if there is no error 
} 