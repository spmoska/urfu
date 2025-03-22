using namespace std;
#include <iostream>
#include <locale>

// Первый вариант: обмен через третью переменную
void obmen1(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// Второй вариант: обмен через указатели
void obmen2(int* px, int* py) {
    int temp = *px;
    *px = *py;
    *py = temp;
}

// Третий вариант: обмен через ссылки
void obmen3(int& rx, int& ry) {
    int temp = rx;
    rx = ry;
    ry = temp;
}

int main() {
    setlocale(LC_ALL, "RU");

    int a = 2, b = 5;

    // Вывод до обмена
    cout << "До обмена: a=" << a << ", b=" << b << std::endl;

    // Первый обмен: через значения (не работает, так как изменения внутри функции не влияют на оригинальные переменные)
    obmen1(a, b);
    cout << "После обмена 1: a=" << a << ", b=" << b << std::endl;

    // Второй обмен: через указатели
    obmen2(&a, &b);
    cout << "После обмена 2: a=" << a << ", b=" << b << std::endl;

    // Третий обмен: через ссылки
    obmen3(a, b);
    cout << "После обмена 3: a=" << a << ", b=" << b << std::endl;

    return 0;
}