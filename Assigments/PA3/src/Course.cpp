#include "Course.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

namespace PA3
{
	Course::Course(){name = "";code = "";size_fox=0;}

	Course::Course(string n,string c){name = n;code = c;size_fox=0;}

	Course::~Course(){delete[] fox;size_fox=0;}

	string Course::getName(){return name;}

	string Course::getCode(){return code;}

	int Course::getSize(){return size_fox;}

	void Course::setName(string n){name = n;}

	void Course::setCode(string c){code = c;}

	Student* Course::get(int index){return fox[index];}


	void Course::add_student(Student* add_student)
	{
		Student** temp;
		temp = new Student*[size_fox];
		if(size_fox != 0){
			for(int i=0;i<size_fox;i++)
				temp[i] = fox[i];
			delete[] fox;
		}
		size_fox++;
		fox = new Student*[size_fox];
		for(int i=0;i<size_fox;i++)
			fox[i] = temp[i];
		fox[size_fox-1] = add_student;
		delete[] temp;
	}

	void Course::drop_student(Student* drop_student)
	{
		int j = 0;
		Student** temp;
		temp = new Student*[size_fox];
		if(size_fox != 0){
			for(int i=0;i<size_fox;i++)
				temp[i] = fox[i];
			delete[] fox;
		}
		size_fox--;
		for(int i=0;i<size_fox;i++){
			if((drop_student->getName() != temp[i]->getName()) && (drop_student->getID() != temp[i]->getID())){
				fox[j]=temp[i];
				j++;
			}
		}
		delete[] temp;
	}
}