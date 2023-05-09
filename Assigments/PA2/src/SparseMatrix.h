#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include <vector>
#include <string>
#include <iostream>
#include "SparseVector.h"
using namespace std;

class SparseMatrix
{
	public:
		//Contructors
		SparseMatrix();
		SparseMatrix(string filename);

		//Operator Overloads
		SparseMatrix operator+(const SparseMatrix& v1)const;
		SparseMatrix operator-(const SparseMatrix& v1)const;
		SparseMatrix operator*(const SparseMatrix& v1)const;
		SparseMatrix operator-()const;
		void operator=(SparseMatrix v);
		friend ostream& operator<<(ostream& outs,const SparseMatrix& v);
		
		//Class Functions
		SparseMatrix transpos()const;
		bool control(int rw)const;
		int finder(int rw)const;
	private:
		//vector holds SparseVector in that row
		vector<SparseVector> column;

		//vector holds rows
		vector<int> row;
};
#endif