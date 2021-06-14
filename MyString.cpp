//
// Created by Sergey on 6/14/2021.
//

#include "MyString.h"

MyString &MyString::operator=(const MyString &other) {
// Здесь логика похожа на ту которая реализована в конструкторе, за исключением того, что нам нужно позаботиться
// об освобождении ресурсов объекта если до копирования в него новой строки он уже содержал код
//+ страндартный синтаксис перегрузки оператора =
    if (this->str != nullptr)
    {
        delete[] str;
    }
    length = strLength(other.str);
    this->str = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        this->str[i] = other.str[i];
    }
    this->str[length] = '\0';
    return *this;
}
