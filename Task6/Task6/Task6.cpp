#include <iostream>
#include <windows.h>
#include <cstring>
using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    char names[5][100];

    for (int i = 0; i < 5; i++)
    {
        cout << "Введіть прізвище " << i + 1 << ": ";
        cin.getline(names[i], 100);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                char temp[100];

                strcpy_s(temp, names[j]);
                strcpy_s(names[j], names[j + 1]);
                strcpy_s(names[j + 1], temp);
            }
        }
    }

    cout << "Відсортовані прізвища:" << endl;

    for (int i = 0; i < 5; i++)
        cout << names[i] << endl;

    return 0;
}
