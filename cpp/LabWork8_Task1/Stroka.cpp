#define _CRT_SECURE_NO_WARNINGS
#include "Stroka.h"

using namespace std;

// Конструктор по умолчанию
Stroka::Stroka() : size(80) {
    str = new char[size]; // Выделяем память для буфера
    str[0] = '\0';        // Инициализируем строку как пустую
}

// Конструктор с указанием размера буфера
Stroka::Stroka(int capacity) : size(capacity) {
    if (capacity <= 0) {
        throw std::invalid_argument("Размер буфера должен быть положительным");
    }

    str = new char[size]; // Выделяем память для буфера
    str[0] = '\0';        // Инициализируем строку как пустую
}

// Конструктор с параметром
Stroka::Stroka(const char* string) : size(strlen(string) + 1) {
    str = new char[size]; // Выделяем память для строки
    strcpy(str, string);  // Копируем строку
}

// Копирующий конструктор
Stroka::Stroka(const Stroka& s) : size(s.size) {
    str = new char[size]; // Выделяем память для копии
    strcpy(str, s.str);   // Копируем строку
}

// Деструктор
Stroka::~Stroka() {
    delete[] str; // Освобождаем динамическую память
}

// Оператор присваивания
Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) { // Проверка на самоприсваивание
        strcpy(str, s.str);
    }

    return *this;
}

// Оператор сцепления строк
Stroka Stroka::operator+(const Stroka& s) const {
    Stroka result; // Создаем новый объект
    strcpy(result.str, str); // Копируем текущую строку
    strcat(result.str, s.str); // Добавляем строку из параметра
    return result;
}

// Оператор сравнения
int Stroka::operator==(const Stroka& s) {
    return strcmp(str, s.str) == 0; // Возвращает 1, если строки равны, иначе 0
}

// Перегрузка оператора вывода
ostream& operator<<(ostream& os, const Stroka& s) {
    os << s.str;
    return os;
}

// Перегрузка оператора ввода
istream& operator>>(istream& is, Stroka& s) {
    char buffer[256]; // Временный буфер
    is.getline(buffer, 256); // Читаем строку из потока
    s = Stroka(buffer); // Присваиваем объекту новую строку
    return is;
}

// Метод для определения длины строки
int Stroka::dlina() {
    return strlen(str);
}

// Метод для ввода строки
void Stroka::vvod() {
    cin >> str;
}

// Метод для вывода строки
void Stroka::vyvod() {
    cout << str;
}
