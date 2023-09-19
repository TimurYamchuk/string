#include <iostream>
#include "Array.h"
#include <cstring>

using namespace std; // Include the std namespace

class MyString {
private:
    char* str;     // Указатель на строку
    int length;    // Длина строки

    // Статическое поле для подсчета созданных объектов
    static int objectCount;

public:
    // Конструктор по умолчанию, создает строку длиной 80 символов
    MyString() : str(nullptr), length(0) {
        str = new char[81];
        memset(str, '\0', 81);
        objectCount++;  // Увеличиваем счетчик созданных объектов
    }

    // Конструктор, создающий строку произвольного размера
    MyString(int len) : str(nullptr), length(0) {
        if (len < 1) {
            len = 1;
        }
        str = new char[len + 1];
        memset(str, '\0', len + 1);
        objectCount++;  // Увеличиваем счетчик созданных объектов
    }

    // Конструктор, инициализирующий строку пользовательским вводом
    MyString(const char* input) : str(nullptr), length(0) {
        length = strlen(input);
        str = new char[length + 1];
        strcpy(str, input);
        objectCount++;  // Увеличиваем счетчик созданных объектов
    }

    // Деструктор для освобождения памяти
    ~MyString() {
        delete[] str;
        objectCount--;  // Уменьшаем счетчик созданных объектов при уничтожении
    }

    // Метод для получения длины строки
    int getLength() const {
        return length;
    }

    // Статический метод для получения количества созданных объектов
    static int getObjectCount() {
        return objectCount;
    }
};

// Инициализируем статическое поле objectCount
int MyString::objectCount = 0;

