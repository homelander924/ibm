#include <iostream>
#include <cstdio>
using namespace std;
void test(int x)
{
    try
    {
        if (x > 0)
            throw x;
        else
            throw 'x';
    }
    catch (int x)
    {
        cout << "Catch a integer and that integer is:" << x;
    }
    catch (char x)
    {
        cout << "Catch a character and that character is:" << x;
    }
}
int main()
{
    // clrscr();
    cout << "Testing multiple catches\n:";
    test(10);
    test(0);
    // getch();
    return 0;
}
