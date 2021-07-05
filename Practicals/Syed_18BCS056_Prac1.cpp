#include <bits/stdc++.h>
using namespace std;

set<string> finalStates;
vector<vector<string>> matrix;
vector<string> row;
int initState;

void readAutomata()
{
    string line;
    ifstream myfile("dfa_gen.txt");
    string temp;
    char c;
    if (myfile.is_open())
    {
        myfile.get(c);
        initState = c - '0';
        getline(myfile, line);

        string temp;
        getline(myfile, line);
        stringstream check1(line);

        while (getline(check1, temp, ','))
        {
            finalStates.insert(temp);
        }

        while (getline(myfile, line))
        {

            stringstream check1(line);
            while (getline(check1, temp, ' '))
            {
                row.push_back(temp);
            }
            matrix.push_back(row);
            row.clear();
        }

        myfile.clear();
    }

    else
    {
        cout << "Not able to open" << endl;
    }
}

void dfaCheck()
{
    readAutomata();
    while (1)
    {
        cout << "Enter the string: ";
        string str;
        cin >> str;
        int current_state = initState;

        for (int i = 0; i < str.size(); i++)
        {
            int options = str[i] - '0';

            stringstream conv(matrix[current_state][options]);
            conv >> current_state;
            cout << current_state << ",";
            if (current_state == -1)
            {
                break;
            }
        }

        cout << endl;

        if (finalStates.count(to_string(current_state)) == 0)
        {
            cout << "Not accepted" << endl;
        }
        else
        {
            cout << "Accepted" << endl;
        }
    }
}

int main()
{
    string initState;
    set<string> finalState;
    vector<vector<string>> matrix;
    vector<string> row;

    string line;
    ifstream inputFile("Input.txt");
    string temp;
    char c;

    if (inputFile.is_open())
    {
        inputFile.get(c);
        initState = c;
        getline(inputFile, line);
        string temp;
        getline(inputFile, line);
        stringstream check(line);
        while (getline(check, temp, ','))
        {
            finalState.insert(temp);
        }

        while (getline(inputFile, line))
        {

            stringstream check(line);
            while (getline(check, temp, ' '))
            {
                row.push_back(temp);
            }
            matrix.push_back(row);
            row.clear();
        }
        inputFile.clear();
    }
    else
    {
        cout << "No File Found" << endl;
    }

    int count = 0;
    map<string, int> m;
    set<int> newfinal;
    map<int, map<int, int>> ans;

    function<void(string)> createTransition = [&](string cur)
    {
        if (m.find(cur) != m.end())
            return;
        m[cur] = count++;
        for (auto x : cur)
        {
            string t;
            t += x;
            if (finalState.find(t) != finalState.end())
            {
                newfinal.insert(m[cur]);
                break;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            string nxt = "";
            set<char> ss;
            for (auto x : cur)
            {
                if (x != ',')
                {
                    string tmp = matrix[x - '0'][i];
                    if (tmp != "-1")
                    {
                        for (auto y : tmp)
                        {
                            if (y != ',')
                                ss.insert(y);
                        }
                    }
                }
            }
            if (ss.empty())
                continue;
            for (auto x : ss)
                nxt += x;
            createTransition(nxt);
            ans[m[cur]][i] = m[nxt];
        }
    };
    string output = "";
    createTransition(initState);
    cout << "Syed Mohammad Raza"
         << endl;
    cout << "18BCS056" << endl;
    cout << endl;
    cout << initState << endl;
    output += initState + "\n";
    string fin;
    for (auto X : newfinal)
    {
        fin += char(X + '0');
        fin += ",";
    }
    fin.pop_back();
    cout << fin << endl;
    output += fin + "\n";
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ans[i].find(j) == ans[i].end())
            {
                cout << -1 << " ";
                output += "-1 ";
            }
            else
            {
                cout << ans[i][j] << " ";
                output += to_string(ans[i][j]) + " ";
            }
        }
        cout << endl;
        output += "\n";
    }
    ofstream dfaFile("dfa_gen.txt");
    dfaFile << output;
    dfaFile.close();
    dfaCheck();
    return 0;
}
