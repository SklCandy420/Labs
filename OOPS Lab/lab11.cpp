#include <bits/stdc++.h>
using namespace std;
class Matrix
{
private:
    int r;
    int c;
    int mat[200][200];

public:
    void input()
    {
        cout << "Enter number of rows: ";
        cin >> r;
        cout << "Enter number of column : ";
        cin >> c;
        cout << "Enter the matrix : " << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> mat[i][j];
            }
        }
    }
    void display()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    Matrix operator+(Matrix obj)
    {
        if ((this->r) != obj.r || (this->c != obj.c))
        {
            cout << "Dimensions don't match , So elementwise operation cannot take place " << endl;
            Matrix temp;
            return temp;
        }
        else
        {
            Matrix temp;
            for (int i = 0; i < this->r; i++)
            {
                for (int j = 0; j < this->c; j++)
                {
                    temp.mat[i][j] = this->mat[i][j] + obj.mat[i][j];
                }
            }
            temp.r = this->r;
            temp.c = this->c;
            return temp;
        }
    }
    Matrix operator-(Matrix obj)
    {
        if ((this->r) != obj.r || (this->c != obj.c))
        {
            cout << "Dimensions don't match , So elementwise operation cannot take place " << endl;
            Matrix temp;
            return temp;
        }
        else
        {
            Matrix temp;
            for (int i = 0; i < this->r; i++)
            {
                for (int j = 0; j < this->c; j++)
                {
                    temp.mat[i][j] = this->mat[i][j] - obj.mat[i][j];
                }
            }
            temp.r = this->r;
            temp.c = this->c;
            return temp;
        }
    }
};
int main()
{
    cout << "Syed Mohammad Raza \n18BCS056" << endl;
    Matrix mat1;
    Matrix mat2;
    mat1.input();
    mat2.input();
    Matrix mat3 = mat1 + mat2;
    Matrix mat4 = mat1 - mat2;
    cout << "Addition of two matrices : " << endl;
    mat3.display();
    cout << "Subtraction of two matrices: " << endl;
    mat4.display();
    return 0;
}