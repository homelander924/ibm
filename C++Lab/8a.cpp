#include <iostream>
#include <cstdio>
using namespace std;
void interchange(int number1, int number2);
int main()
{
    int num1 = 50, num2 = 70;
    // clrscr();
    interchange(num1, num2);
    cout << "\n Number1:" << num1 << "\n Number2:" << num2;
    // getch();
    return 0;
}
void interchange(int number1, int number2)
{
    int temp;
    temp = number1;
    number1 = number2;
    number2 = temp;
}
