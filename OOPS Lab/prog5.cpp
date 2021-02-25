#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, c, i, j, k;
    cout << "Enter Length Of Matrix 1"
         << "\n";
    cin >> r >> c;
    vector<vector<int>> matrix1(r, vector<int>(c));
    cout << "\n"
         << "Enter Elements Of Matrix 1:"
         << "\n";
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            cout << "Enter Elements "
                 << " : ";
            cin >> matrix1[i][j];
        }
    }
    cout << "Enter Size Of Matrix 2"
         << "\n";
    cin >> r >> c;
    vector<vector<int>> matrix2(r, vector<int>(c));
    cout << "\n"
         << "Enter Elements Of Matrix 2:"
         << "\n";
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            cout << "Enter Elements "
                 << " : ";
            cin >> matrix2[i][j];
        }
    }
    vector<vector<int>> matrixFinal(matrix1.size(), vector<int>(matrix2[0].size()));
    for (i = 0; i < matrix1.size(); ++i)
        for (j = 0; j < matrix2[0].size(); ++j)
            for (k = 0; k < matrix1[0].size(); ++k)
            {
                matrixFinal[i][j] += matrix1[i][k] * matrix2[k][j];
            }
    cout << "Desired Product : "
         << "\n";
    for (i = 0; i < matrixFinal.size(); ++i)
    {
        for (j = 0; j < matrixFinal[0].size(); ++j)
        {
            cout << matrixFinal[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Syed Mohammad Raza"
         << "\n";
    return 0;
}