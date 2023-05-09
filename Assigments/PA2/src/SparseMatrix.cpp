#include "SparseMatrix.h"
#include "SparseVector.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//--------------------//
//Default Constructor.//
//--------------------//
SparseMatrix::SparseMatrix(){}

//-----------------------------------------------//
//Constructor takes a string and fills the matrix.//
//-----------------------------------------------//
SparseMatrix::SparseMatrix(string filename)
{
	ifstream cinfile;
	ofstream temp; 
	cinfile.open(filename);
	int a;
	char c;
	string s;

	do{
		cinfile>>a;               //taking row
		getline(cinfile,s);  	  //taking vector of row as a string
		temp.open("temp");        //open txt file for writing
		temp<<s<<endl;		   	  //writing string to file
		s.erase(0,1);	    	  //erasing first element of string because it is " "(space).
		row.push_back(a);   	  //filling row vector
		SparseVector tmp("temp"); //Creating new SparseVector object (tmp) with temporary file
		int x = remove("temp");   //removing temporary file
		column.push_back(tmp);    //filling column vector(that holds vector of rows) with tmp objects
		temp.close();
	}while(!cinfile.eof());

	cinfile.close();
}

//------------------------------------//
//operator+()-------------------------//
//Adds two SparseMatrix objects.------//
//Creates another SparseMatrix object.//
//------------------------------------//
SparseMatrix SparseMatrix::operator+(const SparseMatrix& v)const
{
	SparseMatrix sum;

	int control, 	     //data for control if rows are the same
		temp1;  	     //data for using in index sort(row holder)
	SparseVector temp,	 //data for fill column vector 
				 temp2;  //data for using in row sort(column holder)

	//First matrix elements			 
	for(int i=0;i<row.size();i++){
		sum.row.push_back(row[i]);
		sum.column.push_back(column[i]);
	}

	//Second matrix elemets
	for(int i=0;i<v.row.size();i++){
		control=0;

		//control common row
		for(int j=0;j<sum.row.size();j++){

			//if rows are the same add two vector of rows
			if(v.row[i]==sum.row[j]){
				temp.clean();
				temp = sum.column[j];
				sum.column[j].clean();
				sum.column[j]=temp+v.column[i];
				control++;
			}
		}
		//if rows aren't the same 
		if(control==0){
			sum.row.push_back(v.row[i]);
			sum.column.push_back(v.column[i]);
		}
	}

	//Row sort process
	for(int i=0;i<sum.row.size()-1;i++){
		for(int j=0;j<sum.row.size()-1;j++){
			if(sum.row[j]>sum.row[j+1]){
				temp1=sum.row[j];
				temp2.clean();
				temp2 = sum.column[j];
				sum.row[j]=sum.row[j+1];
				sum.column[j].clean();
				sum.column[j]=sum.column[j+1];
				sum.row[j+1]=temp1;
				sum.column[j+1].clean();
				sum.column[j+1]=temp2;
			}
		}
	}
	return sum;
}

//----------------------------------------//
//operator-()-----------------------------//
//Subtracts one SparseMatrix from another.//
//Creates another SparseMatrix object.----//
//----------------------------------------//
SparseMatrix SparseMatrix::operator-(const SparseMatrix& v)const
{
	SparseMatrix diff;

	int control,     	//data for control if rows are the same
		temp1;			//data for using in row sort(row holder)
	SparseVector temp,  //data for fill column vector
				 temp2; //data for using in row sort(column holder)

	//First matrix elements			 
	for(int i=0;i<row.size();i++){
		diff.row.push_back(row[i]);
		diff.column.push_back(column[i]);
	}

	//Second matrix elemets
	for(int i=0;i<v.row.size();i++){
		control=0;

		//control common row
		for(int j=0;j<diff.row.size();j++){
			//if rows are the same 
			if(v.row[i]==diff.row[j]){
				temp.clean();
				temp = diff.column[j];
				diff.column[j].clean();
				diff.column[j]=temp-v.column[i];
				control++;
			}
		}
		//if rows aren't the same subtract a vector from another
		if(control==0){
			diff.row.push_back(v.row[i]);
			diff.column.push_back(-v.column[i]);
		}
	}

	//Row sort process
	for(int i=0;i<diff.row.size()-1;i++){
		for(int j=0;j<diff.row.size()-1;j++){
			if(diff.row[j]>diff.row[j+1]){
				temp1=diff.row[j];
				temp2.clean();
				temp2 = diff.column[j];
				diff.row[j]=diff.row[j+1];
				diff.column[j].clean();
				diff.column[j]=diff.column[j+1];
				diff.row[j+1]=temp1;
				diff.column[j+1].clean();
				diff.column[j+1]=temp2;
			}
		}
	}
	return diff;
}

//--------------------------------------------------------//
//operator*()---------------------------------------------//
//Multiplies two matrices.(Regular matrix multiplication).//
//Creates another SparseMatrix object.--------------------//
//--------------------------------------------------------//
SparseMatrix SparseMatrix::operator*(const SparseMatrix& v)const
{
	SparseMatrix rtn;   //Return matrix
	SparseMatrix temp;	//Temporary matrix that holds transpos of second matrix
	SparseVector temp2; //Temporary vector for fill return.column vector

	int max = row[row.size()-1]; //Data that hold maximum index of rows
	double temp1; //temporary data that holds dot product results

	temp=v.transpos();	

	//Finding max value
	for(int i=0;i<column.size();i++){
		for(int j=0;j<column[i].getSize();j++){
			if(column[i].getIndex(j)>max)
				max = column[i].getIndex(j);
		}
	}
	max++; //For check last element.For example if max=5 and row=5.

	for(int i=0;i<max;i++){

		//control if first matrix rows have i value
		if(control(i)){
			rtn.row.push_back(i); //fill return row vector
			for(int j=0;j<max;j++){
				//control if second matrix rows have j value
				if(temp.control(j)){

					//dot product
					temp1=dot(column[finder(i)],temp.column[temp.finder(j)]);
					temp2.setIndex(j);
					temp2.setData(temp1);
				}
			}
			//fill column vector
			rtn.column.push_back(temp2);
			temp2.clean();
		}
	}
	return rtn;
}

//------------------------------------//
//operator-()-------------------------//
//Negates elements of of a matrix.----//
//Creates another SparseMatrix object.//
//------------------------------------//
SparseMatrix SparseMatrix::operator-()const
{
	SparseMatrix neg;

	//Negates elemets
	for(int i=0;i<row.size();i++){
		neg.row.push_back(row[i]);
		neg.column.push_back(-column[i]);
	}
	return neg;
}

//-----------------------//
//operator=()------------//
//Assigment operator.----//
//Usage matrix1 = matrix2// 
//-----------------------//
void SparseMatrix::operator=(SparseMatrix v)
{

	//If matrix isn't empty
	if(row.size()!=0){
		for(int i=0;i<row.size();i++){
			row.pop_back();
			column.pop_back();
		}
	}

	//Fill row vector
	for(int i=0;i<v.row.size();i++){
		row.push_back(v.row[i]);
	}

	//Fill column vector
	for(int i=0;i<v.row.size();i++){
		column.push_back(v.column[i]);
	}
}

//----------------------------------------------------------//
//operator<<(ostream)---------------------------------------//
//Sends contents of a SparseMatrix to a std::ostream object.//
//----------------------------------------------------------//
ostream& operator<<(ostream& outs,const SparseMatrix& v)
{
	for(int i=0;i<v.row.size();i++){
		outs<<v.row[i]<<" "<<v.column[i];
	}
	return outs;
}

//-----------------------------//
//transpos() function.---------//
//Returns a transpos of matrix.//
//-----------------------------//
SparseMatrix SparseMatrix::transpos()const
{
	SparseMatrix transpos;  //return matrix
	SparseVector temp;		//temporary SparseVector object for filling column vector

	int max = row[row.size()-1]; //Data that hold maximum index of rows

	//Finding max value
	for(int i=0;i<column.size();i++){
		for(int j=0;j<column[i].getSize();j++){
			if(column[i].getIndex(j)>max)
				max = column[i].getIndex(j);
		}
	}

	//Loop for rows
	for(int i=0;i<=max;i++){
		//Loop for columns
		for(int j=0;j<=max;j++){
			//control if matrix row vector has j value and column in there index vector has i value
			if(control(j)&&column[finder(j)].control(i)){
				temp.setIndex(row[finder(j)]);
				temp.setData(column[finder(j)].getData(column[finder(j)].finder(i)));
			}			
		}	
		//Control temporary vector has data
		if(temp.getSize()!=0){
			transpos.column.push_back(temp);
			temp.clean();
			transpos.row.push_back(i);
		}	
	}
	return transpos;
}	

//----------------//
//HELPER FUNCTIONS//
//----------------//

//--------------------------------------------------------------------------------//
//Function that takes row index as a integer and control if matrix has that index.//
//--------------------------------------------------------------------------------// 
bool SparseMatrix::control(int rw)const
{
	for(int i=0;i<row.size();i++){
		if(row[i]==rw)
			return true;
	}
	return false;
}

//-----------------------------------------------------------------------------//
//Funtion that takes index as a integer and returns the location of that index.//
//-----------------------------------------------------------------------------//
int SparseMatrix::finder(int rw)const
{
	for(int i=0;i<row.size();i++){
		if(row[i]==rw)
			return i;
	}
	return -1;
}