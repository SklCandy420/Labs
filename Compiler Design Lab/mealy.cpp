#include <bits/stdc++.h>
using namespace std;

struct combi
{
    int next;
    string output;
};

int main()
{
    vector<vector<combi>> matrix;
    vector<string> row;
    int initState;
    vector<combi> temp_row;
    string line;
    ifstream inputFile("Mealy.txt");
    string temp;
    char c;
    if (inputFile.is_open())
    {
        inputFile.get(c);
        initState = c - '0';

        while (getline(inputFile, line))
        {

            stringstream firstCheck(line);
            while (getline(firstCheck, temp, ' '))
            {
                row.push_back(temp);
            }

            int firstElement;
            for (int i = 0; i < row.size(); i += 2)
            {
                stringstream check2(row[i]);
                check2 >> firstElement;

                temp_row.push_back({firstElement, row[i + 1]});
            }
            if (temp_row.size() > 0)
            {
                matrix.push_back(temp_row);
            }
            row.clear();
            temp_row.clear();
        }

        inputFile.clear();
    }

    else
    {
        cout << "No File Found" << endl;
        return 0;
    }

    while (1)
    {
        cout << "String: ";
        string str;
        cin >> str;
        int currState = initState;
        string output = "";

        for (char i : str)
        {

            output += " " + matrix[currState][i - '0'].output;
            currState = matrix[currState][i - '0'].next;
            if (currState == -1)
            {
                cout << "Dead State Reached" << endl;
                break;
            }
        }

        cout << output << endl;
    }
}