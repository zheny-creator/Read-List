#include <iostream>      // Для ввода/вывода (cout, cin)
#include <vector>        // Для работы с динамическими массивами
#include <string>        // Для работы со строками
#include <unordered_map> // Для работы с ассоциативными массивами
#include <fstream>       // Для работы с файлами
#include "json.hpp"      // Для работы с JSON
#pragma once             // Для того, чтобы компилятор не включал этот файл дважды

using namespace std;
using json = nlohmann::json;
class Book
{
protected:         // Поля доступны внутри класса и в наследниках
    string name;   // Имя книги
    string author; // Автор книги
    string genre;  // Жанр книги
    int year;      // Год издания книги

public:
    // Конструктор
    Book(const string &name, const string &author, const string &genre, int year) : name(name), author(author), genre(genre), year(year) {}

    // Добавление книги в словарь
    void add_book(const string &name, const string &author, const string &genre, int year)
    {
        unordered_map<string, Book> books;
        books[name] = Book(name, author, genre, year);
    }
};