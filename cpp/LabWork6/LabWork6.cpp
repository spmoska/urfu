#include "Stroka.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.utf-8");

    Stroka firstString("Text"); // Создаем строку с начальным значением
    Stroka copiedString(firstString); // Копия первой строки
    Stroka concatenatedString; // Для конкатенации
    Stroka userInput; // Для ввода пользователя

    cout << "Первая строка по умолчанию: ";
    firstString.vyvod();
    cout << endl;

    // 1. Присваивание userInput
    userInput = "Input Text";
    cout << "Присвоение userInput по умолчанию: ";
    userInput.vyvod();
    cout << endl;

    // 2. Ввод и вывод строки от пользователя
    cout << "\nВведите userInput: ";
    userInput.vvod();
    cout << "Вы ввели: ";
    userInput.vyvod();
    cout << endl;

    // 3. Конкатенация строк
    concatenatedString = firstString + copiedString + userInput;
    cout << "\nОбъединенная строка: ";
    concatenatedString.vyvod();
    cout << " (Длина: " << concatenatedString.dlina() << ")" << endl;

    // 4. Сравнение строк
    if (firstString == userInput) {
        cout << "Первая и пользовательская строки равны" << endl;
    } else {
        cout << "Первая и пользовательская строки НЕ равны" << endl;
    }

    return 0;
}
