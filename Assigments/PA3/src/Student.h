#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

namespace PA3
{
	class Course;
	class Student
	{
		public:
			Student();
			Student(string s,string i);
			~Student();

			string getName();
			string getID();
			int getSize();
			Course* get(int index);
			void setName(string n);
			void setID(string i);
			void add_course(Course* add_c);
			void drop_course(Course* drop_c);
		private:
			string name;
			string ID;
			Course** classes;
			int size_classes;
	};
}
#endif