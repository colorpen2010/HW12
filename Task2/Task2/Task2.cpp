#include <iostream>
#include <windows.h>
using namespace std;

void deleteColumn(int**& arr, int rows, int& cols, int pos)
{
    if (pos < 1 || pos > cols)
    {
        cout << "Неправильний номер стовпчика!" << endl;
        return;
    }

    if (cols == 1)
    {
        cout << "Не можна видалити останній стовпчик!" << endl;
        return;
    }

    int** temp = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        temp[i] = new int[cols - 1];
        int k = 0;

        for (int j = 0; j < cols; j++)
        {
            if (j != pos - 1)
            {
                temp[i][k] = arr[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;

    arr = temp;
    cols--;
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
    cout << "Який стовпчик видалити? ";
    cin >> pos;

    deleteColumn(arr, rows, cols, pos);

    cout << "Результат:" << endl;
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
