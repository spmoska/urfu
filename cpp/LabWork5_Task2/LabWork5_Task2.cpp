#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.utf-8");

    // Открытие входного файла
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть входной файл." << endl;
        return 1;
    }

    string line;
    string currentPageNumber;
    vector<string> pageLines;

    regex pageRegex(R"(^-\s*(\d+)\s*-$)");
    smatch match;

    while (getline(inputFile, line)) {
        // Если строка начинается и заканчивается с '-', предполагаем, что это строка с номером страницы.
        if (regex_match(line, match, pageRegex)) {
            currentPageNumber = match[1].str();
            continue;
        }

        // Если встречаем строку, равную "\f", это конец текущей страницы
        // Здесь предполагается, что в файле строка записана как: \f
        if (line == "\\f") {
            // Выводим все сохранённые строки страницы
            for (const string &pageLine : pageLines) {
                cout << pageLine << endl;
            }

            // После строк выводим номер страницы
            cout << currentPageNumber << endl << endl; // дополнительный перевод строки между страницами

            // Очищаем данные для следующей страницы
            pageLines.clear();
            currentPageNumber.clear();
            continue;
        }

        // Иначе сохраняем строку страницы
        pageLines.push_back(line);
    }

    // Закрытие файлов
    inputFile.close();

    return 0;
}
