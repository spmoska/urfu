#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

// Функция определения длины строки (способ 1: цикл)
int dlina1(const char* str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

// Функция определения длины строки (способ 2: strlen)
int dlina2(const char* str) {
    return strlen(str);
}

// Функция определения длины строки (способ 3: рекурсия)
int dlina3(const char* str) {
    if (*str == '\0') {
        return 0;
    }

    return 1 + dlina3(str + 1);
}

// Функция копирования строки
void kopir(char* dest, const char* src) {
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0'; // Добавляем завершающий нулевой символ
}

// Функция сравнения строк
int sravn(char* str1, char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

// Функция конкатенации строк
void konkat(char* str1, const char* str2) {
    int len1 = dlina1(str1); // Длина первой строки
    int i = 0;

    while (str2[i] != '\0') {
        str1[len1 + i] = str2[i]; // Добавляем символы второй строки к первой
        i++;
    }

    str1[len1 + i] = '\0'; // Добавляем завершающий нулевой символ
}

int main() {
    setlocale(LC_ALL, "ru_RU.utf-8");

    // Выделение динамической памяти
    char* str1 = (char*)calloc(100, sizeof(char));
    char* str2 = (char*)calloc(100, sizeof(char));

    if (!str1 || !str2) {
        cerr << "Ошибка: Не удалось выделить память." << endl;
        return 1;
    }

    // Инициализация строк
    strcpy(str1, "qwerty");
    strcpy(str2, "1234567890");

    // Вывод длины строк тремя способами
    cout << "Длина str1 = " << dlina1(str1) << ", str2=" << dlina1(str2) << endl;
    cout << "Длина str1 = " << dlina2(str1) << ", str2=" << dlina2(str2) << endl;
    cout << "Длина str1 = " << dlina3(str1) << ", str2=" << dlina3(str2) << endl;

    // Обмен строк
    char temp[100];
    kopir(temp, str1);
    kopir(str1, str2);
    kopir(str2, temp);

    cout << "После обмена: str1 = \"" << str1 << "\", str2 = \"" << str2 << "\"" << endl;

    // Копирование строки
    char copiedStr[100];
    kopir(copiedStr, str1);
    cout << "Результат копирования: str1 = \"" << copiedStr << "\"" << endl;

    // Сравнение строк
    int comparison = sravn(str1, str2);

    if (comparison == 0) {
        cout << "Строки равны." << endl;
    } else if (comparison < 0) {
        cout << "Первая строка меньше второй." << endl;
    } else {
        cout << "Первая строка больше второй." << endl;
    }

    // Конкатенация строк
    konkat(str1, str2);
    cout << "Результат конкатенации: str1 = \"" << str1 << "\"" << endl;

    free(str1);
    free(str2);

    return 0;
}
