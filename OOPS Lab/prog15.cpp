#include <bits/stdc++.h>

using namespace std;

class Dimension2
{

public:
    float x;
    float y;

    Dimension2()
    {
        this->x = 0;
        this->y = 0;
    }

    Dimension2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    static float calculateDistance(Dimension2 p1, Dimension2 p2)
    {
        return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
    }
};

class Dimension3 : Dimension2
{

public:
    float z;
    Dimension3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    static float calculateDistance(Dimension3 p1, Dimension3 p2)
    {
        cout << p1.x << " " << p1.y << " " << p1.z << endl;
        cout << p1.x << " " << p1.y << " " << p1.z << endl;
        return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)) + ((p1.z - p2.z) * (p1.z - p2.z))) * 1.0;
    }
};

int main()
{
    Dimension3 point1(12, 12, 12);
    Dimension3 point2(1, 1, 1);

    cout << Dimension3::calculateDistance(point1, point2) << endl;
}