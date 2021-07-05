#include <bits/stdc++.h>
using namespace std;
int main()
{

    cout << "Syed Mohammad Raza(18BCS056)"
         << "\n";

    cout << "Program For Counting Vowels In The Given String Using Pointer Arithmetic"
         << "\n";
    cout << "Enter Char. Array : ";
    char Char[1000];
    cin >> Char;
    char *str = Char;
    int counter = 0;
    while ((*str) != '\0')
    {
        char var = (*str);
        if (var == 'a' or var == 'e' or var == 'i' or var == 'o' or var == 'u' or var == 'A' or var == 'E' or var == 'I' or var == 'O' or var == 'U')
        {
            counter++;
        }
        str++;
    }

    cout << "Vowels In The Given String " << counter << "\n";

    return 0;
}
