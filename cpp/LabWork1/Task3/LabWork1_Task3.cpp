using namespace std;
#include <iostream>
#include <locale>

// ������ �������: ����� ����� ������ ����������
void obmen1(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// ������ �������: ����� ����� ���������
void obmen2(int* px, int* py) {
    int temp = *px;
    *px = *py;
    *py = temp;
}

// ������ �������: ����� ����� ������
void obmen3(int& rx, int& ry) {
    int temp = rx;
    rx = ry;
    ry = temp;
}

int main() {
    setlocale(LC_ALL, "RU");

    int a = 2, b = 5;

    // ����� �� ������
    cout << "�� ������: a=" << a << ", b=" << b << std::endl;

    // ������ �����: ����� �������� (�� ��������, ��� ��� ��������� ������ ������� �� ������ �� ������������ ����������)
    obmen1(a, b);
    cout << "����� ������ 1: a=" << a << ", b=" << b << std::endl;

    // ������ �����: ����� ���������
    obmen2(&a, &b);
    cout << "����� ������ 2: a=" << a << ", b=" << b << std::endl;

    // ������ �����: ����� ������
    obmen3(a, b);
    cout << "����� ������ 3: a=" << a << ", b=" << b << std::endl;

    return 0;
}