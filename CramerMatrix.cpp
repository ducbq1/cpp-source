// CramerMatrix.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "CramerMatrix.h"
#include <iostream>
#include <fstream>
using namespace std;

// TODO: This is an example of a library function
#include <math.h>
float determinant(int** matrix, int n) {
    float det = 0;
    // cap phat bo nho cho submatrix
    int** submatrix = new int* [n];
    for (int i = 0; i < n; i++) {
        submatrix[i] = new int[n];
    }

    if (n == 2)
        return (float)((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
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

int** searchX(int** matrixA, int* matrixB, int size, int m) {

    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
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

int** insertMatrixA(int size) {
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++) {
            cin >> *(*(matrix + i) + j);
        }
    }
    return matrix;
}

int* insertMatrixB(int size) {
    int* matrix = new int[size];
    for (int i = 0; i < size; i++)
        cin >> matrix[i];
    return matrix;
}

void writeFile(const char* nameFile, char* buf) {
    std::ofstream outfile;
    outfile.open(nameFile);
    //std::cout << "Writing to the file" << '\n';
    /*std::cin >> data;
    std::cin.ignore();*/
    outfile << buf << '\n';
    outfile.close();
}
void writeFileMethodTwo(const char* nameFile, char* buf) {
    std::ofstream outfile;
    outfile.open(nameFile, ios::ate);
    outfile << buf << '\n';
    outfile.close();
}

int* readFileOneDimensional(const char* nameFile) {
    char data[100];
    std::ifstream infile;
    infile.open(nameFile);
    //std::cout << "Reading from the file" << '\n';
    int i = 0;
    int temp = 0;
    int tem[40];
    while (infile >> data) {
        sscanf_s(data, "%d", &temp);
        i++;
        tem[i - 1] = temp;
    }
    int* matrix = new int[i];
    for (int x = 0; x < i; x++) {
        matrix[x] = tem[x];
    }
    infile.close();
    return matrix;
}

int** readFileTwoDimensional(const char* nameFile) {
    char data[100];
    std::ifstream infile;
    infile.open(nameFile);
    //std::cout << "Reading from the file" << '\n';
    int i = 0;
    int temp = 0;
    int tem[100];
    while (infile >> data) {
        sscanf_s(data, "%d", &temp);
        i++;
        tem[i - 1] = temp;
    }
    int j = sqrt(i);

    // cap phat bo nho
    int** matrix = new int* [j];
    for (int i = 0; i < j; i++) {
        matrix[i] = new int[j];
    }

    for (int a = 0; a < j; a++) {
        for (int b = 0; b < j; b++) {
            matrix[a][b] = tem[j * a + b];
        }
    }

    infile.close();
    return matrix;
}

int getQuantity(const char* nameFile) {
    char data[100];
    std::ifstream infile;
    infile.open(nameFile);
    int i = 0;
    while (infile >> data) {
        i++;
    }
    return i;
}


char* readFileBinary(const char* nameFile) {
    char buf[100];
    ifstream file(nameFile, ios::in | ios::binary);
    if (file.is_open())
    {
        file.read(buf, 100);
        file.close();
    }
    return buf;
}

void writeFileBinary(const char* nameFile, char* buf) {
    ofstream file(nameFile, ios::out | ios::binary | ios::ate);
    if (file.is_open())
    {
        file.write(buf, 100);
        file.close();
    }
}

