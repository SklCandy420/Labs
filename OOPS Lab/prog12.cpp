#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
template <typename T>
T myMin(T x, T y)
{

    if (x == y)
    {
        cout << "Same Same Same!!!!" << endl;
    }
    return min(x, y);
}
int main()
{
    int n1, n2;
    cout << "Enter Two Numbers: ";
    cin >> n1 >> n2;
    cout << myMin<int>(n1, n2) << endl;
    char c1, c2;
    cout << "Enter Two Characters: ";
    cin >> c1 >> c2;
    cout << myMin<char>(c1, c2) << endl;
    float f1, f2;
    cout << "Enter Two Float Numbers: ";
    cin >> f1 >> f2;
    cout << myMin<float>(f1, f2) << endl;

    cout << "Syed Mohammad Raza" << endl;
    cout << "18BCS056" << endl;
    return 0;
}