#include "Stroka.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.utf-8");

    Stroka s;
    cout << "Введите строку: ";
    cin >> s;
    cout << "Вы ввели: " << s << endl;
}
