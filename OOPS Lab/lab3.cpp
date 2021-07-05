#include <bits/stdc++.h>

using namespace std;

class counter
{
private:
    static int objectCreated;
    static int objectDestroyed;

public:
    counter()
    {
        objectCreated++;
    }

    ~counter()
    {
        objectDestroyed++;
    }

    static void info()
    {
        cout << " Objects created:" << objectCreated << endl;
        cout << " Objects destroyed: " << objectDestroyed << endl;
    }
};

int counter::objectCreated;
int counter::objectDestroyed;

int main()
{
    cout << "Syed Mohammad Raza(18BCS056)"
         << "\n";

    {
        counter *count1 = new counter();
        counter::info();
        counter *count2 = new counter();
        counter::info();
        counter *count3 = new counter();
        counter::info();

        delete count1;
        counter::info();
        delete count2;
        counter::info();
    }
}