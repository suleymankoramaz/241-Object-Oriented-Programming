#ifndef SPARSEVECTOR_H
#define SPARSEVECTOR_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class SparseVector
{
	public:
		//Contructors
		SparseVector();
		SparseVector(string filename);

		//Operator Overloads
		SparseVector operator+(const SparseVector& v1)const;
		SparseVector operator-(const SparseVector& v1)const;
		SparseVector operator-()const;
		void operator=(SparseVector v);
		friend ostream& operator<<(ostream& outs,const SparseVector& v);

		//Class Functions
		static double dot(const SparseVector& v1,const SparseVector& v2);
		int finder(int data)const;
		bool control(int indx)const;
		void clean();

		//Get Functions
		double getData(int indx)const;
		int getIndex(int indx)const;
		int getSize()const; 

		//Set Funtctions
		void setData(double dt);
		void setIndex(int dt);
	private:
		//Holds data
		vector<double> data;

		//Holds index of data
		vector<int> index;  
};

#endif