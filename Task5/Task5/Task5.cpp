#include <iostream>
#include <windows.h>
#include <cstring>
using namespace std;

struct Contact
{
    char name[100];
    char phone[30];
};

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int size = 0;
    Contact* contacts = nullptr;
    int choice;

    do
    {
        cout << "\n1 - Додати контакт";
        cout << "\n2 - Пошук за ім'ям";
        cout << "\n3 - Пошук за телефоном";
        cout << "\n4 - Змінити контакт";
        cout << "\n0 - Вихід\n";
        cin >> choice;
        cin.ignore(1000, '\n');

        if (choice == 1)
        {
            Contact* temp = new Contact[size + 1];

            for (int i = 0; i < size; i++)
                temp[i] = contacts[i];

            cout << "Ім'я: ";
            cin.getline(temp[size].name, 100);

            cout << "Телефон: ";
            cin.getline(temp[size].phone, 30);

            delete[] contacts;
            contacts = temp;
            size++;
        }
        else if (choice == 2 || choice == 3)
        {
            char search[100];
            cout << "Введіть ім'я або телефон: ";
            cin.getline(search, 100);

            bool found = false;

            for (int i = 0; i < size; i++)
            {
                if ((choice == 2 &&
                    strcmp(contacts[i].name, search) == 0) ||
                    (choice == 3 &&
                        strcmp(contacts[i].phone, search) == 0))
                {
                    cout << contacts[i].name << " - "
                        << contacts[i].phone << endl;
                    found = true;
                }
            }

            if (!found)
                cout << "Контакт не знайдено." << endl;
        }
        else if (choice == 4)
        {
            char search[100];
            cout << "Введіть ім'я контакту для зміни: ";
            cin.getline(search, 100);

            bool found = false;

            for (int i = 0; i < size; i++)
            {
                if (strcmp(contacts[i].name, search) == 0)
                {
                    cout << "Нове ім'я: ";
                    cin.getline(contacts[i].name, 100);

                    cout << "Новий телефон: ";
                    cin.getline(contacts[i].phone, 30);

                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Контакт не знайдено." << endl;
        }

    } while (choice != 0);

    delete[] contacts;

    return 0;
}
