using namespace std;
#include <iostream>
#include <algorithm>
#include <conio.h>

// Функция для восстановления массива до исходного состояния
void resetArray(int arr[], int size) {
    // Оригинальные значения хранятся в статической переменной внутри функции
    static const int original[] = { 2, 5, -8, 1, -4, 6, 3, -5, 9, 13, 0, 4, 9 };

    // Проверка размера
    if (size != sizeof(original) / sizeof(original[0])) {
        std::cerr << "Ошибка: Размер массива не соответствует оригиналу!" << std::endl;
        return;
    }

    // Копируем оригинальные значения в переданный массив
    for (int i = 0; i < size; i++) {
        arr[i] = original[i];
    }
}

// Функция вывода массива
void printArray(int mas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << mas[i] << ' ';
    }

    cout << endl;
}

// Метод мини-макс
void miniMaxSort(int mas[], int n) {
    int imin, imax;
    for (int i = 0; i < n / 2; i++) {
        imin = i;
        imax = i;

        for (int j = i + 1; j < n - i; j++) {
            if (mas[j] < mas[imin]) imin = j;
            if (mas[j] > mas[imax]) imax = j;
        }

        swap(mas[i], mas[imin]);
        if (imax == i) imax = imin;
        swap(mas[n - 1 - i], mas[imax]);
    }
}

// Сортировка пузырьком
void bubbleSort(int mas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (mas[j] > mas[j + 1]) {
                swap(mas[j], mas[j + 1]);
            }
        }
    }
}

// Быстрая сортировка
int partition(int mas[], int low, int high) {
    int pivot = mas[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (mas[j] < pivot) {
            i++;
            swap(mas[i], mas[j]);
        }
    }

    swap(mas[i + 1], mas[high]);
    return i + 1;
}

void quickSort(int mas[], int low, int high) {
    if (low < high) {
        int pi = partition(mas, low, high);
        quickSort(mas, low, pi - 1);
        quickSort(mas, pi + 1, high);
    }
}

// Сортировка четных по возрастанию и нечетных по убыванию
void sortEvenOdd(int mas[], int n) {
    // Сортировка четных чисел по возрастанию
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mas[i] % 2 == 0 && mas[j] % 2 == 0 && mas[i] > mas[j]) {
                swap(mas[i], mas[j]);
            }
        }
    }

    // Сортировка нечетных чисел по убыванию
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mas[i] % 2 != 0 && mas[j] % 2 != 0 && mas[i] < mas[j]) {
                swap(mas[i], mas[j]);
            }
        }
    }
}

// Сортировка на интервале индексов
void sortInterval(int mas[], int N1, int N2) {
    sort(mas + N1, mas + N2 + 1); // По возрастанию
}

void sortIntervalDescending(int mas[], int N1, int N2) {
    sort(mas + N1, mas + N2 + 1, greater<int>()); // По убыванию
}

int main() {
    setlocale(LC_ALL, "ru_RU.utf-8");

    const int n = 13;
    int mas[n]; // Основной массив для тестов
    resetArray(mas, n);

    cout << "Исходный массив: ";
    printArray(mas, n);

    // 1. Метод мини-макс
    miniMaxSort(mas, n);
    cout << "Мини-макс: ";
    printArray(mas, n);
    resetArray(mas, n);

    // 2. Пузырьковая сортировка
    bubbleSort(mas, n);
    cout << "Пузырьком: ";
    printArray(mas, n);
    resetArray(mas, n);

    // 3. Быстрая сортировка
    quickSort(mas, 0, n - 1);
    cout << "Быстрая сортировка: ";
    printArray(mas, n);
    resetArray(mas, n);

    // 4. Сортировка четных по возрастанию и нечетных по убыванию
    sortEvenOdd(mas, n);
    cout << "Четные по возрастанию, нечетные по убыванию: ";
    printArray(mas, n);
    resetArray(mas, n);

    // 5. Сортировка на интервале [3, 7]
    sortInterval(mas, 3, 7);
    cout << "Сортировка на интервале [3, 7]: ";
    printArray(mas, n);
    resetArray(mas, n);

    // 6. Сортировка на интервале [3, 7] по убыванию
    sortIntervalDescending(mas, 3, 7);
    cout << "Сортировка на интервале [3, 7] по убыванию: ";
    printArray(mas, n);

    return 0;
}
