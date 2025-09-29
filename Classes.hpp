#include <iostream>
#include <vector>
#include <string>
#include "json.hpp"
#pragma once

using namespace std;

class Book
{
private:
    string name;
    string author;
    string genre;
    int year;

public:
    Book(const string &name, const string &author, const string &genre, int year) : name(name), author(author), genre(genre), year(year) {}
};