#include <iostream>
#include <cstring>
#include "./libjit/libjit_defs.h"

using namespace std;

const int N = 128;

struct Matrix {
    unsigned int mat[N][N];
    Matrix() {
        memset(mat, 0, sizeof(mat));
    }
};

bool operator == (const Matrix &a, const Matrix &b) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a.mat[i][j] != b.mat[i][j])
                return false;
        }
    }
    return true;
}

Matrix multiply_naive(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                c.mat[i][j] += a.mat[i][k] * a.mat[k][j];
            }
        }
    }
    return c;
}

// template <unsigned regsA, unsigned regsB>

Matrix multiply_fast(const Matrix &a, const Matrix &b) {
/***********************************************************

***********************************************************/\
    unsigned regsA, regsB;
    Matrix c;
    float8 csum[regsA][regsB] = {{0.0}};
    for (int p = 0; p < N; p++) {

        // Perform the DOT product.
        for (int bi = 0; bi < regsB; bi++) {
        float8 bb = LoadFloat8((p, bi * 8));
        for (int ai = 0; ai < regsA; ai++) {
            float8 aa = BroadcastFloat8((ai, p));
            csum[ai][bi] += aa * bb;
        }
        }
    }

    // Accumulate the results into C.
    for (int ai = 0; ai < regsA; ai++) {
        for (int bi = 0; bi < regsB; bi++) {
        AdduFloat8((Matrix)(ai, bi * 8), csum[ai][bi]);
        }
    }

}

Matrix gen_random_matrix() {
    Matrix a;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a.mat[i][j] = rand();
        }
    }
    return a;
}

Matrix base;

double benchmark(Matrix (*multiply) (const Matrix&, const Matrix&), Matrix& result) {
    const int NUM_TEST = 10;
    const int NUM_ITER = 64;

    Matrix a = base;
    result = a;

    double taken = 0;
    for (int t = 0; t < NUM_TEST; ++t) {
        clock_t start = clock();
        for (int i = 0; i < NUM_ITER; ++i) {
            a = multiply(a, result);
            result = multiply(result, a);
        }
        clock_t finish = clock();
        taken += (double)(finish - start);
    }
    taken /= NUM_TEST;
    printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
}

int main() {
    base = gen_random_matrix();

    Matrix a, b;
    printf("Slow version\n");
    double slow = benchmark(multiply_naive, a);
    printf("Fast version\n");
    double fast = benchmark(multiply_fast, b);

    if (a == b) {
        printf("Correct answer! Your code is %.2f%% faster\n", slow / fast * 100.0);
    } else {
        printf("Wrong answer!\n");
    }
    return 0;
}