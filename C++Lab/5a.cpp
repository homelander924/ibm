#include <iostream>
using namespace std;
class fibonacci
{
    int f0, f1, f;

public:
    fibonacci()
    {
        f0 = 0;
        f1 = 1;
    }
    void series(int n)
    {
        int count = 0;
        f0 = 0;
        f1 = 1;
        while (count < n)
        {
            cout << f0 << "\t";
            count++;
            f = f0 + f1;
            f0 = f1;
            f1 = f;
        }
    }
};
int main()
{
    fibonacci obj;
    int terms;
    cout << "Enter How many terms to be printed:";
    cin >> terms;
    obj.series(terms);
    return 0;
}
