#include "FileEncryptor.h"
#include <iostream>

using namespace std;

FileEncryptor::FileEncryptor(int argc, char* argv[])
    : default_input_file_("input.txt"),
    default_key_("defaultkey"),
    output_file_("encrypted.txt") {
    parseArguments(argc, argv);
}

void FileEncryptor::parseArguments(int argc, char* argv[]) {
    input_file_ = (argc >= 2) ? argv[1] : default_input_file_;
    key_ = (argc >= 3) ? argv[2] : default_key_;
}

bool FileEncryptor::validateKey() const {
    return !key_.empty();
}

bool FileEncryptor::encrypt() const {
    ifstream infile(input_file_, ios::binary);
    if (!infile.is_open()) {
        cerr << "Ошибка: Не удалось открыть входной файл." << endl;
        return false;
    }

    ofstream outfile(output_file_, ios::binary);
    if (!outfile.is_open()) {
        cerr << "Ошибка: Не удалось открыть выходной файл." << endl;
        infile.close();
        return false;
    }

    size_t key_index = 0;
    char c;
    while (infile.get(c)) {
        char encrypted_char = c ^ key_[key_index];
        outfile.put(encrypted_char);
        key_index = (key_index + 1) % key_.length();
    }

    infile.close();
    outfile.close();
    return true;
}
