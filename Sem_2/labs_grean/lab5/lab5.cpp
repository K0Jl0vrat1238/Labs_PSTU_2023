#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 100; 

int sumBelowDiagonal(int matrix[N][N], int size) 
{
    int sum = 0;
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int n; 
    cout << "Введите количество матриц: ";
    cin >> n;

    for (int k = 1; k <= n; ++k) 
    {
        int size; 
        cout << "Введите размер матрицы " << k << ": ";
        cin >> size;

        int matrix[N][N];
        
        for (int i = 0; i < size; ++i) 
        {
            for (int j = 0; j < size; ++j) 
            {
                matrix[i][j] = (1 + rand() % (100 - 10 + 1));
            }
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << matrix[i][j] << "\t";

            }
            cout << endl;
        }

        int sum = sumBelowDiagonal(matrix, size);
        cout << "Сумма элементов ниже главной диагонали в матрице " << k << ": " << sum << endl;
    }

    return 0;
}

