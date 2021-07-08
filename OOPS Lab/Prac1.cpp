#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string fullName;
    int age;

    friend ostream &operator<<(ostream &out, Student &s);
    friend istream &operator>>(istream &in, Student &s);
};

ostream &operator<<(ostream &out, Student &s)
{
    out << "####################################" << endl;
    out << "Name: " << s.fullName << endl;
    out << "Age: " << s.age << endl;
    out << "####################################" << endl;

    return out;
}

istream &operator>>(istream &in, Student &s)
{
    getline(in, s.fullName);
    in >> s.age;
    in.ignore();
    return in;
}

int main()
{
    cout << "Syed Mohammad Raza\n18BCS056" << endl;

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    Student s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;

    cout << s1;
    cout << s2;
    cout << s3;
}