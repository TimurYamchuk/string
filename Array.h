#pragma once

class MyString {
private:
    char* str;     
    int length;   

    
    static int objectCount;

public:
    MyString();  
    MyString(int len);  // Объявление конструктора с параметром
    MyString(const char* input);  // Объявление конструктора с параметром

    ~MyString(); // Объявление деструктора

    int getLength() const;  // Объявление метода для получения длины строки
    static int getObjectCount();  // Объявление статического метода для получения количества созданных объектов
};
