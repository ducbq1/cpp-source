#include <bits/stdc++.h>
using namespace std;

void malloc_matrix(int*** matrix, int n) {
    int** temp = new int*[n];
    for (int i = 0; i < n; i++) {
        temp[i] = new int[n];
    }
    *matrix = temp;
}

void input_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void print_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(*(matrix + i) + j) << "\t";
        }
        cout << '\n';
    }
}

void sum_matrix(int** matrixMul, int** matrixOne, int** matrixTwo, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrixMul[i][j] = matrixOne[i][j] + matrixTwo[i][j];
        }
    }
}

void mul_matrix(int** matrixMul, int** matrixOne, int** matrixTwo, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrixMul[i][j] = 0;
            for (int k = 0; k < n; k++) {
                matrixMul[i][j] += matrixOne[i][k] * matrixTwo[k][j];
            }
        }
    }
}

void free_matrix(int*** matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] *matrix[i];
    }
    delete[] *matrix;
}

int main() {
    int n;
    cin >> n;

    int **matrixOne, **matrixTwo, **matrixSum, **matrixMul;

    malloc_matrix(&matrixOne, n);
    malloc_matrix(&matrixTwo, n);
    malloc_matrix(&matrixSum, n);
    malloc_matrix(&matrixMul, n);
   

    // int** matrixOne = new int*[n];
    // for (int i = 0; i < n; i++) {
    //     matrixOne[i] = new int[n];
    // }int** matrixTwo = new int*[n];
    // for (int i = 0; i < n; i++) {
    //     matrixTwo[i] = new int[n];
    // }int** matrixSum = new int*[n];
    // for (int i = 0; i < n; i++) {
    //     matrixSum[i] = new int[n];
    // }int** matrixMul = new int*[n];
    // for (int i = 0; i < n; i++) {
    //     matrixMul[i] = new int[n];
    // }

    cout << "Nhap ma tran 1\n";
    input_matrix(matrixOne, n);
    cout << "Nhap ma tran 2\n";
    input_matrix(matrixTwo, n);

    sum_matrix(matrixSum, matrixOne, matrixTwo, n);
    mul_matrix(matrixMul, matrixOne, matrixTwo, n);

    cout << "\nMa tran 1\n";
    print_matrix(matrixOne, n);
    cout << "\nMa tran 2\n";
    print_matrix(matrixTwo, n);
    cout << "\nMa tran tong\n";
    print_matrix(matrixSum, n);
    printf("\nMa tran tich\n");
    print_matrix(matrixMul, n);

    free_matrix(&matrixOne, n);
    cout << &matrixOne << "\t" << *matrixOne;
    free_matrix(&matrixTwo, n);
    // free_matrix(&matrixSum, n);
    // free_matrix(&matrixMul, n);
    

    return 0;
    
}
