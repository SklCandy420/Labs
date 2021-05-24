#include <bits/stdc++.h>

using namespace std;

void followfirst(char, int, int);
void follow(char c);
void findfirst(char, int, int);

char calc_first[10][100];
char calc_follow[10][100];
int m = 0;
char production[10][10];
char f[10], first[10];
int k;
char ck;
int e;
int myCount;
int n = 0;

map<char, int> relationalTable;
map<char, set<char>> firstSet;
map<char, set<char>> followSet;
vector<set<string>> temp_vector;

map<char, vector<string>> grammar;
set<char> nonTerms;
set<char> terminals;

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

bool isSpecialChar(char item)
{
    set<char> validator{'*', '/', '(', ')', '+'};
    if (validator.count(item) > 0)
    {
        return true;
    }

    return false;
}

void readAutomatamod()
{
    ifstream inputFile("ll1Parser.txt");

    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            grammar[line[0]].push_back(line.substr(2));
            nonTerms.insert(line[0]);

            for (char item : line.substr(2))
            {
                if ((item >= 'a' && item <= 'z') || isSpecialChar(item))
                {
                    terminals.insert(item);
                }
            }
        }
        inputFile.clear();
    }
}

int readAutomata()
{
    ifstream inputFile("ll1Parser.txt");
    int tempCount = 0;
    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            char tempLine[20];

            for (int i = 0; i < line.size(); i++)
            {
                tempLine[i] = line[i];
            }

            tempLine[line.size()] = '\0';

            strcpy(production[tempCount], tempLine);
            tempCount++;
        }
        inputFile.clear();
    }

    return tempCount;
}

int main()
{

    int jm = 0;
    int km = 0;
    int i, choice;
    char c, ch;
    myCount = readAutomata();
    readAutomatamod();

    int kay;
    char done[myCount];
    int ptr = -1;

    for (k = 0; k < myCount; k++)
    {
        for (kay = 0; kay < 100; kay++)
        {
            calc_first[k][kay] = '!';
        }
    }
    int point1 = 0, point2, xxx;

    for (k = 0; k < myCount; k++)
    {
        c = production[k][0];
        point2 = 0;
        xxx = 0;

        for (kay = 0; kay <= ptr; kay++)
            if (c == done[kay])
                xxx = 1;

        if (xxx == 1)
            continue;

        findfirst(c, 0, 0);
        ptr += 1;

        done[ptr] = c;
        printf("\n First(%c) = { ", c);
        calc_first[point1][point2++] = c;

        for (i = 0 + jm; i < n; i++)
        {
            int lark = 0, chk = 0;

            for (lark = 0; lark < point2; lark++)
            {

                if (first[i] == calc_first[point1][lark])
                {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0)
            {
                printf("%c, ", first[i]);
                firstSet[c].insert(first[i]);
                calc_first[point1][point2++] = first[i];
            }
        }
        printf("}\n");
        jm = n;
        point1++;
    }
    printf("\n");
    printf("-----------------------------------------------\n\n");
    char donee[myCount];
    ptr = -1;

    for (k = 0; k < myCount; k++)
    {
        for (kay = 0; kay < 100; kay++)
        {
            calc_follow[k][kay] = '!';
        }
    }
    point1 = 0;
    int land = 0;
    for (e = 0; e < myCount; e++)
    {
        ck = production[e][0];
        point2 = 0;
        xxx = 0;

        for (kay = 0; kay <= ptr; kay++)
            if (ck == donee[kay])
                xxx = 1;

        if (xxx == 1)
            continue;
        land += 1;

        follow(ck);
        ptr += 1;

        donee[ptr] = ck;
        printf(" Follow(%c) = { ", ck);
        calc_follow[point1][point2++] = ck;

        for (i = 0 + km; i < m; i++)
        {
            int lark = 0, chk = 0;
            for (lark = 0; lark < point2; lark++)
            {
                if (f[i] == calc_follow[point1][lark])
                {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0)
            {
                printf("%c, ", f[i]);
                followSet[ck].insert(f[i]);
                calc_follow[point1][point2++] = f[i];
            }
        }
        printf(" }\n\n");
        km = m;
        point1++;
    }

    temp_vector.resize(terminals.size() + 1);

    map<char, vector<set<string>>> LL_Table;

    int bleh = 0;
    for (auto j : terminals)
    {

        relationalTable[j] = bleh++;
    }

    relationalTable['$'] = bleh++;

    for (auto item : grammar)
    {
        string firstGram = "";
        firstGram += item.first;

        for (string language : item.second)
        {
            if (language[0] >= 'a' && language[0] <= 'z' || isSpecialChar(language[0]))
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

    cout << "\n\n LL(1) TABLE :" << endl;
    cout << "              ";
    for (char item : terminals)
    {
        cout << "       " << item << "       ";
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
            }

            cout << "  ";
        }
        cout << endl;
    }

    while (1)
    {
        string userInput;

        cout << "\n Enter the string to validate : ";
        cin.clear();
        getline(cin, userInput, '\n');

        userInput += '$';

        int currentPointer = 0;

        stack<char> st;

        st.push('$');
        st.push('E');

        while (st.size() > 1 && currentPointer < userInput.length())
        {

            if (terminals.count(st.top()) > 0)
            {
                if (st.top() == userInput[currentPointer])
                {
                    st.pop();
                    currentPointer++;
                }
                else
                {
                    break;
                }
            }
            else
            {

                set<string> myItem = LL_Table[st.top()][relationalTable[userInput[currentPointer]]];
                string myStringItem;

                for (auto item : myItem)
                {
                    myStringItem = item;
                    break;
                }

                if (myStringItem.size() == 0)
                    break;
                st.pop();
                for (int ccc = myStringItem.size() - 1; ccc >= 3; ccc--)
                {
                    if (myStringItem[ccc] != '0')
                    {
                        st.push(myStringItem[ccc]);
                    }
                }
            }
        }

        if (st.size() == 1 && st.top() == '$' && currentPointer < userInput.length() && userInput[currentPointer] == '$')
        {
            cout << "The string is valid" << endl;
        }
        else
        {
            cout << "The string isn't valid " << endl;
        }
    }
}

void follow(char c)
{
    int i, j;

    if (production[0][0] == c)
    {
        f[m++] = '$';
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 2; j < 10; j++)
        {
            if (production[i][j] == c)
            {
                if (production[i][j + 1] != '\0')
                {

                    followfirst(production[i][j + 1], i, (j + 2));
                }

                if (production[i][j + 1] == '\0' && c != production[i][0])
                {

                    follow(production[i][0]);
                }
            }
        }
    }
}

void findfirst(char c, int q1, int q2)
{
    int j;

    if (!(isupper(c)))
    {
        first[n++] = c;
    }
    for (j = 0; j < myCount; j++)
    {
        if (production[j][0] == c)
        {
            if (production[j][2] == '0')
            {
                if (production[q1][q2] == '\0')
                    first[n++] = '0';
                else if (production[q1][q2] != '\0' && (q1 != 0 || q2 != 0))
                {

                    findfirst(production[q1][q2], q1, (q2 + 1));
                }
                else
                    first[n++] = '0';
            }
            else if (!isupper(production[j][2]))
            {
                first[n++] = production[j][2];
            }
            else
            {

                findfirst(production[j][2], j, 3);
            }
        }
    }
}

void followfirst(char c, int c1, int c2)
{
    int k;

    if (!(isupper(c)))
        f[m++] = c;
    else
    {
        int i = 0, j = 1;
        for (i = 0; i < myCount; i++)
        {
            if (calc_first[i][0] == c)
                break;
        }

        while (calc_first[i][j] != '!')
        {
            if (calc_first[i][j] != '0')
            {
                f[m++] = calc_first[i][j];
            }
            else
            {
                if (production[c1][c2] == '\0')
                {

                    follow(production[c1][0]);
                }
                else
                {

                    followfirst(production[c1][c2], c1, c2 + 1);
                }
            }
            j++;
        }
    }
}