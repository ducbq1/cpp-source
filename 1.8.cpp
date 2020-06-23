#include <iostream>
using namespace std;

void input(int** mt, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> *(*(mt + i) + j);
    }
}

void output(int** mt, int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cout << mt[i][j] << " ";
}

int process(int** mt, int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (*(*(mt + i) + j) % 2 == 0)
                sum += *(*(mt + i) + j);
    return sum;
}

void free_mem(int*** mt, int m, int n) {
    for (int i = 0; i < m; i++)
        delete[] mt[i];
    delete[] mt;
}

int main() {
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d %d", &m, &n);
    mt = new int*[m];
    for (int i = 0; i < m; i++)
        mt[i] = new int[n];
    input(mt, m, n);
    output(mt, m, n);
    printf("\nThe sum of all even elements is %d\n", process(mt, m, n));
    free_mem(&mt, m, n);
    return 0;
}