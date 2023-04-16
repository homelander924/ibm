// pointers
#include <iostream>
#include <cstdio>
using namespace std;
class student
{
    int rollno;
    char name[50];

public:
    void getdata();
    void print();
};
void student::getdata()
{
    cout << "Enter roll number" << endl;
    cin >> rollno;
    cout << "Enter Name ";
    cin >> name;
}
void student::print()
{
    cout << "Name :" << name << endl;
    cout << "Roll no:" << rollno << endl;
}
int main()
{
    student a;
    a.getdata();
    a.print();
    cout << "Pointer to class\n";
    student *ptr;
    ptr = &a;
    ptr->print();
}