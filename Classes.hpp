#include <iostream>   // Для ввода/вывода (cout, cin)
#include <vector>     // Для работы с динамическими массивами
#include <string>     // Для работы со строками
#include <fstream>    // Для работы с файлами
#include <filesystem> // Для работы с файловой системой
#include "json.hpp"   // Для работы с JSON
#pragma once          // Для того, чтобы компилятор не включал этот файл дважды

using namespace std;
using json = nlohmann::json;
namespace fs = std::filesystem;
class Book
{
private:              // Поля доступны внутри класса и в наследниках
    int id;           // Идентификатор книги
    string name;      // Имя книги
    string author;    // Автор книги
    string genre;     // Жанр книги
    string name_list; // Название списка книг
    int year;         // Год издания книги

public:
    // Конструктор
    Book(const int &id, const string &name, const string &author, const string &genre, const string &name_list, int year) : id(id), name(name), author(author), genre(genre), year(year) {}

    // Добавление книги в список
    void add_book(const int &id, const string &name, const string &author, const string &genre, const string &name_list, int year)
    {
        json j1 = json::array();
        json book1;
        book1["id"] = id,
        book1["name"] = name;
        book1["year"] = year;
        book1["author"] = author;
        book1["genre"] = genre;
        j1.push_back(book1);
        ofstream file(name_list + ".json"); // Создаем файл .json в режиме записи
        file << j1.dump(4);                 // превращаем json объекты в строку
        file.close();
    }
    void add_book_to_list(const int &id, const string &name_list, const string &name, const string &author, const string &genre, int year)
    {
        ifstream file(name_list + ".json"); // Открываем файл для чтения
        json j1;
        if (file.is_open())
        {
            file >> j1;
            file.close();
        } // Если файл открыт успешно

        json book1;
        book1["id"] = id,
        book1["name"] = name;
        book1["year"] = year;
        book1["author"] = author;
        book1["genre"] = genre;
        j1.push_back(book1);
        ofstream out(name_list + ".json"); // Создаем файл .json в режиме записи
        if (out.is_open())
        {
            out << j1.dump(4); // превращаем json объекты в строку
            file.close();
        }
        else if (out.fail())
        {
            cout << "Ошибка при открытии файла" << endl;
        }
    }
};

class List
{
private:
    string new_name_list;
    string old_name_list;

public:
    List(const string &new_name_list, const string &old_name_list) : new_name_list(new_name_list), old_name_list(old_name_list) {}

    void change_name_list(const string &new_name_list, const string &old_name_list)
    {
        fs::rename(new_name_list + ".json", old_name_list + ".json");
    }
};
class New_data // Класс для работы с данными
{
private:
    string name;
    string old_name;
    string new_name;
    string name_json;
    int target_id;

public:
    New_data(const string &name, const string &name_json, const string &old_name, const string &new_name, const int &target_id) : name(name), old_name(old_name), new_name(new_name), target_id(target_id) {}

    void change_data(const string &name, const string &name_json, const string &old_name, const string &new_name, const int &target_id)
    {
        ifstream file(name_json + ".json"); // Открываем файл для чтения
        json j;
        if (file.is_open())
        {
            file >> j; // Считываем данные из файла в объект json
            file.close();
        }
        else
        {
            cout << "Ошибка при открытии файла" << endl;
        }
        for (auto &book : j)
        {
            if (book["id"] == target_id)
            {
                book[name] = new_name;
                ofstream file(name_json + ".json"); // Открываем файл для записи
                file << j.dump(4);                  // Преобразуем объект json в строку и записываем в файл
                file.close();
            }
        }
    };
};
