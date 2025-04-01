#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void countSymbols(ifstream &file) {
    int total = 0, empty = 0;
    char ch;

    // Возвращаемся в начало файла
    file.clear();
    file.seekg(0, ios::beg);

    while (file.get(ch)) {
        total++;
        if (isspace(ch) || ch == '\a') {
            empty++;
        }
    }

    cout << "Общее количество символов: " << total << endl;
    cout << "Количество пустых символов: " << empty << endl;
    cout << "Количество непустых символов: " << total - empty << endl;
}

void searchSubstring(ifstream &file, const char *substring, const char *outputFile) {
    ofstream out(outputFile);
    if (!out.is_open()) {
        cout << "Не удалось открыть файл для записи результатов." << endl;
        return;
    }

    // Возвращаемся в начало файла
    file.clear();
    file.seekg(0, ios::beg);

    string line;
    while (getline(file, line)) {
        if (line.find(substring) != string::npos) {
            out << line << endl;
        }
    }

    out.close();
    cout << "Результаты поиска сохранены в файле '" << outputFile << "'." << endl;
}

int main() {
    setlocale(LC_ALL, "ru_RU.utf-8");

    char name[100], substring[100], outputFile[100];

    cout << "Введите имя файла для просмотра: ";
    cin.getline(name, 100);

    ifstream file(name);
    if (!file.is_open()) {
        cout << "Файл " << name << " не открыт" << endl;
        return 1;
    }

    cout << "\nСодержимое файла:" << endl;
    cout << file.rdbuf() << endl;

    cout << "\nСтатистика символов:" << endl;
    countSymbols(file);

    cout << "\nВведите подстроку для поиска: ";
    cin.getline(substring, 100);

    printf("Введите имя файла для сохранения результатов: ");
    cin.getline(outputFile, 100);

    searchSubstring(file, substring, outputFile);

    file.close();
    return 0;
}
