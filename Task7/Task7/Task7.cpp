#include <iostream>
#include <windows.h>
using namespace std;

bool contains(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
            return true;
    }

    return false;
}

void addUnique(int arr[], int& size, int value)
{
    if (!contains(arr, size, value))
    {
        arr[size] = value;
        size++;
    }
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int rowsA, colsA;
    int rowsB, colsB;
    int rowsC, colsC;

    cout << "Введіть розміри A: ";
    cin >> rowsA >> colsA;

    cout << "Введіть розміри B: ";
    cin >> rowsB >> colsB;

    cout << "Введіть розміри C: ";
    cin >> rowsC >> colsC;

    if (rowsA <= 0 || colsA <= 0 ||
        rowsB <= 0 || colsB <= 0 ||
        rowsC <= 0 || colsC <= 0)
    {
        cout << "Неправильні розміри!" << endl;
        return 0;
    }

    int sizeA = rowsA * colsA;
    int sizeB = rowsB * colsB;
    int sizeC = rowsC * colsC;

    int* A = new int[sizeA];
    int* B = new int[sizeB];
    int* C = new int[sizeC];

    cout << "Введіть елементи A:" << endl;
    for (int i = 0; i < sizeA; i++)
        cin >> A[i];

    cout << "Введіть елементи B:" << endl;
    for (int i = 0; i < sizeB; i++)
        cin >> B[i];

    cout << "Введіть елементи C:" << endl;
    for (int i = 0; i < sizeC; i++)
        cin >> C[i];

    int maxSize = sizeA + sizeB + sizeC;

    int* common = new int[maxSize];
    int* unique = new int[maxSize];
    int* commonAC = new int[maxSize];
    int* negative = new int[maxSize];

    int commonSize = 0;
    int uniqueSize = 0;
    int commonACSize = 0;
    int negativeSize = 0;

    for (int i = 0; i < sizeA; i++)
        addUnique(unique, uniqueSize, A[i]);

    for (int i = 0; i < sizeB; i++)
        addUnique(unique, uniqueSize, B[i]);

    for (int i = 0; i < sizeC; i++)
        addUnique(unique, uniqueSize, C[i]);

    for (int i = 0; i < sizeA; i++)
    {
        if (contains(B, sizeB, A[i]) &&
            contains(C, sizeC, A[i]))
        {
            addUnique(common, commonSize, A[i]);
        }
    }

    for (int i = 0; i < sizeA; i++)
    {
        if (contains(C, sizeC, A[i]))
            addUnique(commonAC, commonACSize, A[i]);
    }

    for (int i = 0; i < sizeA; i++)
        if (A[i] < 0)
            addUnique(negative, negativeSize, A[i]);

    for (int i = 0; i < sizeB; i++)
        if (B[i] < 0)
            addUnique(negative, negativeSize, B[i]);

    for (int i = 0; i < sizeC; i++)
        if (C[i] < 0)
            addUnique(negative, negativeSize, C[i]);

    cout << "\nЗагальні значення A, B, C: ";
    for (int i = 0; i < commonSize; i++)
        cout << common[i] << " ";

    cout << "\nУнікальні значення A, B, C: ";
    for (int i = 0; i < uniqueSize; i++)
        cout << unique[i] << " ";

    cout << "\nСпільні значення A і C: ";
    for (int i = 0; i < commonACSize; i++)
        cout << commonAC[i] << " ";

    cout << "\nВід'ємні значення без повторень: ";
    for (int i = 0; i < negativeSize; i++)
        cout << negative[i] << " ";

    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    delete[] common;
    delete[] unique;
    delete[] commonAC;
    delete[] negative;

    return 0;
}
