#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class MyInteger
{
public:
    MyInteger();
    MyInteger(int newint);
    void SetInt(int newint);
    int GetInt() const;
    int operator [](int index);
private:
    int num;
};

int main()
{
MyInteger num(418);
cout << num[0] << " " << num[1] << " " << num[2] << endl;
cout << num[3] << endl;
cout << num[-1] << endl;
return 0;
}

MyInteger::MyInteger() : num(0)
{}

MyInteger::MyInteger(int newint) : num(newint)
{}

void MyInteger::SetInt(int newint)
{
    num = newint;
}

int MyInteger::GetInt() const
{
    return num;
}

int MyInteger::operator[] (int index)
{
    int temp;
    if(index < 0){
        cout << "Illegal index value.\n";
        return -1;
    }
    else{
        temp = (int) (num / (pow(10,index)));
        //Rightmost digit is the answer
        return (temp % 10); 
    }
}



