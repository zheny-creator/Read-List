#include "Classes.hpp" // Здесь лежат классы

int main()
{
    int choice;                                                          // Переменная для выбора действия
    string name, author, genre, name_list, new_name_list, old_name_list; // Переменные для хранения данных
    int year;                                                            // Переменная для хранения года издания
    while (true)                                                         // Бесконечный цикл
    {
        cout << "\n=== Меню ===\n";
        cout << "1: Создать список книг\n";
        cout << "2: Добавить книгу в существующий список\n";
        cout << "3: Изменить книгу в списке\n";
        cout << "4: Выйти\n";
        cout << "5: О программе\n";
        cout << "6: Изменение названия списка\n";
        cout << "Введите номер действия: ";
        cin >> choice; // Ввод выбора действия
        cin.ignore();  // Очистка буфера ввода

        if (choice == 1) // Если выбрано создание списка книг
        {
            cout << "Введите название списка: ";
            getline(cin, name_list);
            if (name_list.empty())
            {
                cout << "Название списка не может быть пустым!\n";
                continue;
            } // Если название списка пустое
            cout << "Введите название книги: ";
            getline(cin, name);
            if (name.empty())
            {
                cout << "Название книги не может быть пустым!\n";
                continue;
            }
            cout << "Введите автора: ";
            getline(cin, author);
            if (author.empty())
            {
                cout << "Автор не может быть пустым!\n";
                continue;
            } // Если автор не указан
            cout << "Введите жанр: ";
            getline(cin, genre);
            if (genre.empty())
            {
                cout << "Жанр не может быть пустым!\n";
                continue;
            } // Если жанр не указан
            cout << "Введите год издания: ";
            cin >> year;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода! Введите число.\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Book book1(name, author, genre, name_list, year);
            book1.add_book(name, author, genre, name_list, year);
            cout << "Список создан!\n";
            continue;
        }
        else if (choice == 2) // Если выбрано добавление книги в существующий список
        {
            cout << "Введите название списка: ";
            getline(cin, name_list);
            cout << "Введите название книги: ";
            getline(cin, name);
            cout << "Введите автора: ";
            getline(cin, author);
            cout << "Введите жанр: ";
            getline(cin, genre);
            cout << "Введите год издания: ";
            cin >> year;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода! Введите число.\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Book book1(name, author, genre, name_list, year);
            book1.add_book_to_list(name_list, name, author, genre, year);
            cout << "Список обновлен!\n";
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
            cout << "Версия: 1.0 Milestone 2" << endl;
            continue;
        }
        else if (choice == 6) // Если выбрано изменение названия списка
        {
            cout << "Введите старое название списка: ";
            getline(cin, old_name_list);
            cout << "Введите новое название списка: ";
            getline(cin, new_name_list);
            List list1(old_name_list, new_name_list);
            list1.change_name_list(old_name_list, new_name_list);
            cout << "Название списка изменено!\n";
            continue;
        }
    }
    return 0;
}