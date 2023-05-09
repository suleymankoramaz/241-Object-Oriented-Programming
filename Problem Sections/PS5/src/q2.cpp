#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Student{

public:
    Student();
    ~Student();
    void InputData();
    void OutputData();
    void ResetClasses();
    Student& operator=(const Student& stdnt);

private:
    string name;
    int numClasses;
    string *classList;


};

Student::Student()
{
    numClasses=0;
    classList = NULL;
    name = "";

}

Student::~Student()
{

    if(classList != NULL)
    {
        delete [] classList;
    }

}

void Student::ResetClasses()
{

if(classList != NULL)
{
         delete [] classList;
         classList = NULL;
}
    numClasses = 0;

}


void Student::InputData()
{
    int i;

    ResetClasses();

    cout<<"Enter student name."<<endl;
    getline(cin,name);
    cout<<"Enter number of classes."<<endl;
    cin>>numClasses;
    cin.ignore(2,'\n');     //Discard extra newline

    if(numClasses>0)
    {
        classList = new string[numClasses];

        for(i=0;i<numClasses;i++)
        {
            cout<<"Enter name of class"<<(i+1)<<endl;
            getline(cin,classList[i]);

        }

    }
    cout<<endl;



}

void Student::OutputData()
{
    int i;

    cout<<"Name: "<<name<<endl;
    cout<<"Number of classes: "<<numClasses<<endl;

    for(i=0;i<numClasses;i++)
    {
        cout<<"  Class "<<(i+1)<<":"<<classList[i]<<endl;
    }
    cout<<endl;

}

Student& Student::operator=(const Student& stdnt)
{
    if(this->classList==stdnt.classList)
    {
        return *this;
    }

    int i;

    ResetClasses();
    name=stdnt.name;
    numClasses=stdnt.numClasses;

    if(numClasses>0)
    {
        classList=new string[numClasses];
        for(i=0;i<numClasses;i++)
        {
            classList[i] = stdnt.classList[i];
        }

    }
    return *this;
}

int main(){

    Student stdnt1,stdnt2;
    stdnt1.InputData();
    cout<<"Student 1's data:"<<endl;
    stdnt1.OutputData();

    cout<<endl;

    stdnt2=stdnt1;
    cout<<"Student 2's data after assignment from student 1:"<<endl;
    stdnt2.OutputData();

    stdnt1.ResetClasses();
    cout<<"Student 1's data after reset:"<<endl;
    stdnt1.OutputData();

    cout<<"Student 2's data,should still same:"<<endl;
    stdnt2.OutputData();

    cout<<endl;
    return 0;

}


