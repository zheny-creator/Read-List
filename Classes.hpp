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
    string name;      // Имя книги
    string author;    // Автор книги
    string genre;     // Жанр книги
    string name_list; // Название списка книг
    int year;         // Год издания книги

public:
    // Конструктор
    Book(const string &name, const string &author, const string &genre, const string &name_list, int year) : name(name), author(author), genre(genre), year(year) {}

    // Добавление книги в список
    void add_book(const string &name, const string &author, const string &genre, const string &name_list, int year)
    {
        json j1 = json::array();
        json book1;
        book1["name"] = name;
        book1["year"] = year;
        book1["author"] = author;
        book1["genre"] = genre;
        j1.push_back(book1);
        ofstream file(name_list + ".json"); // Создаем файл .json в режиме записи
        file << j1.dump(4);                 // превращаем json объекты в строку
        file.close();
    }
    void add_book_to_list(const string &name_list, const string &name, const string &author, const string &genre, int year)
    {
        json j1 = json::array();
        json book1;
        book1["name"] = name;
        book1["year"] = year;
        book1["author"] = author;
        book1["genre"] = genre;
        j1.push_back(book1);
        ofstream file(name_list + ".json", ios::app); // Создаем файл .json в режиме записи
        if (file.is_open())
        {
            file << j1.dump(4); // превращаем json объекты в строку
            file.close();
        }
        else if (file.fail())
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