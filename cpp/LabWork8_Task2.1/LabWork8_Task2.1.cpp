#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.utf-8");

    string input_file, output_file;

    // Ввод имени входного файла
    cout << "Введите имя входного файла: ";
    cin >> input_file;

    // Открываем входной файл
    ifstream ifs(input_file);
    if (!ifs.is_open()) {
        cerr << "Ошибка: Не удалось открыть входной файл " << input_file << endl;
        return 1;
    }

    // Ввод имени выходного файла
    cout << "Введите имя выходного файла: ";
    cin >> output_file;

    // Открываем выходной файл
    ofstream ofs(output_file);
    if (!ofs.is_open()) {
        cerr << "Ошибка: Не удалось открыть выходной файл " << output_file << endl;
        ifs.close();
        return 1;
    }

    char c;
    while (ifs.get(c)) {
        // Преобразуем символ в верхний регистр
        c = toupper(static_cast<unsigned char>(c));
        ofs.put(c);
    }

    ifs.close();
    ofs.close();

    cout << "Выходной файл является копией входного файла в верхнем регистре." << endl;
    return 0;
}
