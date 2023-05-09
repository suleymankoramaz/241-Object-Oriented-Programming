#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
	int i;
	int current;
	int numSuitors;

	cout<<"Enter number of suitors:";
	cin>>numSuitors;

	vector<int> suitors(numSuitors);

	for(int i=0;i<numSuitors;i++){
		suitors[i] = i+1;
	}

	if(numSuitors<=0)
		cout<<"Not enough suitors."<<endl;

	else if(numSuitors==1)
		cout<<"You would stand first in line."<<endl;

	else{
		current=0;
		while(suitors.size()>1){
			for(int i=0;i<2;i++){
				current++;
				if(current==suitors.size())
					current=0;
			}
			suitors.erase(suitors.begin()+current);
			if(current==suitors.size())
				current=0;
		}
		cout<<"To win the princiess,you should stand in position "<<suitors[0]<<endl;
	}
	return 0;
}