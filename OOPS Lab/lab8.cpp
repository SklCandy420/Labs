#include <bits/stdc++.h>
using namespace std;
const int min_bal = 500;
class Bank
{
public:
    int bal, acc_id;
    string contact_no, name;
    Bank(int id)
    {
        cout << "Enter Name : ";
        cin >> name;
        cout << "Enter Contact no : ";
        cin >> contact_no;
        bal = 0;
        acc_id = id;
        cout << "Your account ID is " << acc_id << endl;
        deposit();
    }
    void balance_enquiry()
    {
        cout << "Current Amount is : " << bal << endl;
    }
    void deposit()
    {
        cout << "Enter amount to be deposited : ";
        int x;
        cin >> x;
        while (bal + x < min_bal)
            cout << "Amount less than min\n";
        cout << "Enter amount again : ";
        cin >> x;
        bal += x;
    }
    void withdraw()
    {
        cout << "Enter withdrawl amount : ";
        int x;
        cin >> x;
        if (bal - x < min_bal)
        {
            cout << "Account Bal min" << endl;
            return;
            bal -= x;
            cout << "Amount Withdrawn Successfully" << endl;
            balance_enquiry();
        }
    }
    void customer_update()
    {
        cout << "Update Name (Y/N): ";
        char ch;
        cin >> ch;
        if (ch == 'Y')
        {
            cout << "Enter new name";
            cin >> name;
            cout << "\nUpdate Contact no.(Y/N): ";
            cin >> ch;
            if (ch == 'Y')
            {
                cout << "Enter new contact no";
                cin >> contact_no;
            }
        }
    }
};
int main()
{
     cout << "Syed Mohammad Raza \n18BCS056" << endl;
    vector<Bank> v;
    while (true)
    {
        cout << "1. Open Account\n 2.  Deposit into Account\n 3. Withdraw From Account\n 4. Balance Enquiry\n 5. Customer Contact Update\n 6. Exit\n";

        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int id = v.size();
            cout << "Your new Account id: " << id << endl;
            Bank acc(id);
            v.push_back(acc);
        }
        else if (ch == 2)
        {
            cout << "Enter Account ID: ";
            int id;
            cin >> id;
            if (id >= v.size())
                cout << "Invalid ID" << endl;
            else
                v[id].deposit();
        }
        else if (ch == 3)
        {
            cout << "Enter Account ID: ";
            int id;
            cin >> id;
            if (id >= v.size())
                cout << "Invalid ID" << endl;
            else
                v[id].withdraw();
        }
        else if (ch == 4)
        {
            cout << "Enter Account ID: ";
            int id;
            cin >> id;
            if (id >= v.size())
                cout << "Invalid ID" << endl;
            else
                v[id].balance_enquiry();
        }
        else if (ch == 5)
        {
            cout << "Enter Account ID: ";
            int id;
            cin >> id;
            if (id >= v.size())
                cout << "Invalid ID" << endl;
            else
                v[id].customer_update();
        }
        else
            break;
    }
    return 0;
}
