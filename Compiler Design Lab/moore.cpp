#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<string>> matrix;
    vector<string> row;
    int initState;
    string line;
    ifstream inputFile("Moore.txt");
    string temp;
    char c;
    if (inputFile.is_open())
    {
        inputFile.get(c);
        initState = c - '0';

        string temp;

        while (getline(inputFile, line))
        {

            stringstream firstCheck(line);
            while (getline(firstCheck, temp, ' '))
            {
                row.push_back(temp);
            }
            if (row.size() > 0)
            {
                matrix.push_back(row);
            }
            row.clear();
        }

        inputFile.clear();
    }

    else
    {
        cout << "No File Found" << endl;
        return 0;
    }

    cout << "Initial State : " << initState << endl;

    while (1)
    {
        cout << "string: ";
        string str;
        cin >> str;
        int currState = initState;
        string output = "";
        for (char item : str)
        {
            output += " " + matrix[currState][matrix[0].size() - 1];

            stringstream check2(matrix[currState][item - '0']);

            check2 >> currState;
            if (currState == -1)
            {
                cout << "Dead State Reached" << endl;
                break;
            }
        }

        cout << output << endl;
    }
}