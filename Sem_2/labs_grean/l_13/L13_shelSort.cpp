#include<iostream>
using namespace std;
void shellSort(int* arr, int n) {
    // Начинаем с большого интервала, затем уменьшаем его
    for (int interval = n / 2; interval > 0; interval /= 2) {
        // Делаем сортировку вставками для этого интервала
        for (int i = interval; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}

// Пример использования функции shellSort
int main() {
    system("chcp 1251 >Null");
    int arr[] = { 12, 34, 54, 2, 3, 7,9, 4,108,54,32,16 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    shellSort(arr, n);

    cout << "Отсортированный массив: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}