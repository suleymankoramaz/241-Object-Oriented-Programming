#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

const int MAX = 20;

void size(int s[], int& size);
void print(const int s[], int size);
void add(int num1[], int size1, int num2[], int size2, int sum[], int& sumSize);

int main()
{
    int s1[MAX + 1], s2[MAX + 1], sum[MAX + 1]; //numbers
    int size1, size2, sumSize;                  //number's sizes
    cout << "Enter an integer, 20 digits or less" << endl;
    size(s1, size1);  

    cout << "\nEnter another integer, 20 digits or less" << endl;
    size(s2, size2);   

    cout << "\n\nThe sum is: " << endl;
    print(s1, size1);
    cout << endl;
    print(s2, size2);
    cout << "\n---------------------\n";
    add(s1, size1, s2, size2, sum, sumSize);
    print(sum, sumSize);
    cout << endl;

    return 0;
}

void size(int s[], int& size)
{
    char ch;
    int i = 0;
    size = 0;
    cin.get(ch);
    while('\n' != ch){
        if(!isdigit(ch)){   //error control1
            cout << "non digit entered. Aborting. " << endl;
            exit(1);
        }
        s[i] = int(ch) - int('0');  //char to integer
        size++;
        i++;
        cin.get(ch);    //take next digit
    }

    if(size > 20){          //error control2
        cout << "Input s size too large. Aborting" << endl;
        exit(1);
    }

    //reversing
    for(int k=0; k<size/2; k++){
        int temp = s[k];
        s[k] = s[size-1-k];
        s[size-1-k] = temp;
    }
}

void print(const int s[], int size)
{
    for(int i=20; i>=size; i--)
        cout << " ";
    for(int i=size-1; i>=0; i--)
        cout << s[i];
}

void add(int num1[], int size1, int num2[], int size2, int sum[], int& sumSize)
{
    int carry=0, largerSize;
    if(size1 > size2){
        for(int i=size2; i<size1; i++)
            num2[i] = 0;
        largerSize = size1;
    }
    else{
        for(int i=size1; i<size2; i++)
            num1[i] = 0;
        largerSize = size2;
    }
    for(int i=0; i< largerSize; i++){
        sum[i] = num1[i] + num2[i] + carry;
        if(sum[i] > 9){
            carry = 1;
            sum[i] = sum[i] - 10;
        }
        else
            carry = 0;
    }
    if(carry == 1){
        if(largerSize == 20){
            cout << "An owerflow has occured. Result is set to 0" << endl;
            sumSize = 1;
            sum[0] = 0;
        }
        else{
            sum[largerSize] = carry;
            sumSize = largerSize + 1;
        }
    }
    else
        sumSize = largerSize;   
}