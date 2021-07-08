#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Syed Mohammad Raza\n18BCS056" << endl;

    int array[5];
    cout << "Enter array values: \n";
    for (int i = 0; i < 5; i++)
    {
        cin >> array[i];
    }
    while (true)
    {
        cout << "Enter index input: \n";
        int index;
        cin >> index;
        try
        {
            if (index >= 5 || index < 0)
            {
                throw "index out of bounds\n";
            }
            cout << "Value at index " << index << ":";
            cout << array[index] << endl;
        }
        catch (const char *err)
        {
            cout << err;
        }
    }

    return 0;
}