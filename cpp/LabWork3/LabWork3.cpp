using namespace std;
#include <iostream>
#include <algorithm>
#include <conio.h>

// ������� ��� �������������� ������� �� ��������� ���������
void resetArray(int arr[], int size) {
    // ������������ �������� �������� � ����������� ���������� ������ �������
    static const int original[] = { 2, 5, -8, 1, -4, 6, 3, -5, 9, 13, 0, 4, 9 };

    // �������� �������
    if (size != sizeof(original) / sizeof(original[0])) {
        std::cerr << "������: ������ ������� �� ������������� ���������!" << std::endl;
        return;
    }

    // �������� ������������ �������� � ���������� ������
    for (int i = 0; i < size; i++) {
        arr[i] = original[i];
    }
}

// ������� ������ �������
void printArray(int mas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << mas[i] << ' ';
    }

    cout << endl;
}

// ����� ����-����
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

// ���������� ���������
void bubbleSort(int mas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (mas[j] > mas[j + 1]) {
                swap(mas[j], mas[j + 1]);
            }
        }
    }
}

// ������� ����������
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

// ���������� ������ �� ����������� � �������� �� ��������
void sortEvenOdd(int mas[], int n) {
    // ���������� ������ ����� �� �����������
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mas[i] % 2 == 0 && mas[j] % 2 == 0 && mas[i] > mas[j]) {
                swap(mas[i], mas[j]);
            }
        }
    }

    // ���������� �������� ����� �� ��������
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mas[i] % 2 != 0 && mas[j] % 2 != 0 && mas[i] < mas[j]) {
                swap(mas[i], mas[j]);
            }
        }
    }
}

// ���������� �� ��������� ��������
void sortInterval(int mas[], int N1, int N2) {
    sort(mas + N1, mas + N2 + 1); // �� �����������
}

void sortIntervalDescending(int mas[], int N1, int N2) {
    sort(mas + N1, mas + N2 + 1, greater<int>()); // �� ��������
}

int main() {
    setlocale(LC_ALL, "RU");

    const int n = 13;
    int mas[n]; // �������� ������ ��� ������
    resetArray(mas, n);

    cout << "�������� ������: ";
    printArray(mas, n);

    // 1. ����� ����-����
    miniMaxSort(mas, n);
    cout << "����-����: ";
    printArray(mas, n);
    resetArray(mas, n);

    // 2. ����������� ����������
    bubbleSort(mas, n);
    cout << "���������: ";
    printArray(mas, n);
    resetArray(mas, n);

    // 3. ������� ����������
    quickSort(mas, 0, n - 1);
    cout << "������� ����������: ";
    printArray(mas, n);
    resetArray(mas, n);

    // 4. ���������� ������ �� ����������� � �������� �� ��������
    sortEvenOdd(mas, n);
    cout << "������ �� �����������, �������� �� ��������: ";
    printArray(mas, n);
    resetArray(mas, n);

    // 5. ���������� �� ��������� [3, 7]
    sortInterval(mas, 3, 7);
    cout << "���������� �� ��������� [3, 7]: ";
    printArray(mas, n);
    resetArray(mas, n);

    // 6. ���������� �� ��������� [3, 7] �� ��������
    sortIntervalDescending(mas, 3, 7);
    cout << "���������� �� ��������� [3, 7] �� ��������: ";
    printArray(mas, n);

    return 0;
}