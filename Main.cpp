#include "Classes.hpp" // Здесь лежат классы

int main()
{
    int choice;                            // Переменная для выбора действия
    string name, name_list, author, genre; // Переменные для хранения данных
    int year;                              // Переменная для хранения года издания
    while (true)                           // Бесконечный цикл
    {
        cout << "\n=== Меню ===\n";
        cout << "1: Создать список книг\n";
        cout << "2: Добавить книгу в существующий список\n";
        cout << "3: Изменить книгу в списке\n";
        cout << "4: Выйти\n";
        cout << "5: О программе\n";
        cout << "Введите номер действия: ";
        cin >> choice; // Ввод выбора действия

        if (choice == 1) // Если выбрано создание списка книг
        {
            cout << "Введите название списка: ";
            getline(cin, name_list);
            cin.ignore();
            cout << "Введите название книги: ";
            getline(cin, name);
            cin.ignore();
            cout << "Введите автора: ";
            getline(cin, author);
            cin.ignore();
            cout << "Введите жанр: ";
            cin >> genre;
            cout << "Введите год издания: ";
            cin >> year;

            cout << "В разработке!" << endl;
            continue;
        }
        else if (choice == 2) // Если выбрано добавление книги в существующий список
        {
            cout << "В разработке!" << endl;
            continue;
        }
        else if (choice == 3) // Если выбрано изменение книги в списке
        {
            cout << "В разработке!" << endl;
            continue;
        }
        else if (choice == 4) // Если выбран выход
        {
            cout << "Выход из программы..." << endl;
            break;
        }
        else if (choice == 5) // Если выбрана программа
        {
            cout << "Программа для работы с книгами." << endl;
            cout << "Автор: Женя Бородин" << endl;
            cout << "Версия: 1.0 Milestone 1" << endl;
            continue;
        }
    }
    return 0;
}