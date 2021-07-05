#include <bits/stdc++.h>
using namespace std;
class Student
{
private:
    int rollNo;
    string name;
    int standard;

public:
    Student(int rollNo, string name, int standard)
    {
        this->rollNo = rollNo;
        this->name = name;
        this->standard = standard;
    }
    friend ostream &operator<<(ostream &out, Student &s);
};
ostream &operator<<(ostream &out, Student &s)
{
    cout << "Roll No: " << s.rollNo << endl;
    cout << "Name: " << s.name << endl;
    cout << "Class: " << s.standard << endl;
    return out;
}
int main()
{
    Student s1(1, "Syed Mohammad Raza", 56);
    Student s2(2, "Md Ruhulamin Khan", 67);
    Student s3(3, "Dhruv Dua", 89);
    cout << s1;
    cout << s2;
    cout << s3;

    cout << "Syed Mohammad Raza" << endl;
    cout << "18BCS056" << endl;
}
