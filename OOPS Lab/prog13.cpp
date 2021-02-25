#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
template <typename T>
class Pair
{
public:
    T x;
    T y;
    Pair(T x, T y)
    {
        this->x = x;
        this->y = y;
    }
    T getMax()
    {
        if (x == y)
        {
            cout << "Same Same Same!!!!" << endl;
        }

        return max(x, y);
    }
};
int main()
{
    int n1, n2;
    cout << "Enter Two Numbers: ";
    cin >> n1 >> n2;
    Pair<int> pair1 = Pair<int>(n1, n2);
    cout << pair1.getMax() << endl;

    char c1, c2;
    cout << "Enter Two Characters: ";
    cin >> c1 >> c2;
    Pair<char> pair2 = Pair<char>(c1, c2);
    cout << pair2.getMax() << endl;

    float f1, f2;
    cout << "Enter Two Float Numbers: ";
    cin >> f1 >> f2;
    Pair<float> pair3 = Pair<float>(f1, f2);
    cout << pair3.getMax() << endl;

    cout << "Syed Mohammad Raza" << endl;
    cout << "18BCS056" << endl;
    return 0;
}