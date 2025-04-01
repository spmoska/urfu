#pragma once

#include <string>
#include <fstream>

using namespace std;

class FileEncryptor {
private:
    string input_file_;
    string key_;
    const string default_input_file_ = "input.txt";
    const string default_key_ = "defaultkey";
    const string output_file_ = "encrypted.txt";

    void parseArguments(int argc, char* argv[]);

public:
    FileEncryptor(int argc, char* argv[]);
    bool encrypt() const;
    bool validateKey() const;
};
