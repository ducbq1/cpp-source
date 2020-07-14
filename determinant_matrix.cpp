#include<iostream>
#include<math.h>
using namespace std;

float determinant(int** matrix, int n) {
    int det = 0;
    // cap phat bo nho cho submatrix
    int** submatrix = new int* [n];
    for (int i = 0; i < n; i++) {
        submatrix[i] = new int[n];
    }

    if (n == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
        }
    }

    // giai phong bo nho submatrix
    // for (int i = 0; i < n; i++) {
    //     delete[] submatrix[i];
    // }
    // delete[] submatrix;

    return det;
}


int** searchX(int** matrixA, int* matrixB,int size, int m) {

    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int [size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == m) {
                matrix[i][j] = matrixB[i];
            }
            else {
                matrix[i][j] = matrixA[i][j];
            }
        }
    }
    return matrix;

}




int main() {

    int n;
    cin >> n;
    int** matrixA = new int* [n];
    for (int i = 0; i < n; i++) {
        matrixA[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> matrixA[i][j];
        }
    }
    int* matrixB = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> matrixB[i];
    }

    for (int i = 0; i < n; i++) {
        cout << "Nghiem so " << i + 1 << " la: " << determinant(searchX(matrixA, matrixB, n, i), n) /
            determinant(matrixA, n) << '\n';
    }

    // for (int i = 0; i < n; i++) {
    //     delete[] matrixA[i];
    // }
    // delete[] matrixA;
    // delete[] matrixB;
    return 0;
}