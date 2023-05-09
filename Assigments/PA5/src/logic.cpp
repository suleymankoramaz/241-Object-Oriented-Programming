#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//HEADER FILES
#include "logic.h"
#include "gate.h"
#include "input.h"
#include "output.h"
#include "and_gate.h"
#include "or_gate.h"
#include "not_gate.h"
#include "decoder.h"
#include "flipflop.h"

//FUNCTION READ CIRCUIT FILE//
void logic::readfile_circuit()
{
	//open file
	ifstream read;
	read.open("circuit.txt");

	//string holds keyword at the beginning of the file
	string keyword;

	//vector of string that holds string come after keywords
	vector<string> temp_string_vector;

	//temporary string for reading
	string str;

	//read until end of the file
	while(!read.eof()){

		//READ KEYWORD
    	read>>keyword;

    	//KEYWORD CATEGORIZING
   		if(keyword=="INPUT"){

   			//READ UNTIL LINE
   			while((read.peek()!='\n')&&(read.peek()!= EOF)) {

   				//READ INPUT NAMES
     			read>>str;

     			//CREATE INPUT-OUTPUT GATE
     			//SECOND PARAMETER 0 MEANS IT'S INPUT GATE
     			gate* temp = create_gate_io(str,0);

     			//ADD INPUT GATE TO INPUTS VECTOR
     			inputs.push_back(temp);

     			//ADD INPUT GATE TO GATES VECTOR
     			gates.push_back(temp);
    		} 
   		}
   		else if(keyword=="OUTPUT"){

   			//READ UNTIL LINE
   			while((read.peek()!='\n')&&(read.peek()!= EOF)) {
   				
   				//READ INPUT NAMES
     			read>>str;
     			
     			//CREATE INPUT-OUTPUT GATE
     			//SECOND PARAMETER 1 MEANS IT'S OUTPUT GATE
     			gate* temp = create_gate_io(str,1);
     		
     			//ADD OUTPUT GATE TO OUTPUTS VECTOR
     			outputs.push_back(temp);
     			
     			//ADD OUTPUT GATE TO GATES VECTOR
     			gates.push_back(temp);
    		} 
   		}
 
   		else if(keyword=="DECODER"){

   			//READ OUTPUTS TO PASS TO INPUTS
   			for(int i=0;i<outputs.size();i++){
     			read>>str;   			
     		}
   	
   			//INTEGERS THAT HOLDS INDEX OF INPUTS IN GATES VECTOR
   			int x1,x2;
   			while((read.peek()!='\n')&&(read.peek()!= EOF)) {

   				//READ FIRST INPUT
   				read>>str;
   				//FIND INDEX OF FIRST INPUT
   				for(int i=0;i<gates.size();i++){
     				if(gates[i]->getName() == str){		 
     					x1 = i;    					
     				}
     			}
     			//READ SECOND INPUT
     			read>>str;
     			//FIND INDEX OF SECOND INPUT
     			for(int i=0;i<gates.size();i++){
     				if(gates[i]->getName() == str){		 
     					x2 = i;    					
     				}
     			}
    		} 	
    		
    		//VECTOR OF INPUT GATES
			vector<gate*> temp_vector;
			temp_vector.push_back(gates[x1]);
			temp_vector.push_back(gates[x2]);

			//CREATE DECODER GATE
    		my_decoder = new decoder(temp_vector);	
   		}
 	  	
   		else{
   			//CLEAR VECTOR 
   			temp_string_vector.clear();

   			//READ UNTIL END OF THE LINE
   			while((read.peek()!='\n')&&(read.peek()!= EOF)) {

   				//FIRST STRING IS NAME THE OTHERS NAME OF INPUTS
   				read>>str;
   				temp_string_vector.push_back(str);	
    		}    

    		//CREATE GATE
   			gates.push_back(create_gate(temp_string_vector,keyword));
  		} 
	}
	read.close();
}

//FUNCTION READ INPUT FILE, CALCULATE OUTPUTS AND PRINT THEM
void logic::program()
{
	//OPEN FILE
	ifstream read;
	read.open("input.txt");

	//DATA READ FROM FILE
	int in;

	//READ UNTIL FILE
	while(!read.eof()){

		//READ INPUTS
		for(int i=0;i<inputs.size();i++){
			read>>in;
			inputs[i]->setData(in);
		}

		//IF END OF THE FILE BREAK LOOP
		if(read.eof())
			break;
		//---------------------------//

		//OUT IS OUTPUT DATA
		//EVALUATE DECODER
		int out = my_decoder->evaluate();

		//PRINT OUTPUT 
		print_terminal(out);
		//FIND INDEX OF FLIPFLOP IN GATES VECTOR 
		for(int i=0;i<gates.size();i++){
			if(gates[i]->getType() == 5)
				ff_index = i;
		}
		
		//SET DATA OF FLIPFLIP 0 END OF THE EVALUATION
		gates[ff_index]->setCounter(0);
	}
	read.close();
}

//FUNCTION RETURN POINTER OF INPUT AND OUTPUT GATES
gate* logic::create_gate_io(string name,int type)
{
	gate* temp;

	//CREATE GATE
	if(type==0)
		temp = new input(name);
	if(type==1)
		temp = new output(name);
	return temp;
}

//FUNCTION RETURN POINTER OF AND,OR,NOT,FLIPFLOP GATES
gate* logic::create_gate(vector<string> ids,string type)
{	
	gate* temp;

   	//GATE CATEGORIZING
	if(type=="AND"){

		//INDEX OF INPUTS IN GATES VECTOR
		int index1,index2;

		//FIND INDEX OF INPUTS
		for(int j=0;j<gates.size();j++){
			if(gates[j]->getName() == ids[1])
				index1 = j;
		}
		for(int j=0;j<gates.size();j++){
			if(gates[j]->getName() == ids[2])
				index2 = j;
		}

		//VECTOR OF INPUTS
		vector<gate*> temp_vector = {gates[index1],gates[index2]};
		
		//CREATE AND RETURN AND_GATE
		temp = new and_gate(ids[0],temp_vector);
	}
	if(type=="OR"){

		//INDEX OF INPUTS IN GATES VECTOR
		int index1,index2;

		//FIND INDEX OF INPUTS
		for(int j=0;j<gates.size();j++){
			if(gates[j]->getName() == ids[1])
				index1 = j;
		}
		for(int j=0;j<gates.size();j++){
			if(gates[j]->getName() == ids[2])
				index2 = j;
		}

		//VECTOR OF INPUTS
		vector<gate*> temp_vector = {gates[index1],gates[index2]};

		//CREATE AND RETURN OR_GATE
		temp = new or_gate(ids[0],temp_vector);
	}
	if(type=="NOT"){

		//INDEX OF INPUT IN GATES VECTOR
		int index;

		//FIND INDEX OF INPUT
		for(int j=0;j<gates.size();j++){
			if(gates[j]->getName() == ids[1])
				index = j;
		}

		//VECTOR OF INPUTS
		vector<gate*> temp_vector = {gates[index]};

		//CREATE AND RETURN NOT_GATE
		temp = new not_gate(ids[0],temp_vector);
	}
	if(type=="FLIPFLOP"){
		
		//INDEX OF INPUT IN GATES VECTOR
		int index;

		//FIND INDEX OF INPUT
		for(int j=0;j<gates.size();j++){
			if(gates[j]->getName() == ids[1])
				index = j;
		}

		//VECTOR OF INPUTS
		vector<gate*> temp_vector = {gates[index]};
		
		//CREATE AND RETURN FLIPFLOP_GATE
		temp = new flipflop(ids[0],temp_vector);
	}
	return temp;
}

//FUNCTION PRINTS OUTPUT TO TERMINAL 
void logic::print_terminal(int out)
{
	//OUTPUT DATA
	int a1,a2,a3,a4;

	//CALCULATE OUTPUT DATA
	a4 = out%10;
	out = out/10;
	a3 = out%10;
	out = out/10;
	a2 = out%10;
	out = out/10;
	a1 = out%10;
	out = out/10;	

	//PRINT OUTPUT DATA
	cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;
}