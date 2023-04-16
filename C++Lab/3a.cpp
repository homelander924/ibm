// C++ program to demonstrate inheritance
#include <iostream>
using namespace std;
// base class
class Animal
{
public:
    void eat()
    {
        cout << "I can eat!" << endl;
    }
    void sleep()
    {
        cout << "I can sleep!" << endl;
    }
};
// derived class
class Dog : public Animal
{
public:
    void bark()
    {
        cout << "I can bark! Woof woof!!" << endl;
    }
};
int main()
{
    // Create object of the Dog class
    Dog dawg;
    // Calling members of the base class
    dawg.eat();
    dawg.sleep();
    // Calling member of the derived class
    dawg.bark();
    return 0;
}
