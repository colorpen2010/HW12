#include <iostream>
#include <windows.h>
using namespace std;

void transpose(int** arr, int** result, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            result[j][i] = arr[i][j];
    }
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int rows, cols;
    cout << "Введіть кількість рядків і стовпців: ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) return 0;

    int** arr = new int* [rows];
    int** result = new int* [cols];

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];

        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < cols; i++)
        result[i] = new int[rows];

    transpose(arr, result, rows, cols);

    cout << "Транспонована матриця:" << endl;

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];

    for (int i = 0; i < cols; i++)
        delete[] result[i];

    delete[] arr;
    delete[] result;

    return 0;
}
