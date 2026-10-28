#include <iostream>
#include <windows.h>
using namespace std;

void addColumn(int**& arr, int rows, int& cols, int pos)
{
    if (pos < 1 || pos > cols + 1)
    {
        cout << "Неправильна позиція!" << endl;
        return;
    }

    int** temp = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        temp[i] = new int[cols + 1];

        for (int j = 0; j < pos - 1; j++)
            temp[i][j] = arr[i][j];

        cout << "";

        for (int j = pos; j <= cols; j++)
            temp[i][j] = arr[i][j - 1];
    }

    cout << "Введіть елементи нового стовпчика:" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "Рядок " << i + 1 << ": ";
        cin >> temp[i][pos - 1];
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;

    arr = temp;
    cols++;
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

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];
    }

    int pos;
    cout << "Введіть позицію стовпчика: ";
    cin >> pos;

    addColumn(arr, rows, cols, pos);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}
