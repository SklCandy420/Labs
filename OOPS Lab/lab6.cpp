#include <bits/stdc++.h>
using namespace std;
class ptr_obj
{
public:
    string rno, name;
    void set_data()
    {
        cout << "Enter Name:";
        cin >> this->name;
        cout << "Enter Roll no: ";
        cin >> this->rno;
    }
    void print()
    {
        cout << "Name - " << this->name << "\nRoll No - " << this->rno << endl;
    }
};
int main()
{
    cout << "Syed Mohammad Raza\n18BCS056" << endl;
    ptr_obj *ob1 = new ptr_obj(), *ob2 = new ptr_obj(), *ob3 = new ptr_obj();
    ob1->set_data();
    ob2->set_data();
    ob3->set_data();
    ob1->print();
    return 0;
}
