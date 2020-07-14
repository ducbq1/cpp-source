#pragma comment(lib, "CramerMatrix.lib")

#include <iostream>
#include <fstream>
#include <math.h>
#include "../testLib/CramerMatrix.h"
using namespace std;

int main() {
	int m, n;
	cout << "Chon 100 de chon ma tran tu file, chon so khac de nhap tay!\n";
	cin >> m;
	if (m == 100) {
		int** matrixA = readFileTwoDimensional("matrixA.txt");
		int* matrixB = readFileOneDimensional("matrixB.txt");
		int sizeM = getQuantity("matrixB.txt");
		char buf[1024], solution[1024] = "";

		for (int i = 0; i < sizeM; i++) {
			float a = determinant(searchX(matrixA, matrixB, sizeM, i), sizeM) / determinant(matrixA, sizeM);
			cout << "Nghiem thu " << i + 1 << " la: " << a;
			sprintf_s(buf, "X %d la: %f\n", i + 1, a);
			strcat_s(solution, buf);
			cout << '\n';
		}
		//writeFileBinary("result.bin", solution);
		writeFile("result_one.txt", solution);

		char conclusion[256] = "";
		for (int i = 0; i < sizeM; i++) {
			float det = determinant(searchX(matrixA, matrixB, sizeM, i), sizeM);
			sprintf_s(buf, "Dinh thuc cua ma tran thu %d la: %f\n", i + 1, det);
			strcat_s(conclusion, buf);
		}
		writeFile("result_new_method.txt", conclusion);
		writeFileBinary("result.bin", conclusion);

		char* test = readFileBinary("result.bin");
		cout << test;

		return 0;
	}
	else {
		cout << "Nhap kich thuoc ma tran vuong\n";
		cin >> n;
		cout << "Nhap ma tran A\n";
		int** matrixA = insertMatrixA(n);
		cout << "Nhap ma tran B\n";
		int* matrixB = insertMatrixB(n);
		for (int i = 0; i < n; i++) {
			cout << "Nghiem thu " << i + 1 << " la: " << determinant(searchX(matrixA, matrixB, n, i), n) / determinant(matrixA, n);
			cout << '\n';
		}
		return 0;
	}
}