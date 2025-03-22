using namespace std;
#include <iostream>
#include <string.h>

int getStringLen(char* inputString) {
    int i = 0;
    while (inputString[i])
        i++;
    
    return i;
}

char* copyString(char* destination, char* source) {
    destination = source;

    return destination;
}

int main()
{
    char myString [23] = "myString";
    char mySecondString[15] = "mySecondString";
    char myThirdString[15];

    cout << "Длина строки - " << strlen(myString);
    cout << "Объединенные строки - " << strcat_s(myString, mySecondString);
    cout << "Скопированная строка - " << strcpy_s(myThirdString, mySecondString);
    cout << "Сравнение строк myString и myThirdString - " << strcmp(myString, myThirdString);

    cout << "Длина строки из своей функции - " << getStringLen(myString);

    return 0;
}

