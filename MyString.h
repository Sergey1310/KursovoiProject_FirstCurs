#ifndef KURSOVOIPROJECT_MYSTRING_H
#define KURSOVOIPROJECT_MYSTRING_H
#include <iostream>

class MyString
{
public:

    MyString()
    {
        str = nullptr;
        length = 0;
    }//конструктор без параметров.

    MyString(const char *str)
    {
        length = strLength(str);// Функция strLength получает количество символов в строке которую мы передаём в объект.

// Выделяем память для динамического массива где будет храниться наша строка.
// +1 символ так как нужно место в массиве под терминирующий 0.
        this->str = new char[length + 1];

// копируем символы строки в массив нашего класса
        for (int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }

//закрываем строку терминирующим нулём
        this->str[length] = '\0';

    }//конструктор с параметрами, при создании объекта класса необходимо передать строку которую он будет хранить.

    MyString(const MyString &other)
    {
        length = strLength(other.str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';
    }// Конструктор копировании, необходим для создании точной копи объекта класса но в другой области памяти.

    ~MyString()
    {
        delete[] this->str;
    }// Деструктор, отвечает за освобождение ресурвов занятых объектом, вызывается при уничтожении объекта класса.

    MyString &operator =(const MyString& other);// Дерегруженый оператор присваивания, вызывается когда необходимо присвоить значение одного объекта другому.
    MyString &operator =(const char* other)
    {
// Здесь логика похожа на ту которая реализована в конструкторе, за исключением того, что нам нужно позаботиться
// об освобождении ресурсов объекта если до копирования в него новой строки он уже содержал код
//+ страндартный синтаксис перегрузки оператора =
        if (this->str != nullptr)
        {
            delete[] str;
        }
        length = strLength(other);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = other[i];
        }
        this->str[length] = '\0';
        return *this;
    }// Перегруженый оператор присваивания, вызывается когда необходимо присвоить значение одной строки, другой.
    MyString operator+(const MyString &other)
    {
//Создаём новый пустой объект где будим хранить результат склеивания (Конкатенации) строк и который будет результатом работы
// перегруженного оператора +
        MyString newStr;
// получаем количество символов в обеих строках для конкатенации

        int thisLength = strLength(this->str);
        int otherLength = strLength(other.str);

        newStr.length = thisLength + otherLength;

// выделяем место в динамической памяти под новую строку
        newStr.str = new char[thisLength + otherLength + 1];

//копируем данные из 2х конкатенируемых строк в новую строку
        int i = 0;
        for (; i < thisLength; i++)
        {
            newStr.str[i] = this->str[i];
        }

        for (int j = 0; j < otherLength; j++, i++)
        {
            newStr.str[i] = other.str[j];
        }

        newStr.str[thisLength + otherLength] = '\0';

// возвращаем результа
// возвращаем результат конкатенации
        return newStr;
    }//Перегруженный оператор сложения, необходим для склеивания строк.
    void Print()
    {
        std::cout<< str;
    }// выводит строку в консоль.
    bool operator ==(const MyString & other)
    {
        if (this->length != other.length)
        {
            return false;
        }//Сравниваем длину строк, если она различается falls.

        for (int i = 0; i < this->length; i++)
        {
            if (this->str[i] != other.str[i])
            {
                return false;
            }
        } //Посимвольная проверка строк.
        return true;
    }// Перегруженный оператор равенства, вызывается когда нужно проверить две строки на равенство.
    bool operator !=(const MyString & other)
    {
        return !(this->operator==(other)); //Тут ясно без лишних слов.
    }// Перегруженный оператор НеРавно, вызывается когда нужно проверить две строки на НЕ равенство.
    char& operator [](int index)
    {
        return this->str[index];
    }// Перегруженный оператор взятия элемента, вызывается когда нужно обратиться к объекту по индексу.

private:

    static int strLength(const char* str) {
        int counter = 0;
        while (str[counter] != '\0') {
            ++counter;
        }
        return counter;
    } //Подсчёт символов в строке.
    char* str; //Указатель на получаемую строку.
    int length; // Переменная для хранения длинны строки.
};

#endif //KURSOVOIPROJECT_MYSTRING_H
