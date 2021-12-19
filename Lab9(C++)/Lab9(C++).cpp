#include <iostream>
#include <ctime>
using namespace std;

void output_matrix(double**, int m, int n);

int main() {
    srand(time(NULL));
    int m, n;
    cout << "input number of lines: "; cin >> m;
    cout << "input number of columns: "; cin >> n;
    double** A = new double* [m];
    for (int i = 0; i < m; i++) {
        A[i] = new double[n];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 100;
        }
    }
    output_matrix(A, m, n);
    int i = 0;
    double X = 100;
    int last_min_M, last_min_N, temp_1;
    for (int j = 0; j < n; j++) {
        if (i == 0 || i == -1) {
            i = 0;
            temp_1 = 1;
        }
        else if (i == m) {
            i = i - 1;
            temp_1 = -1;
        }
        for (int k = 0; k < m; k++) {
            if (X >= A[i][j]) {
                X = A[i][j];
                last_min_M = i;
                last_min_N = j;
            }
            i = i + temp_1;
        }
    }

    cout << "last_min: " << X << endl;
    cout << "line: " << last_min_M + 1 << "  ";
    cout << "column: " << last_min_N + 1 << "\n\n";

    double temp;
    temp = A[0][last_min_N];
    A[0][last_min_N] = X;
    A[last_min_M][last_min_N] = temp;
    output_matrix(A, m, n);

    for (int i = 0; i < m; i++) {
        delete[] A[i];
    }
    delete[] A;
    system("pause");
    return 0;
}

void output_matrix(double* A[], int m, int n) {
    cout << "matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << endl;
}