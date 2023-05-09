#include <iostream>
using namespace std;

int main()
{
	//value that used for check prime number
	int control;

	//first loop
	for(int i=3 ; i<100 ; i++){

		//control reset
		control = 0;

		//second loop
		for(int j=2 ; j<i ; j++){
			
		    //prime number check
			if(i%j == 0)
				control++;
		}

		//if control is not zero it means one 
		//of the values less than i is the 
		//divisor of i and i is not prime number
		if(control == 0)
			cout<<i<<" "<<endl;
	}
	return 0;
}