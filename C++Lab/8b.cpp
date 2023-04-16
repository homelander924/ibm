// call by reference
#include <iostream>
#include <cstdio>
using namespace std;
void interchange(int *num1, int *num2);
int main()
{
    int num1 = 50, num2 = 70;
    // clrscr();
    interchange(&num1, &num2);
    cout << "\n Number1:" << num1 << "\n Number2:" << num2;
    // getch();
    return 0;
}
void interchange(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}