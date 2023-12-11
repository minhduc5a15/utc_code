#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int m, n, p;
    cin >> m >> n >> p;
    int **A = new int *[m];
    for (int i = 0; i < m; ++i) {
        A[i] = new int[n];
    }

    int **B = new int *[n];
    for (int i = 0; i < n; ++i) {
        B[i] = new int[p];
    }

    int **C = new int *[m];
    for (int i = 0; i < m; ++i) {
        C[i] = new int[p];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            cout << setw(10) << C[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < m; ++i) {
        delete[] A[i];
    }
    delete[] A;

    for (int i = 0; i < n; ++i) {
        delete[] B[i];
    }
    delete[] B;

    for (int i = 0; i < m; ++i) {
        delete[] C[i];
    }
    delete[] C;

    return 0;
}


// code by duck it1
