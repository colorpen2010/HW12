#include <iostream>
#include <windows.h>
using namespace std;

void shiftRows(int** arr, int rows, int cols, int count, bool down)
{
    count %= rows;

    for (int t = 0; t < count; t++)
    {
        if (down)
        {
            for (int j = 0; j < cols; j++)
            {
                int temp = arr[rows - 1][j];

                for (int i = rows - 1; i > 0; i--)
                    arr[i][j] = arr[i - 1][j];

                arr[0][j] = temp;
            }
        }
        else
        {
            for (int j = 0; j < cols; j++)
            {
                int temp = arr[0][j];

                for (int i = 0; i < rows - 1; i++)
                    arr[i][j] = arr[i + 1][j];

                arr[rows - 1][j] = temp;
            }
        }
    }
}

void shiftColumns(int** arr, int rows, int cols,
    int count, bool right)
{
    count %= cols;

    for (int t = 0; t < count; t++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (right)
            {
                int temp = arr[i][cols - 1];

                for (int j = cols - 1; j > 0; j--)
                    arr[i][j] = arr[i][j - 1];

                arr[i][0] = temp;
            }
            else
            {
                int temp = arr[i][0];

                for (int j = 0; j < cols - 1; j++)
                    arr[i][j] = arr[i][j + 1];

                arr[i][cols - 1] = temp;
            }
        }
    }
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int rows, cols;
    cout << "Введіть розміри матриці: ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) return 0;

    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];

        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];
    }

    int type, count, direction;

    cout << "1 - зсув рядків, 2 - стовпчиків: ";
    cin >> type;

    cout << "Кількість зсувів: ";
    cin >> count;

    if (count < 0) count = -count;

    if (type == 1)
    {
        cout << "1 - вниз, 2 - вгору: ";
        cin >> direction;
        shiftRows(arr, rows, cols, count, direction == 1);
    }
    else if (type == 2)
    {
        cout << "1 - вправо, 2 - вліво: ";
        cin >> direction;
        shiftColumns(arr, rows, cols, count, direction == 1);
    }

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
