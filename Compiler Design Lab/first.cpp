#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> grammar;
set<char> nonTerms;
set<char> terminals;

void readAutomata()
{
    ifstream inputFile("Input.txt");

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

set<char> first(char prod)
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
                for (auto k : first(j[0]))
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
                            for (auto k : first(gram[l + 1]))
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

int main()
{
    readAutomata();

    
    for (auto i : nonTerms)
    {
        cout << "First(" << i << ") >>>>> {";
        for (auto k : first(i))
        {

            cout << k << ",";
        }
        cout << "}" << endl;
    }
    for (auto i : nonTerms)
    {
        cout << "Follow(" << i << ") >>>>> {";
        auto res = follow(i);
        for (auto k : res)
        {
            if (k != '0')
            {
                cout << k << ",";
            }
        }

        cout << "}" << endl;
    }

    for (auto i : terminals)
    {
        cout << "First(" << i << ")>>>>> {" << i << "}" << endl;
    }
}