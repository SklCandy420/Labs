#include <bits/stdc++.h>
using namespace std;

class Bank
{
public:
    int p;
    Bank()
    {
        p = 0;
    }

    void operator++(int)
    {
        p++;
    }
    void operator--(int)
    {
        p--;
    }
    void print()
    {
        cout << "Number of people in the Bank are: " << p << endl;
    }
};
int main()
{
    cout << "Syed Mohammad Raza \n18BCS056" << endl;
    Bank B1;
    B1.print();
    B1++;
    B1++;
    B1.print();
    B1--;
    B1.print();
}