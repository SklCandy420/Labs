#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> grammar;
bool f = 0;

void readAutomata()
{
    ifstream inputFile("regGrammar.txt");

    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            grammar[line[0]].push_back(line.substr(2));
        }
        inputFile.clear();
    }
}

void recur(string cur, string s)
{
    if (f or cur.size() > s.size())
    {
        return;
    }
    if (cur == s)
    {
        f = 1;
        cout << "String belongs to this grammar" << endl;
        return;
    }
    for (int i = 0; i < cur.size(); i++)
    {
        if (cur[i] >= 'A' and cur[i] <= 'Z')
        {
            for (auto x : grammar[cur[i]])
            {
                string tmp;
                tmp += cur.substr(0, i);
                tmp += x;
                tmp += cur.substr(i + 1);
                recur(tmp, s);
            }
        }
    }
}

int main()
{

    readAutomata();

    while (1)
    {
        cout << "Enter the string: ";
        f = 0;
        string s;
        cin >> s;
        recur("S", s);
        if (!f)
            cout << "String does not to belongs to this grammar" << endl;
    }
    return 0;
}