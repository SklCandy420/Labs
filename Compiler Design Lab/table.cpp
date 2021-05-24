#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> grammar;
set<char> nonTerms;
set<char> terminals;

void readAutomata()
{
    ifstream inputFile("table.txt");

    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            grammar[line[0]].push_back(line.substr(2));
            nonTerms.insert(line[0]);

            for (char item : line.substr(2))
            {
                if (item >= 'a' && item <= 'z')
                {
                    terminals.insert(item);
                }
            }
        }
        inputFile.clear();
    }
}

set<char> recur(char prod)
{
    set<char> ans;
    for (auto j : grammar[prod])
    {
        if (j[0] >= 'A' && j[0] <= 'Z')
        {
            if (j[0] == prod)
            {
                continue;
            }
            else
            {
                for (auto k : recur(j[0]))
                {
                    ans.insert(k);
                }
            }
        }
        else
        {
            ans.insert(j[0]);
        }
    }
    return ans;
}

set<char> follow(char pr)
{
    set<char> ans;
    for (auto prod : nonTerms)
    {
        for (auto gram : grammar[prod])
        {
            for (int l = 0; l < gram.size(); l++)
            {
                if (gram[l] == pr)
                {
                    if (l != gram.size() - 1)
                    {
                        if (gram[l + 1] >= 'A' && gram[l + 1] <= 'Z' && gram[l + 1])
                        {

                            if (find(grammar[gram[l + 1]].begin(), grammar[gram[l + 1]].end(), "0") != grammar[gram[l + 1]].end())
                            {
                                if (prod != pr && prod != 'S')
                                {

                                    for (auto k : follow(gram[prod]))
                                    {
                                        ans.insert(k);
                                    }
                                }
                                if (prod == 'S')
                                {
                                    ans.insert('$');
                                }
                            }
                            for (auto k : recur(gram[l + 1]))
                            {
                                ans.insert(k);
                            }
                        }
                        else
                        {
                            ans.insert(gram[l + 1]);
                        }
                    }
                    else
                    {
                        if (prod != pr && prod != 'S')
                        {
                            for (auto k : follow(gram[prod]))
                            {
                                ans.insert(k);
                            }
                        }
                        if (prod == 'S')
                        {
                            ans.insert('$');
                        }
                    }
                }
            }
        }
    }

    return ans;
}

map<char, int> relationalTable;
map<char, set<char>> firstSet;
map<char, set<char>> followSet;
vector<set<string>> temp_vector;

void fillTable(string inputGrammar, char c)
{

    for (char item : firstSet[c])
    {
        if (item != '0')
        {
            temp_vector[relationalTable[item]].insert(inputGrammar);
        }
        else
        {

            for (char item1 : followSet[c])
            {

                temp_vector[relationalTable[item1]].insert(inputGrammar);
            }
        }
    }
}

int main()
{

    readAutomata();

    for (auto i : nonTerms)
    {
        cout << "First(" << i << ") ----->>> {";
        for (auto k : recur(i))
        {

            cout << k << ",";
            firstSet[i].insert(k);
        }
        cout << "}" << endl;
    }
    for (auto i : nonTerms)
    {
        cout << "Follow(" << i << ") ----->>> {";
        auto res = follow(i);
        for (auto k : res)
        {
            if (k != '0')
            {
                cout << k << ",";
                followSet[i].insert(k);
            }
        }

        cout << "}" << endl;
    }

    for (auto i : terminals)
    {
        cout << "First(" << i << ") ---->>> {" << i << "}" << endl;
    }

    temp_vector.resize(terminals.size() + 1);

    map<char, vector<set<string>>> LL_Table;

    int i = 0;
    for (auto j : terminals)
    {

        relationalTable[j] = i++;
    }

    relationalTable['$'] = i++;

    for (auto item : grammar)
    {
        string firstGram = "";
        firstGram += item.first;

        for (string language : item.second)
        {
            if (language[0] >= 'a' && language[0] <= 'z')
            {

                temp_vector[relationalTable[language[0]]].insert(firstGram + "->" + language);
            }
            else if (language[0] == '0')
            {

                fillTable(firstGram + "->" + language, item.first);
            }
            else
            {

                fillTable(firstGram + "->" + language, language[0]);
            }
        }
        LL_Table[item.first] = temp_vector;
        for (int j = 0; j < terminals.size() + 1; j++)
        {
            temp_vector[j] = {};
        }
    }

    bool isValidTable = true;

    cout << "\n\n LL(1) TABLE :" << endl;

    for (char item : terminals)
    {
        cout << "           " << item << "     ";
    }
    cout << "      "
         << "$"
         << "         ";

    cout << endl;

    for (auto item : LL_Table)
    {
        cout << item.first << " ---> ";
        for (auto item1 : item.second)
        {
            if (item1.size() == 0)
                cout << "{ -1 }";
            else
            {
                cout << "{ ";
                for (auto item2 : item1)
                {
                    cout << item2 << " , ";
                }
                cout << " }";
                if (item1.size() > 1)
                    isValidTable = false;
            }

            cout << "  ";
        }
        cout << endl;
    }

    if (isValidTable)
    {
        cout << "\nThe following grammar is LL(1)" << endl;
    }
    else
    {
        cout << "\nThe grammar isn't LL(1)" << endl;
    }
}