#include "SparseVector.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------//
//Default Constructor.//
//--------------------//
SparseVector::SparseVector(){}

//----------------------------------------------//
//Constructor takes string and fills the vector.//
//----------------------------------------------//
SparseVector::SparseVector(string filename)
{
	ifstream cinfile;
	cinfile.open(filename);

	int a;
	char b;
	double c;
	cinfile>>a>>b>>c;

	//While loop takes data from file until end of the file.
	while(!cinfile.eof()){
		index.push_back(a);
		data.push_back(c);
		cinfile>>a>>b>>c;
	}

	cinfile.close();
}

//------------------------------------//
//operator+()-------------------------//
//Adds two SparseVector objects.------//
//Creates another SparseVector object.//
//------------------------------------//
SparseVector SparseVector::operator+(const SparseVector& v)const
{
	SparseVector sum;

	int     control, //data for control if index is common
			temp1;   //data for using in index sort(index holder)
	double 	temp2;   //data for using in index sort(data holder)

	//First vector elemets
	for(int i=0;i<index.size();i++){
		sum.data.push_back(data[i]);
		sum.index.push_back(index[i]);
	}

	//Second vector elemens
	for(int i=0;i<v.index.size();i++){
		control=0;

		//control common index
		for(int j=0;j<sum.index.size();j++){
			//if indexes are the same add two data
			if(v.index[i]==sum.index[j]){
				sum.data[j]=sum.data[j]+v.data[i];
				control++;
			}
		}
		//if indexes aren't the same
		if(control==0){
			sum.data.push_back(v.data[i]);
			sum.index.push_back(v.index[i]);
		}
	}

	//Index sort process
	for(int i=0;i<sum.index.size()-1;i++){
		for(int j=0;j<sum.index.size()-1;j++){
			if(sum.index[j]>sum.index[j+1]){
				temp1=sum.index[j];
				temp2=sum.data[j];
				sum.index[j]=sum.index[j+1];
				sum.data[j]=sum.data[j+1];
				sum.index[j+1]=temp1;
				sum.data[j+1]=temp2;
			}
		}
	}
	return sum;
}

//----------------------------------------//
//operator-()-----------------------------//
//Subtracts one SparseVector from another.//
//Creates another SparseVector object.----//
//----------------------------------------//
SparseVector SparseVector::operator-(const SparseVector& v)const
{
	SparseVector diff;

	int     control,//data for control if index is common
			temp1;	//data for using in index sort(index holder)
	double 	temp2;	//data for using in index sort(data holder)

	//First vector elements
	for(int i=0;i<index.size();i++){
		diff.data.push_back(data[i]);
		diff.index.push_back(index[i]);
	}

	//Second vector elements
	for(int i=0;i<v.index.size();i++){
		control=0;

		//control common index
		for(int j=0;j<diff.index.size();j++){
			//if indexes are the same subtract data from another
			if(v.index[i]==diff.index[j]){
				diff.data[j]=diff.data[j]-v.data[i];
				control++;
			}
		}
		//if indexes aren't the same(second elements are negative)
		if(control==0){
			diff.data.push_back(-v.data[i]);
			diff.index.push_back(v.index[i]);
		}
	}

	//Index sort process
	for(int i=0;i<diff.index.size()-1;i++){
		for(int j=0;j<diff.index.size()-1;j++){
			if(diff.index[j]>diff.index[j+1]){
				temp1=diff.index[j];
				temp2=diff.data[j];
				diff.index[j]=diff.index[j+1];
				diff.data[j]=diff.data[j+1];
				diff.index[j+1]=temp1;
				diff.data[j+1]=temp2;
			}
		}
	}
	return diff;
}

//------------------------------------//
//operator-()-------------------------//
//Negates elemens of SparseVector.----//
//Creates another SparseVector object.//
//------------------------------------//
SparseVector SparseVector::operator-()const
{
	SparseVector neg;

	//Negates elements.
	for(int i=0;i<index.size();i++){
		neg.index.push_back(index[i]);
		neg.data.push_back(-data[i]);
	}
	return neg;
}

//-------------------//
//operator=()--------//
//Assigment operator.//
//-------------------//
void SparseVector::operator=(SparseVector v)
{
	//If vector is not empty.
	clean();

	//Fill index vector
	for(int i=0;i<v.index.size();i++){
		index.push_back(v.index[i]);
	}
	//Fill data vector
	for(int i=0;i<v.index.size();i++){
		data.push_back(v.data[i]);
	}
}

//----------------------------------------------------------//
//operator<<(ostream)---------------------------------------//
//Sends contents of a SparseVector to a std::ostream object.//
//----------------------------------------------------------//
ostream& operator<<(ostream& outs,const SparseVector& v)
{
	for(int i=0;i<v.index.size();i++){
		if(v.data[i]!=0){
			outs<<v.index[i]<<":"<<v.data[i]<<" ";
		}	
	}
	outs<<endl;
	return outs;
}

//------------------------------------------------------------------//
//dot() function----------------------------------------------------//
//Calculates the dot product(inner product) of two SparseVector.----//
//Function is static because usage: dot(v1,v2).(Call without object.//
//------------------------------------------------------------------
static double dot(const SparseVector& v1,const SparseVector& v2)
{
	double dot=0;
	for(int i=0;i<v1.getSize();i++){
		for(int j=0;j<v2.getSize();j++){

			//Checks if indexes are the same
			if(v1.getIndex(i)==v2.getIndex(j))
				dot = dot+(v1.getData(i)*v2.getData(j));
		}
	}
	return dot;
}	


//-------------//
//SET FUNCTIONS//
//-------------//
void SparseVector::setData(double dt)
{
	data.push_back(dt);
}
void SparseVector::setIndex(int dt)
{
	index.push_back(dt);
}

//-------------//
//GET FUNCTIONS//
//-------------//
double SparseVector::getData(int indx)const
{
	return data[indx];
}
int SparseVector::getIndex(int indx)const
{
	return index[indx];
}
int SparseVector::getSize()const
{
	return index.size();
}

//----------------//
//HELPER FUNCTIONS//
//----------------//

//----------------------------------------------------------------------------//
//Function that takes index as a integer and control if vector has that index.//
//----------------------------------------------------------------------------//
bool SparseVector::control(int indx)const
{
	for(int i=0;i<index.size();i++){
		if(index[i]==indx)
			return true;
	}
	return false;
}

//------------------------------------------------------------------------------//
//Function that takes index as a integer and returns the location of that index.//
//------------------------------------------------------------------------------//
int SparseVector::finder(int dt)const
{
	for(int i=0;i<index.size();i++){
		if(index[i]==dt)
			return i;
	}
	return -1;
}

//----------------------------------------------------------//
//Function that clean the vector for possible memory errors.//
//----------------------------------------------------------//
void SparseVector::clean()
{
	//Data holds index.size() because it is changing.
	int temp=index.size();

	for(int i=0;i<temp;i++){
		index.pop_back();
		data.pop_back();
	}
}
