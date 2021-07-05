#include <bits/stdc++.h>

using namespace std;

int reverseNumberWithReturn(int n)
{
    int rev = 0;
    int rem;
    while (n != 0)
    {
        rem = n % 10;
        rev = (rev * 10) + rem;
        n /= 10;
    }
    return rev;
}

void reverseNumberWithoutReturn(int n)
{
    n = reverseNumberWithReturn(n);
    cout << "Reversed number is " << n << '\n';
}

int main()
{
    cout << "Syed Mohammad Raza(18BCS056)"
         << "\n";
    cout << "Enter the number : ";
    int no;
    cin >> no;
    cout << "Reversed number is " << reverseNumberWithReturn(no) << endl;
    reverseNumberWithoutReturn(no);

    return 0;
}
