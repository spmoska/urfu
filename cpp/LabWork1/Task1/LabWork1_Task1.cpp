#include <iostream>
#include <locale>

// ������� power ��� ���������� x^n
int power(int base, int exponent) {
    int result = 1; // �������������� ��������� ��� 1

    for (int i = 1; i <= exponent; i++) {
        result *= base; // �������� result �� base exponent ���
    }

    return result;
}

int main() {
    std::setlocale(LC_ALL, "Russian");

    int base, exponent;

    // ������ � ������������ �������� ��������� � ���������� �������
    std::cout << "Enter base: ";
    std::cin >> base;

    std::cout << "Enter exponent: ";
    std::cin >> exponent;

    // ����� ������� power � ����� ����������
    int result = power(base, exponent);
    std::cout << base << "^" << exponent << " = " << result << std::endl;

    return 0;
}