#include <bits/stdc++.h>
using namespace std;
class Company
{
public:
    int e;
    Company(int x = 0) { e = x; }

    Company operator+(Company x)
    {
        Company c(e + x.e);
        return c;
    }
    Company operator-(Company x)
    {
        Company c(e - x.e);
        return c;
    }
    void print()
    {
        cout << e << endl;
    }
};
int main()
{
    cout << "Syed Mohammad Raza \n18BCS056" << endl;
    Company c1(11), c2(220);
    auto c = c1 + c2;
    c.print();
    c = c1 - c2;
    c.print();
}
