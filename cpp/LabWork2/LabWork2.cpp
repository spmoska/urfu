using namespace std;
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#define N 5

// ������� ��� ������ �������
void printMatrix(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(8) << setprecision(2) << m[i][j];
        }

        cout << endl;
    }
}

// ������� ��� ���������� ������� ���������� ������� �� 0 �� 10
void fillMatrix(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = rand() % 100;
        }
    }
}

// ������� ��� ���������� �������� �������
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

// ������� ��� ���������� ��������� �������
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

// ������� ��� ���������� ��������� ���������������� �����
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

// ������� ��� ���������� ��������� ����������������� �����
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

// ������� ��� ���������� �������� ���������������� �����
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

// ������� ��� ���������� �������� ����������������� �����
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

// ������� ��� ���������� �������� ������� ���������
int findMinMainDiagonal(int m[N][N]) {
    int minVal = numeric_limits<int>::max();

    for (int i = 0; i < N; i++) {
        if (m[i][i] < minVal) {
            minVal = m[i][i];
        }
    }

    return minVal;
}

// ������� ��� ���������� ��������� ������� ���������
int findMaxMainDiagonal(int m[N][N]) {
    int maxVal = numeric_limits<int>::lowest();

    for (int i = 0; i < N; i++) {
        if (m[i][i] > maxVal) {
            maxVal = m[i][i];
        }
    }

    return maxVal;
}

// ������� ��� ���������� �������� ������ ���������
int findMinSecondaryDiagonal(int m[N][N]) {
    int minVal = numeric_limits<int>::max();

    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] < minVal) {
            minVal = m[i][N - 1 - i];
        }
    }

    return minVal;
}

// ������� ��� ���������� ��������� ������ ���������
int findMaxSecondaryDiagonal(int m[N][N]) {
    int maxVal = numeric_limits<int>::lowest();

    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] > maxVal) {
            maxVal = m[i][N - 1 - i];
        }
    }

    return maxVal;
}

// ������� ��� ���������� �������� ��������������� ���� ��������� �������
int findAverageMatrix(int m[N][N]) {
    int sum = 0.0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
    }

    return sum / (N * N);
}

// ������� ��� ���������� �������� ��������������� ���������������� �����
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

// ������� ��� ���������� �������� ��������������� ����������������� �����
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

// ������� ��� ���������� ���� �����
void findRowSums(int m[N][N], int rowSums[N]) {
    for (int i = 0; i < N; i++) {
        rowSums[i] = 0.0;

        for (int j = 0; j < N; j++) {
            rowSums[i] += m[i][j];
        }
    }
}

// ������� ��� ���������� ���� ��������
void findColumnSums(int m[N][N], int colSums[N]) {
    for (int j = 0; j < N; j++) {
        colSums[j] = 0.0;

        for (int i = 0; i < N; i++) {
            colSums[j] += m[i][j];
        }
    }
}

// ������� ��� ���������� ����������� �������� �����
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

// ������� ��� ���������� ����������� �������� ��������
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

// ������� ��� ���������� ������������ �������� �����
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

// ������� ��� ���������� ������������ �������� ��������
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

// ������� ��� ���������� ������� �������������� �������� �����
void findAverageRowValues(int m[N][N], int avgRowValues[N]) {
    for (int i = 0; i < N; i++) {
        avgRowValues[i] = 0.0;

        for (int j = 0; j < N; j++) {
            avgRowValues[i] += m[i][j];
        }

        avgRowValues[i] /= N;
    }
}

// ������� ��� ���������� ������� �������������� �������� ��������
void findAverageColumnValues(int m[N][N], int avgColValues[N]) {
    for (int j = 0; j < N; j++) {
        avgColValues[j] = 0.0;

        for (int i = 0; i < N; i++) {
            avgColValues[j] += m[i][j];
        }

        avgColValues[j] /= N;
    }
}

// ������� ��� ���������� ���� ���������������� � ����������������� ������
void findTriangleSums(int m[N][N], int& lowerSum, int& upperSum) {
    lowerSum = 0.0;
    upperSum = 0.0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) { // ������ ����������� �����
            lowerSum += m[i][j];
        }

        for (int j = i + 1; j < N; j++) { // ������� ����������� �����
            upperSum += m[i][j];
        }
    }
}

// ������� ��� ���������� ��������, �������� �������� � �������� ���������������
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

    // ���������� ������� ���������� �������
    fillMatrix(matrix);

    // ����� �������
    cout << "�������:" << endl;
    printMatrix(matrix);

    // 1. ������� �������
    cout << "������� �������: " << findMinMatrix(matrix) << endl;

    // 2. �������� �������
    cout << "�������� �������: " << findMaxMatrix(matrix) << endl;

    // 3. �������� ���������������� �����
    cout << "�������� ���������������� �����: " << findMaxLowerTriangle(matrix) << endl;

    // 4. �������� ����������������� �����
    cout << "�������� ����������������� �����: " << findMaxUpperTriangle(matrix) << endl;

    // 5. ������� ���������������� �����
    cout << "������� ���������������� �����: " << findMinLowerTriangle(matrix) << endl;

    // 6. ������� ����������������� �����
    cout << "������� ����������������� �����: " << findMinUpperTriangle(matrix) << endl;

    // 7. ������� ������� ���������
    cout << "������� ������� ���������: " << findMinMainDiagonal(matrix) << endl;

    // 8. �������� ������� ���������
    cout << "�������� ������� ���������: " << findMaxMainDiagonal(matrix) << endl;

    // 9. ������� ������ ���������
    cout << "������� ������ ���������: " << findMinSecondaryDiagonal(matrix) << endl;

    // 10. �������� ������ ���������
    cout << "�������� ������ ���������: " << findMaxSecondaryDiagonal(matrix) << endl;

    // 11. ������� �������������� ���� ���������
    int average = findAverageMatrix(matrix);
    cout << "������� �������������� ���� ���������: " << average << endl;

    // 12. ������� �������������� ���������������� �����
    cout << "������� �������������� ���������������� �����: " << findAverageLowerTriangle(matrix) << endl;

    // 13. ������� �������������� ����������������� �����
    cout << "������� �������������� ����������������� �����: " << findAverageUpperTriangle(matrix) << endl;

    // 14. ����� �����
    findRowSums(matrix, rowSums);
    cout << "����� �����: ";
    for (int i = 0; i < N; i++) {
        cout << rowSums[i] << " ";
    }
    cout << endl;

    // 15. ����� ��������
    findColumnSums(matrix, colSums);
    cout << "����� ��������: ";
    for (int j = 0; j < N; j++) {
        cout << colSums[j] << " ";
    }
    cout << endl;

    // 16. ����������� �������� �����
    findMinRowValues(matrix, minRowValues);
    cout << "����������� �������� �����: ";
    for (int i = 0; i < N; i++) {
        cout << minRowValues[i] << " ";
    }
    cout << endl;

    // 17. ����������� �������� ��������
    findMinColumnValues(matrix, minColValues);
    cout << "����������� �������� ��������: ";
    for (int j = 0; j < N; j++) {
        cout << minColValues[j] << " ";
    }
    cout << endl;

    // 18. ������������ �������� �����
    findMaxRowValues(matrix, maxRowValues);
    cout << "������������ �������� �����: ";
    for (int i = 0; i < N; i++) {
        cout << maxRowValues[i] << " ";
    }
    cout << endl;

    // 19. ������������ �������� ��������
    findMaxColumnValues(matrix, maxColValues);
    cout << "������������ �������� ��������: ";
    for (int j = 0; j < N; j++) {
        cout << maxColValues[j] << " ";
    }
    cout << endl;

    // 20. ������� �������������� �������� �����
    findAverageRowValues(matrix, avgRowValues);
    cout << "������� �������������� �������� �����: ";
    for (int i = 0; i < N; i++) {
        cout << avgRowValues[i] << " ";
    }
    cout << endl;

    // 21. ������� �������������� �������� ��������
    findAverageColumnValues(matrix, avgColValues);
    cout << "������� �������������� �������� ��������: ";
    for (int j = 0; j < N; j++) {
        cout << avgColValues[j] << " ";
    }
    cout << endl;

    // 22. ����� ���������������� � ����������������� ������
    int lowerSum, upperSum;
    findTriangleSums(matrix, lowerSum, upperSum);
    cout << "����� ���������������� �����: " << lowerSum << endl;
    cout << "����� ����������������� �����: " << upperSum << endl;

    // 23. �������, �������� ������� � �������� ���������������
    int closestElement = findClosestToAverage(matrix, average);
    cout << "�������, �������� ������� � �������� ���������������: " << closestElement << endl;

    return 0;
}