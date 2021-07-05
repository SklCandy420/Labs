#include <bits/stdc++.h>
using namespace std;

int main()
{
    int initState;
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
        initState = c - '0';

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
    while (true)
    {
        cout << "String: ";
        string str;
        cin >> str;
        int currState = initState;

        for (int i = 0; str[i]; i++)
        {
            int input = str[i] - '0';

            stringstream conv(matrix[currState][input]);
            conv >> currState;
            cout << currState << ",";
            if (currState == -1)
            {
                break;
            }
        }

        if (finalState.count(to_string(currState)))
        {
            cout << "Acceptable" << endl;
        }
        else
        {
            cout << "Not Acceptable" << endl;
        }
    }
    return 0;
}