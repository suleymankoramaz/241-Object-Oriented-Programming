#include "Student.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

namespace PA3
{
	Student::Student(){name = "";ID = "";size_classes = 0;}

	Student::Student(string s,string i){name = s;ID = i;size_classes = 0;}

	Student::~Student(){delete[] classes;size_classes = 0;}

	string Student::getName(){return name;}

	string Student::getID(){return ID;}

	int Student::getSize(){return size_classes;}

	void Student::setName(string n){name = n;}

	void Student::setID(string i){ID = i;}

	Course* Student::get(int index){return classes[index];}

	void Student::add_course(Course* add_c)
	{
		Course** temp;
		temp = new Course*[size_classes];
		if(size_classes != 0){
			for(int i=0;i<size_classes;i++)
				temp[i] = classes[i];
			delete[] classes;
		}
		size_classes++;
		classes = new Course*[size_classes];
		for(int i=0;i<size_classes;i++)
			classes[i] = temp[i];
		classes[size_classes-1] = add_c;
		delete[] temp;
	}

	void Student::drop_course(Course* drop_c)
	{
		int j = 0;
		Course** temp;
		temp = new Course*[size_classes];
		if(size_classes != 0){
			for(int i=0;i<size_classes;i++)
				temp[i] = classes[i];
			delete[] classes;
		}
		size_classes--;
		for(int i=0;i<size_classes;i++){
			if((drop_c->getName() != temp[i]->getName()) && (drop_c->getCode() != temp[i]->getCode())){
				classes[j]=temp[i];
				j++;
			}
		}
		delete[] temp;
	}
}