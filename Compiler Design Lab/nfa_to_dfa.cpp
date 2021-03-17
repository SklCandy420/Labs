#include <bits/stdc++.h>
using namespace std;

int main()
{
    string initState;
    set<string> finalState;
    vector<vector<string>> matrix;
    vector<string> row;

    string line;
    ifstream inputFile("Input1.txt");
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

    function<void(string)> createTransition = [&](string cur) {
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
            ans[m[cur]][i] = m[nxt]; //;
        }
    };
    createTransition(initState);
    cout << initState << endl;
    string fin;
    for (auto X : newfinal)
    {
        fin += char(X + '0');
        fin += ",";
    }
    fin.pop_back();
    cout << fin << endl;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ans[i].find(j) == ans[i].end())
                cout << -1 << " ";
            else
                cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}