#include "SchoolManagerSystem.h"
#include "Student.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

namespace PA3
{

	//---------------------------------------//
	//			  Default Constructor        //
	//---------------------------------------//
	SchoolManagerSystem::SchoolManagerSystem(){size_courses=0;size_students=0;}

	//---------------------------------------//
	//            menu function              //
	//---------------------------------------//
	void SchoolManagerSystem::menu()
	{
		//data for user selection
		int enter = 1; 

		//menu loop until user enter 0
		while(enter!=0)
		{
			cout<<"0 exit"<<endl;
			cout<<"1 student"<<endl;
			cout<<"2 course"<<endl;
			cout<<"3 list_all_students"<<endl;
			cout<<"4 list_all_courses"<<endl<<">> ";
			cin>>enter;

			if(enter==1)
				student_menu();
			if(enter==2)
				course_menu();
			if(enter==3)
				list_students();
			if(enter==4)
				list_courses();
		}
	}

	//---------------------------------------//
	//			 Student menu function       //
	//---------------------------------------//
	void SchoolManagerSystem::student_menu()
	{
		//data for user selection
		int enter = 1;

		//menu loop
		while(enter!=0)
		{
			cout<<"0 up"<<endl;
			cout<<"1 add_student"<<endl;
			cout<<"2 select_student"<<endl<<">> ";
			cin>>enter;

			if(enter==1)
				add_student();
			if(enter==2)
				select_student();
		}
	}

	//---------------------------------------//
	//			 Course menu function        //
	//---------------------------------------//
	void SchoolManagerSystem::course_menu()
	{
		//fata for user input
		int enter = 1;

		//menu loop
		while(enter!=0)
		{
			cout<<"0 up"<<endl;
			cout<<"1 add_course"<<endl;
			cout<<"2 select_course"<<endl<<">> ";
			cin>>enter;

			if(enter==1)
				add_course();
			if(enter==2)
				select_course();
		}
	}

	//---------------------------------------//
	//	   	   list students function        //
	//---------------------------------------//
	void SchoolManagerSystem::list_students()
	{
		for(int i=0; i<size_students; i++)
			cout<<students[i]->getName()<<students[i]->getID()<<endl;
	}

	//---------------------------------------//
	//	   	   list courses function         //
	//---------------------------------------//
	void SchoolManagerSystem::list_courses()
	{
		for(int i=0; i<size_courses; i++)
			cout<<courses[i]->getName()<<" "<<courses[i]->getCode()<<endl;
	}

	//---------------------------------------//
	//	   	   add student function          //
	// 	  Add one student to students array  //
	//---------------------------------------//
	void SchoolManagerSystem::add_student()
	{
		//user input data
		string n;
		string id;
		string tmp;

		//control data
		int control=0;
		
		cout<<">>";
		cin.get();
		getline(cin,tmp);
		int s=0;
		while(tmp[s]<48 || tmp[s]>57){
			n = n + tmp[s];
			s++;
		}
		while(tmp[s]!='\0'){
			id = id + tmp[s];
			s++;
		}
	
		//control input student exist
		for(int i=0;i<size_students;i++){
			if(students[i]->getName() == n && students[i]->getID() == id)
				control++;
		}
		if(control==0){
			//creating student
			Student* st_add = new Student(n,id);
	
			//creating temporary Student array to hold initial array data
			Student** temp;
			temp = new Student*[size_students];

			//fill temp array
			if(size_students != 0){
				for(int i=0;i<size_students;i++)
					temp[i] = students[i];

				//delete initial Student array
				delete[] students;
			}

			//increase size
			size_students++;

			//allocate memory for dynamical array
			students = new Student*[size_students];

			//fill array
			for(int i=0;i<size_students;i++)
				students[i] = temp[i];

			//add created Student object
			students[size_students-1] = st_add;

			//delete temp array
			delete[] temp;
		}	
	}

	//---------------------------------------//
	//	   	 select student function         //
	//Select one student from students array //
	//---------------------------------------//	
	void SchoolManagerSystem::select_student()
	{
		//input data
		string input_name;
		string input_id;
		string tmp;
	
		cout<<">>";	
		cin.get();	
		getline(cin,tmp);
		int s=0;
		while(tmp[s]<48 || tmp[s]>57){
			input_name = input_name + tmp[s];
			s++;
		}
		while(tmp[s]!='\0'){
			input_id = input_id + tmp[s];
			s++;
		}

		//user input data for menu
		int enter = 2;

		//control data for control selected student exist
		int control=0;

		//control selected student if exist
		for(int i=0;i<size_students;i++){
			if(students[i]->getName() == input_name && students[i]->getID() == input_id)
				control++;
		}
		
		if(control!=0){

			//menu loop
			while(enter != 0 && enter != 1){
				cout<<"0 up"<<endl;
				cout<<"1 delete_student"<<endl;
				cout<<"2 add_selected_student_to_a_course"<<endl;
				cout<<"3 drop_selected_student_from_a_course"<<endl;
				cin>>enter;
				for(int i=0;i<size_students;i++){
					if((students[i]->getName() == input_name) && (students[i]->getID() == input_id)){
						if(enter==1)
							delete_student(input_name,input_id);
						if(enter==2)
							add_student_to_a_course(students[i]);
						if(enter==3)
							drop_student_from_a_course(students[i]);
					}
				}
			}
		}
	}

	//---------------------------------------//
	//	   	 delete student function         //
	//Delete one student from students array //
	//---------------------------------------//
	void SchoolManagerSystem::delete_student(string input_name,string input_id)
	{
		//second loop data
		int j = 0;

		//creating temporary Student array for hold initial array data
		Student** temp;

		//descrease size
		size_students--;
		temp = new Student*[size_students];
		for(int i=0;i<size_students+1;i++){

			//if it is not selected student add to temp array
			if((students[i]->getName() != input_name) && (students[i]->getID() != input_id)){
				temp[j] = students[i];
				j++;
			}
			//else delete selected student
			else{
				for(int k=0;k<students[i]->getSize();k++){
					students[i]->get(k)->drop_student(students[i]);
				}
				delete students[i];
			}
		}

		//delete initial array
		delete[] students;

		//allocate memory
		students = new Student*[size_students];

		//fill array with new data
		for(int i=0;i<size_students;i++)
			students[i] = temp[i];

		//delete temp array
		delete[] temp;
	}	

	//---------------------------------------//
	//	  add student to a course function   //
	//---------------------------------------//
	void SchoolManagerSystem::add_student_to_a_course(Student* selected)
	{
		//second loop data
		int j=1,
			//data holds courses that student regestered
			j2=0,
			//control data for control if student regestered to course 
			control,
			//user input data for menu
			enter;

		cout<<"0 up"<<endl;
		for(int i=0;i<size_courses;i++){
			control=0;
			for(int k=0;k<selected->getSize();k++){
				//if student regestered course increase control data
				if((selected->get(k)->getName() == courses[i]->getName()) && (selected->get(k)->getCode() == courses[i]->getCode())){
					control++;
				}
			}
			//if student didn't regester course put it to selections
			if(control==0){
				cout<<j<<" "<<courses[i]->getName()<<"-"<<courses[i]->getCode()<<endl;
				j++;
			}
			//if student regestered course increase j2
			else
				j2++;
		}
		cin>>enter;
		if(enter!=0){
			courses[j2+enter-1]->add_student(selected);
			selected->add_course(courses[j2+enter-1]);
		}
	}

	//---------------------------------------//
	//	drop student from a course function  //
	//---------------------------------------//
	void SchoolManagerSystem::drop_student_from_a_course(Student* selected)
	{
		//second loop data
		int j=1,
			//data holds courses that student regestered
			j2=0,
			//control data for control if student regestered to course 
			control,
			//user input data for menu
			enter;

		cout<<"0 up"<<endl;
		for(int i=0;i<size_courses;i++){
			//if student didn't regester course put it to selections
			if((selected->get(i)->getName() == courses[i]->getName()) && (selected->get(i)->getCode() == courses[i]->getCode())){
				cout<<j<<" "<<courses[i]->getName()<<"-"<<courses[i]->getCode()<<endl;
				j++;
			}
			//if student regestered course increase j2
			else 
				j2++;
		}
		cin>>enter;
		if(enter!=0){
			courses[j2+enter-1]->drop_student(selected);
			selected->drop_course(courses[j2+enter-1]);
		}
	}

	//---------------------------------------//
	//	   	    add course function          //
	// 	   Add one course to students array  //
	//---------------------------------------//
	void SchoolManagerSystem::add_course()
	{
		//input data
		string n;
		string c;
		string tmp;

		//control data
		int control=0;

		cout<<">>";
		cin.get();	
		getline(cin,tmp);
		int s=0;
		while(tmp[s]!=' '){
			c = c + tmp[s];
			s++;
		}
		while(tmp[s]!='\0'){
			n = n + tmp[s];
			s++;
		}

		//control input course exist
		for(int i=0;i<size_courses;i++){
			if(courses[i]->getName() == n && courses[i]->getCode() == c)
				control++;
		}

		if(control==0){
			//creating Course object
			Course* c_add = new Course(n,c);

			//creating temporary array that holds initial array data
			Course** temp;
			temp = new Course*[size_courses];
	
			//fill temp data
			if(size_courses != 0){
				for(int i=0;i<size_courses;i++)
					temp[i] = courses[i];
				//delete initial courses array
				delete[] courses;
			}
			//increase size
			size_courses++;

			//allocate memory
			courses = new Course*[size_courses];

			//fill array with temp array
			for(int i=0;i<size_courses;i++)
				courses[i] = temp[i];
	
			//add Course object to array
			courses[size_courses-1] = c_add;
	
			//delete temp array
			delete[] temp;
		}
	}

	//---------------------------------------//
	//	      select course function         //
	// Select one course from students array //
	//---------------------------------------//	
	void SchoolManagerSystem::select_course()
	{
		//input data
		string input_name;
		string input_code;
		string tmp;

		cout<<">>";
		cin.get();	
		getline(cin,tmp);
		int s=0;
		while(tmp[s]!=' '){
			input_code = input_code + tmp[s];
			s++;
		}
		while(tmp[s]!='\0'){
			input_name = input_name + tmp[s];
			s++;
		}

		//user input data for menu
		int enter = 2;

		//control data for control selected student exist
		int control=0;

		//control selected student if exist
		for(int i=0;i<size_courses;i++){
			if((courses[i]->getName() == input_name) && (courses[i]->getCode() == input_code))
				control++;
		}

		if(control!=0){
			//menu loop
			while(enter != 0 && enter != 1){
				cout<<"0 up"<<endl;
				cout<<"1 delete_course"<<endl;
				cout<<"2 list_students_regestered_to_the_selecter_course"<<endl;
				cin>>enter;
				for(int i=0;i<size_courses;i++){
					if((courses[i]->getName() == input_name) && (courses[i]->getCode() == input_code)){
						if(enter==1){
							delete_course(input_name,input_code);
						}
						if(enter==2)
							list_students_this(courses[i]);
					}
				}
			}
		}
	}

	//---------------------------------------//
	//	      delete course function         //
	// Delete one course from students array //
	//---------------------------------------//
	void SchoolManagerSystem::delete_course(string input_name,string input_code)
	{
		//second loop data
		int j = 0;

		//creating temporary Course array for hold initial array data
		Course** temp;

		//descrease size
		size_courses--;

		//allocate memory
		temp = new Course*[size_courses];

		for(int i=0;i<size_courses+1;i++){
			//if it is not selected course add to temp array
			if((courses[i]->getName() != input_name) && (courses[i]->getCode() != input_code)){
				temp[j] = courses[i];
				j++;
			}
			//else delete selected course
			else{
				for(int k=0;i<courses[i]->getSize();k++){
					courses[i]->get(k)->drop_course(courses[i]);
				}
				delete courses[i];
			}
		}
		//delete initial courses array
		delete[] courses;

		//allocate memory
		courses = new Course*[size_courses];

		//fill courses array with temp array
		for(int i=0;i<size_courses;i++)
			courses[i] = temp[i];

		//delete temporary array
		delete[] temp;
	}

	//---------------------------------------//
	//	   list students this function       //
	//list students regestered in that course//
	//---------------------------------------//
	void SchoolManagerSystem::list_students_this(Course* selected)
	{
		for(int i=0;i<selected->getSize();i++)
			cout<<i+1<<". "<<selected->get(i)->getName()<<"-"<<selected->get(i)->getID()<<endl;
	}
}