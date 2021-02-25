#include <bits/stdc++.h>

using namespace std;

inline int add(int a, int b)
{
    return a + b;
}

inline int sub(int a, int b)
{
    return a - b;
}

inline int mult(int a, int b)
{
    return a * b;
}

inline float divsn(float a, float b)
{
    return a / b;
}

inline int mod(int a, int b)
{
    return a % b;
}

int main()
{
    int x, y;
    cout << "Enter Two Numbers: ";
    cin >> x >> y;
    cout << "Inline Addition: " << add(x, y) << "\n";
    cout << "Inline Subtraction: " << sub(x, y) << "\n";
    cout << "Inline Multiplication: " << mult(x, y) << "\n";
    cout << "Inline Division: " << divsn(x, y) << "\n";
    cout << "Inline Modulus: " << mod(x, y) << "\n";

    cout << "\n"
         << "Syed Mohammad Raza"
         << "\n";
}