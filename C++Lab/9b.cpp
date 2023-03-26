
#include <iostream>
using namespace std;
class Base
{
public:
    Base()
    {
        cout << "Inside Base constructor" << endl;
    }
    ~Base()
    {
        cout << "Inside Base destructor" << endl;
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
    Derived x;
    return 0;
}
 