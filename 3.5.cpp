#include <stdio.h>

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;;
    return binom(n-1, k) + binom(n-1, k-1);
}

int C[1000][1000];
int binom2(int n, int k) {
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        C[i][0] = C[i][i] = 1;
    }
    return C[n][k];
}

int main() {
    for (int n = 1; n <= 10; ++n) {
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= 10; ++n) {
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}