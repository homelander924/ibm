// Constructor Destructor
#include <iostream>
using namespace std;

class Base
{
public:
    ~Base()
    {
        cout << "Inside Base destructor" << endl;
    }
    Base()
    {
        cout << "Inside Base constructor" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Inside Derived constructor" << endl;
    }
    ~Derived()
    {
        cout << "Inside Derived destructor" << endl;
    }
};

int main()
{
    Derived obj;
    return 0;
}
