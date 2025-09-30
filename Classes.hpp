#include <iostream> // Для ввода/вывода (cout, cin)
#include <vector>   // Для работы с динамическими массивами
#include <string>   // Для работы со строками
#include <fstream>  // Для работы с файлами
#include "json.hpp" // Для работы с JSON
#pragma once        // Для того, чтобы компилятор не включал этот файл дважды

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

    // Добавление книги в список
    void add_book(const string &name, const string &author, const string &genre, int year)
    {
        json j1;
        j1["name"] = name;
        j1["year"] = year;
        j1["author"] = author;
        j1["genre"] = genre;
        ofstream file("Книги.json"); // Создаем файл Книги.json в режиме записи
        file << j1.dump(4);          // превращаем json объекты в строку
        file.close();
    }
};