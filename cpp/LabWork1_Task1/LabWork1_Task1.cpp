#include <iostream>
#include <locale>

// Функция power для вычисления x^n
int power(int base, int exponent) {
    int result = 1; // Инициализируем результат как 1

    for (int i = 1; i <= exponent; i++) {
        result *= base; // Умножаем result на base exponent раз
    }

    return result;
}

int main() {
    std::setlocale(LC_ALL, "Russian");

    int base, exponent;

    // Запрос у пользователя значения основания и показателя степени
    std::cout << "Enter base: ";
    std::cin >> base;

    std::cout << "Enter exponent: ";
    std::cin >> exponent;

    // Вызов функции power и вывод результата
    int result = power(base, exponent);
    std::cout << base << "^" << exponent << " = " << result << std::endl;

    return 0;
}