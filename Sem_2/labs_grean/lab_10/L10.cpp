#include <iostream>
using namespace std;


int** createArray(int rows, int cols) {
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }
    return array;
}

void addColumn(int*** array, int rows, int* cols, int n_col) {
    
    for (int i = 0; i < rows; ++i) {
        
        int* newRow = new int[*cols + 1];

        for (int j = 0; j < n_col -1; ++j) {
            newRow[j] = (*array)[i][j];
        }

        newRow[n_col - 1] = 0;

        for (int j = n_col- 1; j < *cols; ++j) {
            newRow[j + 1] = (*array)[i][j];
        }
        delete[](*array)[i];
        (*array)[i] = newRow;
    }

    ++(*cols);
}

int main() {
    int rows = 5;
    int cols = 10;
    int** myArray = createArray(rows, cols);


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            myArray[i][j] = i * cols + j;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << myArray[i][j] <<"\t";
        }
        cout << endl;
    }

    int n_col;
    cin >> n_col;
    addColumn(&myArray, rows, &cols, n_col);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << myArray[i][j] << "\t";
        }
        cout << endl;
    }

}