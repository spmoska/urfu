#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.utf-8");

    // Объявление переменных
    char str1[100], str2[100], concatenatedStr[200];

    // Ввод первой строки
    cout << "Введите первую строку: ";
    cin.getline(str1, 100);

    // Ввод второй строки
    cout << "Введите вторую строку: ";
    cin.getline(str2, 100);

    // 1. Определение длины строк с помощью strlen()
    cout << "Длина первой строки: " << strlen(str1) << endl;
    cout << "Длина второй строки: " << strlen(str2) << endl;

    // 2. Конкатенация строк с помощью strcat()
    strcpy(concatenatedStr, str1); // Копируем первую строку в переменную
    strcat(concatenatedStr, str2); // Добавляем к ней вторую строку
    cout << "Результат конкатенации: " << concatenatedStr << endl;

    // 3. Копирование строки с помощью strcpy()
    char copiedStr[100];
    strcpy(copiedStr, str1); // Копируем первую строку в новую переменную
    cout << "Копированная строка: " << copiedStr << endl;

    // 4. Сравнение строк с помощью strcmp()
    char str3[100] = "qwerty";
    char str4[100] = "0123456789";
    int comparison = strcmp(str3, str4);

    if (comparison == 0) {
        cout << "Строки равны." << endl;
    } else if (comparison < 0) {
        cout << "Первая строка меньше второй." << endl;
    } else {
        cout << "Первая строка больше второй." << endl;
    }

    return 0;
}
