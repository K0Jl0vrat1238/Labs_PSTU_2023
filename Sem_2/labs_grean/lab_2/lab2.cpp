#include <iostream>
using namespace std;
const int N = 100; 

int main() {
    int matrix[N][N];
    int col;
    cin >> col;
    cout << "\n";

    
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < col; ++j) 
        {
            if (i >= j) 
            {
                matrix[i][j] = (i-j+1)%10; 
            }
            else if (i < j) 
            {
                matrix[i][j] = 0; 
            }
            else if(i-j>=9)
            {
                matrix[i][j] = (i - j+1)%10+1; 
                
            }
           
        }
        
    }

    

    for (int i = 0; i < col; ++i) 
    {
        for (int j = 0; j < col; ++j) 
        {
            cout << matrix[i][j] << "\t";
        }
        cout << std::endl;
    }

    return 0;
}
