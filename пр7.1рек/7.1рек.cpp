#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Sort(int** a, const int rowCount, const int colCount, int i0, int i1);
void Change(int* row1, int* row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j);

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    const int Low = 11;
    const int High = 74;
    const int rowCount = 8;
    const int colCount = 9;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High, 0, 0);
    Print(a, rowCount, colCount, 0, 0);
    Sort(a, rowCount, colCount, 0, 0);
    Print(a, rowCount, colCount, 0, 0);

    int S = 0;
    int k = 0;
    Calc(a, rowCount, colCount, S, k, 0, 0);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    Print(a, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, rowCount, colCount, Low, High, j == colCount - 1 ? i + 1 : i, (j + 1) % colCount);
        }
    }
}

void Print(int** a, const int rowCount, const int colCount, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            cout << setw(4) << a[i][j];
            Print(a, rowCount, colCount, i, j + 1);
        }
        else {
            cout << endl;
            Print(a, rowCount, colCount, i + 1, 0);
        }
    }
    else {
        cout << endl << endl;
    }
}

void Sort(int** a, const int rowCount, const int colCount, int i0, int i1) {
    if (i0 < rowCount - 1) {
        if (i1 < rowCount - i0 - 1) {
            if ((a[i1][0] > a[i1 + 1][0]) ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] < a[i1 + 1][1]) ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][3] < a[i1 + 1][3])) {
                Change(a[i1], a[i1 + 1], colCount);
            }
            Sort(a, rowCount, colCount, i0, i1 + 1);
        }
        else {
            Sort(a, rowCount, colCount, i0 + 1, 0);
        }
    }
}

void Change(int* row1, int* row2, const int colCount) {
    if (colCount > 0) {
        int tmp = row1[colCount - 1];
        row1[colCount - 1] = row2[colCount - 1];
        row2[colCount - 1] = tmp;
        Change(row1, row2, colCount - 1);
    }
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j) {
    if (i < rowCount) {
        if (j < colCount) {
            if (a[i][j] % 6 == 0 && !((i + j) % 5 == 0)) {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
            Calc(a, rowCount, colCount, S, k, i, j + 1);
        }
        else {
            Calc(a, rowCount, colCount, S, k, i + 1, 0);
        }
    }
}
