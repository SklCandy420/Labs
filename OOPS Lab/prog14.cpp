#include <bits/stdc++.h>

using namespace std;

class Student
{

public:
    int rollNo;
    string name;
    int standard;

    Student()
    {
        rollNo = 0;
        name = "";
        standard = 0;
    }

    Student(int rollNo, string name, int standard)
    {
        this->rollNo = rollNo;
        this->name = name;
        this->standard = standard;
    }

    friend ostream &operator<<(ostream &out, Student &s);
    friend istream &operator>>(istream &in, Student &s);
};

ostream &operator<<(ostream &out, Student &s)
{
    out << "<<<<<<<<<<<<<<<<<<---->>>>>>>>>>>>>>>>>" << endl;
    out << "Roll No: " << s.rollNo << endl;
    out << "Name: " << s.name << endl;
    out << "Class: " << s.standard << endl;
    out << "<<<<<<<<<<<<<<<<<<---->>>>>>>>>>>>>>>>>" << endl;

    return out;
}

istream &operator>>(istream &in, Student &s)
{
    cout << "Enter roll no: ";
    in >> s.rollNo;
    cout << "Enter name: ";
    in.ignore();
    getline(in, s.name);
    cout << "Enter class: ";
    in >> s.standard;

    return in;
}

int main()
{
    Student stu1;
    cin >> stu1;
    cout << stu1;

    cout << "Syed Mohammad Raza" << endl;
    cout << "18BCS056" << endl;
}
