#include "Classes.hpp"

int main()
{
    int choice;
    while (true)
    {
        cout << "\n=== Меню ===\n";
        cout << "1: Создать список книг\n";
        cout << "2: Добавить книгу в существующий список\n";
        cout << "3: Изменить книгу в списке\n";
        cout << "4: Выйти\n";
        cout << "5: О программе\n";
        cin >> choice;

        if (choice == 1)
        {
            cout << "В разработке!" << endl;
            continue;
        }
        else if (choice == 2)
        {
            cout << "В разработке!" << endl;
            continue;
        }
        else if (choice == 3)
        {
            cout << "В разработке!" << endl;
            continue;
        }
        else if (choice == 4)
        {
            cout << "Выход из программы..." << endl;
            break;
        }
        else if (choice == 5)
        {
            cout << "Программа для работы с книгами." << endl;
            cout << "Автор: Женя Бородин" << endl;
            cout << "Версия: 1.0 Milestone 1" << endl;
            continue;
        }
    }
    return 0;
}