#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H
#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
using namespace std;

namespace PA3
{
	class SchoolManagerSystem
	{
		public:
			SchoolManagerSystem();
			void menu();
		private:
			//menu functions
			void student_menu();
			void course_menu();
			void list_students();
			void list_courses();

			//student menu functions
			void add_student();
			void select_student();
			void delete_student(string input_name,string input_id);
			void add_student_to_a_course(Student* selected);
			void drop_student_from_a_course(Student* selected);

			//course menu functios
			void add_course();
			void select_course();
			void delete_course(string input_name,string input_code);
			void list_students_this(Course* selected);

			Course** courses;
			Student** students;
			int size_courses;
			int size_students;
	};
}
#endif