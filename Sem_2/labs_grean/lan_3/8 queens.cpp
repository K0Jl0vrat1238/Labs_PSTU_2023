#include <iostream>
using namespace std;

const int SIZE = 8;
int board[SIZE][SIZE];

void resetQ(int i, int j) {
    for (int x = 0; x < SIZE; ++x) {
        --board[x][j];
        --board[i][x];
        int k;
        k = j - i + x;
        if (k >= 0 && k < SIZE)
            --board[x][k];
        k = j + i - x;
        if (k >= 0 && k < SIZE)
            --board[x][k];
    }
    board[i][j] = 0;
}

void setQ(int i, int j) {
    for (int x = 0; x < SIZE; ++x) {
        ++board[x][j];
        ++board[i][x];
        int k;
        k = j - i + x;
        if (k >= 0 && k < SIZE)
            ++board[x][k];
        k = j + i - x;
        if (k >= 0 && k < SIZE)
            ++board[x][k];
    }
    board[i][j] = -1;
}

bool tryQ(int i) {
    bool result = false;
    for (int j = 0; j < SIZE; ++j) {
        if (board[i][j] == 0) {
            setQ(i, j);
            if (i == 7)
                result = true;
            else {
                if (!(result = tryQ(i + 1)))
                    resetQ(i, j);
            }
        }
        if (result)
            break;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "rus");

    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            board[i][j] = 0;

    
    
    tryQ(0);
        
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (board[i][j] == -1)
            cout << "Q" << "\t";
            else
                cout << "*" << "\t";
        }
        cout << endl << endl << endl;
    }
        
    
}
