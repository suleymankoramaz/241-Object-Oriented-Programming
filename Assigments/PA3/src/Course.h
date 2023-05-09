#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

namespace PA3
{
	class Student;
	class Course
	{
		public:
			Course();
			Course(string n,string c);
			~Course();

			string getName();
			string getCode();
			int getSize();
			Student* get(int index);
			void setName(string n);
			void setCode(string c);
			void add_student(Student* add_student);
			void drop_student(Student* drop_student);
		private:
			string name;
			string code;
			Student** fox;
			int size_fox;
	};
}
#endif