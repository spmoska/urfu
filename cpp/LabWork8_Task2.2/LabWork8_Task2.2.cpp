#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.utf-8");

    string filename;

    cout << "Введите имя файла: ";
    cin >> filename;

    ifstream fin(filename);

    if (fin.is_open()) {
        cout << "Файл открыт: " << filename << endl;
        // Здесь можно добавить обработку файла
        fin.close();
    }
    else {
        cerr << "Ошибка: Не удалось открыть файл " << filename << endl;
        return EXIT_FAILURE;
    }

    return 0;
}
