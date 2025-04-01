#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru_RU.utf-8");

    // Значения по умолчанию
    const string default_input_file = "input.txt";
    const string default_key = "defaultkey";

    // Получение аргументов коммандной строки
    string input_file = (argc >= 2) ? argv[1] : default_input_file;
    string key = (argc == 3) ? argv[2] : default_key;

    // Проверка, что ключ не пустой
    if (key.empty()) {
        cerr << "Ошибка: Ключ не может быть пустым." << endl;
        return 1;
    }

    // Фиксированное имя выходного файла
    const string output_file = "encrypted.txt";

    // Открытие входного файла в бинарном режиме
    ifstream infile(input_file, ios::binary);
    if (!infile.is_open()) {
        cerr << "Ошибка: Не удалось открыть входной файл." << endl;
        return 1;
    }

    // Открытие выходного файла в бинарном режиме
    ofstream outfile(output_file, ios::binary);
    if (!outfile.is_open()) {
        cerr << "Ошибка: Не удалось открыть выходной файл." << endl;
        infile.close();
        return 1;
    }

    // Переменная для индекса ключа
    size_t key_index = 0;

    // Чтение и шифрование файла
    char c;
    while (infile.get(c)) {
        char encrypted_char = c ^ key[key_index];
        outfile.put(encrypted_char);

        // Обновление индекса ключа циклически
        key_index = (key_index + 1) % key.length();
    }

    // Закрытие файлов
    infile.close();
    outfile.close();

    cout << "Шифрование выполнено успешно." << endl;
    return 0;
}
