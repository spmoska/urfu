#include <iostream>
#include "FileEncryptor.h"

using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru_RU.utf-8");

    FileEncryptor encryptor(argc, argv);

    if (!encryptor.validateKey()) {
        cerr << "Ошибка: Ключ не может быть пустым." << endl;
        return 1;
    }

    if (encryptor.encrypt()) {
        cout << "Шифрование выполнено успешно." << endl;
        return 0;
    }
    else {
        return 1;
    }
}
