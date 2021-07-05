#include <bits/stdc++.h>
using namespace std;
class c_polygon
{
public:
    int h, b;
    void set_values()
    {
        cout << "Enter Height and Breath : ";
        cin >> h >> b;
    }
    virtual float area()
    {
        return 0;
    }
};
class c_rectangle : public c_polygon
{
public:
    float area()
    {
        return h * b;
    }
};
class c_triangle : public c_polygon
{
public:
    float area()
    {
        return h * b * 0.5;
    }
};
int main()
{
    cout << "Syed Mohammad Raza \n18BCS056" << endl;
    c_triangle trg;
    c_rectangle rect;
    rect.set_values();
    trg.set_values();
    cout << "Rectangle area : " << rect.area() << endl;
    cout << "Trianle area : " << trg.area() << endl;
    return 0;
}