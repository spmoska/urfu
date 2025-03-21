using namespace std;
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#define N 5

// Функция для вывода матрицы
void printMatrix(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(8) << setprecision(2) << m[i][j];
        }

        cout << endl;
    }
}

// Функция для заполнения матрицы случайными числами от 0 до 10
void fillMatrix(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = rand() % 100;
        }
    }
}

// Функция для нахождения минимума матрицы
int findMinMatrix(int m[N][N]) {
    int minVal = numeric_limits<int>::max();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
    }

    return minVal;
}

// Функция для нахождения максимума матрицы
int findMaxMatrix(int m[N][N]) {
    int maxVal = numeric_limits<int>::lowest();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }

    }
    return maxVal;
}

// Функция для нахождения максимума нижнетреугольной части
int findMaxLowerTriangle(int m[N][N]) {
    int maxVal = numeric_limits<int>::lowest();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) { // i > j
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
    }

    return maxVal;
}

// Функция для нахождения максимума верхнетреугольной части
int findMaxUpperTriangle(int m[N][N]) {
    int maxVal = numeric_limits<int>::lowest();

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) { // i < j
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
    }

    return maxVal;
}

// Функция для нахождения минимума нижнетреугольной части
int findMinLowerTriangle(int m[N][N]) {
    int minVal = numeric_limits<int>::max();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) { // i > j
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
    }

    return minVal;
}

// Функция для нахождения минимума верхнетреугольной части
int findMinUpperTriangle(int m[N][N]) {
    int minVal = numeric_limits<int>::max();

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) { // i < j
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
    }

    return minVal;
}

// Функция для нахождения минимума главной диагонали
int findMinMainDiagonal(int m[N][N]) {
    int minVal = numeric_limits<int>::max();

    for (int i = 0; i < N; i++) {
        if (m[i][i] < minVal) {
            minVal = m[i][i];
        }
    }

    return minVal;
}

// Функция для нахождения максимума главной диагонали
int findMaxMainDiagonal(int m[N][N]) {
    int maxVal = numeric_limits<int>::lowest();

    for (int i = 0; i < N; i++) {
        if (m[i][i] > maxVal) {
            maxVal = m[i][i];
        }
    }

    return maxVal;
}

// Функция для нахождения минимума второй диагонали
int findMinSecondaryDiagonal(int m[N][N]) {
    int minVal = numeric_limits<int>::max();

    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] < minVal) {
            minVal = m[i][N - 1 - i];
        }
    }

    return minVal;
}

// Функция для нахождения максимума второй диагонали
int findMaxSecondaryDiagonal(int m[N][N]) {
    int maxVal = numeric_limits<int>::lowest();

    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] > maxVal) {
            maxVal = m[i][N - 1 - i];
        }
    }

    return maxVal;
}

// Функция для вычисления среднего арифметического всех элементов матрицы
int findAverageMatrix(int m[N][N]) {
    int sum = 0.0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
    }

    return sum / (N * N);
}

// Функция для вычисления среднего арифметического нижнетреугольной части
int findAverageLowerTriangle(int m[N][N]) {
    int sum = 0.0, count = 0.0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) { // i > j
            sum += m[i][j];
            count++;
        }
    }

    return sum / count;
}

// Функция для вычисления среднего арифметического верхнетреугольной части
int findAverageUpperTriangle(int m[N][N]) {
    int sum = 0.0, count = 0.0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) { // i < j
            sum += m[i][j];
            count++;
        }
    }

    return sum / count;
}

// Функция для вычисления сумм строк
void findRowSums(int m[N][N], int rowSums[N]) {
    for (int i = 0; i < N; i++) {
        rowSums[i] = 0.0;

        for (int j = 0; j < N; j++) {
            rowSums[i] += m[i][j];
        }
    }
}

// Функция для вычисления сумм столбцов
void findColumnSums(int m[N][N], int colSums[N]) {
    for (int j = 0; j < N; j++) {
        colSums[j] = 0.0;

        for (int i = 0; i < N; i++) {
            colSums[j] += m[i][j];
        }
    }
}

// Функция для нахождения минимальных значений строк
void findMinRowValues(int m[N][N], int minRowValues[N]) {
    for (int i = 0; i < N; i++) {
        minRowValues[i] = numeric_limits<int>::max();

        for (int j = 0; j < N; j++) {
            if (m[i][j] < minRowValues[i]) {
                minRowValues[i] = m[i][j];
            }
        }
    }
}

// Функция для нахождения минимальных значений столбцов
void findMinColumnValues(int m[N][N], int minColValues[N]) {
    for (int j = 0; j < N; j++) {
        minColValues[j] = numeric_limits<int>::max();

        for (int i = 0; i < N; i++) {
            if (m[i][j] < minColValues[j]) {
                minColValues[j] = m[i][j];
            }
        }
    }
}

// Функция для нахождения максимальных значений строк
void findMaxRowValues(int m[N][N], int maxRowValues[N]) {
    for (int i = 0; i < N; i++) {
        maxRowValues[i] = numeric_limits<int>::lowest();

        for (int j = 0; j < N; j++) {
            if (m[i][j] > maxRowValues[i]) {
                maxRowValues[i] = m[i][j];
            }
        }
    }
}

// Функция для нахождения максимальных значений столбцов
void findMaxColumnValues(int m[N][N], int maxColValues[N]) {
    for (int j = 0; j < N; j++) {
        maxColValues[j] = numeric_limits<int>::lowest();

        for (int i = 0; i < N; i++) {
            if (m[i][j] > maxColValues[j]) {
                maxColValues[j] = m[i][j];
            }
        }
    }
}

// Функция для вычисления средних арифметических значений строк
void findAverageRowValues(int m[N][N], int avgRowValues[N]) {
    for (int i = 0; i < N; i++) {
        avgRowValues[i] = 0.0;

        for (int j = 0; j < N; j++) {
            avgRowValues[i] += m[i][j];
        }

        avgRowValues[i] /= N;
    }
}

// Функция для вычисления средних арифметических значений столбцов
void findAverageColumnValues(int m[N][N], int avgColValues[N]) {
    for (int j = 0; j < N; j++) {
        avgColValues[j] = 0.0;

        for (int i = 0; i < N; i++) {
            avgColValues[j] += m[i][j];
        }

        avgColValues[j] /= N;
    }
}

// Функция для вычисления сумм нижнетреугольной и верхнетреугольной частей
void findTriangleSums(int m[N][N], int& lowerSum, int& upperSum) {
    lowerSum = 0.0;
    upperSum = 0.0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) { // Нижняя треугольная часть
            lowerSum += m[i][j];
        }

        for (int j = i + 1; j < N; j++) { // Верхняя треугольная часть
            upperSum += m[i][j];
        }
    }
}

// Функция для нахождения элемента, наиболее близкого к среднему арифметическому
int findClosestToAverage(int m[N][N], int average) {
    int closestElement = m[0][0];
    int minDiff = abs(m[0][0] - average);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int diff = abs(m[i][j] - average);
            if (diff < minDiff) {
                minDiff = diff;
                closestElement = m[i][j];
            }
        }
    }

    return closestElement;
}

int main() {
    setlocale(LC_ALL, "RU");

    int matrix[N][N];
    int rowSums[N], colSums[N];
    int minRowValues[N], minColValues[N];
    int maxRowValues[N], maxColValues[N];
    int avgRowValues[N], avgColValues[N];

    // Заполнение матрицы случайными числами
    fillMatrix(matrix);

    // Вывод матрицы
    cout << "Матрица:" << endl;
    printMatrix(matrix);

    // 1. Минимум матрицы
    cout << "Минимум матрицы: " << findMinMatrix(matrix) << endl;

    // 2. Максимум матрицы
    cout << "Максимум матрицы: " << findMaxMatrix(matrix) << endl;

    // 3. Максимум нижнетреугольной части
    cout << "Максимум нижнетреугольной части: " << findMaxLowerTriangle(matrix) << endl;

    // 4. Максимум верхнетреугольной части
    cout << "Максимум верхнетреугольной части: " << findMaxUpperTriangle(matrix) << endl;

    // 5. Минимум нижнетреугольной части
    cout << "Минимум нижнетреугольной части: " << findMinLowerTriangle(matrix) << endl;

    // 6. Минимум верхнетреугольной части
    cout << "Минимум верхнетреугольной части: " << findMinUpperTriangle(matrix) << endl;

    // 7. Минимум главной диагонали
    cout << "Минимум главной диагонали: " << findMinMainDiagonal(matrix) << endl;

    // 8. Максимум главной диагонали
    cout << "Максимум главной диагонали: " << findMaxMainDiagonal(matrix) << endl;

    // 9. Минимум второй диагонали
    cout << "Минимум второй диагонали: " << findMinSecondaryDiagonal(matrix) << endl;

    // 10. Максимум второй диагонали
    cout << "Максимум второй диагонали: " << findMaxSecondaryDiagonal(matrix) << endl;

    // 11. Среднее арифметическое всех элементов
    int average = findAverageMatrix(matrix);
    cout << "Среднее арифметическое всех элементов: " << average << endl;

    // 12. Среднее арифметическое нижнетреугольной части
    cout << "Среднее арифметическое нижнетреугольной части: " << findAverageLowerTriangle(matrix) << endl;

    // 13. Среднее арифметическое верхнетреугольной части
    cout << "Среднее арифметическое верхнетреугольной части: " << findAverageUpperTriangle(matrix) << endl;

    // 14. Суммы строк
    findRowSums(matrix, rowSums);
    cout << "Суммы строк: ";
    for (int i = 0; i < N; i++) {
        cout << rowSums[i] << " ";
    }
    cout << endl;

    // 15. Суммы столбцов
    findColumnSums(matrix, colSums);
    cout << "Суммы столбцов: ";
    for (int j = 0; j < N; j++) {
        cout << colSums[j] << " ";
    }
    cout << endl;

    // 16. Минимальные значения строк
    findMinRowValues(matrix, minRowValues);
    cout << "Минимальные значения строк: ";
    for (int i = 0; i < N; i++) {
        cout << minRowValues[i] << " ";
    }
    cout << endl;

    // 17. Минимальные значения столбцов
    findMinColumnValues(matrix, minColValues);
    cout << "Минимальные значения столбцов: ";
    for (int j = 0; j < N; j++) {
        cout << minColValues[j] << " ";
    }
    cout << endl;

    // 18. Максимальные значения строк
    findMaxRowValues(matrix, maxRowValues);
    cout << "Максимальные значения строк: ";
    for (int i = 0; i < N; i++) {
        cout << maxRowValues[i] << " ";
    }
    cout << endl;

    // 19. Максимальные значения столбцов
    findMaxColumnValues(matrix, maxColValues);
    cout << "Максимальные значения столбцов: ";
    for (int j = 0; j < N; j++) {
        cout << maxColValues[j] << " ";
    }
    cout << endl;

    // 20. Средние арифметические значения строк
    findAverageRowValues(matrix, avgRowValues);
    cout << "Средние арифметические значения строк: ";
    for (int i = 0; i < N; i++) {
        cout << avgRowValues[i] << " ";
    }
    cout << endl;

    // 21. Средние арифметические значения столбцов
    findAverageColumnValues(matrix, avgColValues);
    cout << "Средние арифметические значения столбцов: ";
    for (int j = 0; j < N; j++) {
        cout << avgColValues[j] << " ";
    }
    cout << endl;

    // 22. Суммы нижнетреугольной и верхнетреугольной частей
    int lowerSum, upperSum;
    findTriangleSums(matrix, lowerSum, upperSum);
    cout << "Сумма нижнетреугольной части: " << lowerSum << endl;
    cout << "Сумма верхнетреугольной части: " << upperSum << endl;

    // 23. Элемент, наиболее близкий к среднему арифметическому
    int closestElement = findClosestToAverage(matrix, average);
    cout << "Элемент, наиболее близкий к среднему арифметическому: " << closestElement << endl;

    return 0;
}