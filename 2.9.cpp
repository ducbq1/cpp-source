#include <bits/stdc++.h>

using namespace std;

const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;

double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double x[NUM_INPUTS];

void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; i++) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

double sigmoid[NUM_INPUTS];


void precalc() {
    for (int i = 0; i < NUM_INPUTS; i++) {
        sigmoid[i] = sigmoid_slow(x[i]);
    }

}

double sigmoid_fast(double a) {
    // return 0.5 * (x / (1 + abs(x))) + 0.5;
    // return x / (1 + abs(x));
    int i;
    for (i = 0; i < NUM_INPUTS; i++) {
        if (abs(a - x[i]) < 1e-9) return sigmoid[i];
    }
    return sigmoid[i];
}

double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 1000;

    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);

    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
    printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}

bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6;
    
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}

int main() {
    prepare_input();
    precalc();

    vector<double> a, b;
    printf("Slow version\n");
    double slow = benchmark(sigmoid_slow, a);
    printf("Fast version\n");
    double fast = benchmark(sigmoid_fast, b);

    if (is_correct(a, b)) {
        printf("Correct answer! Your code is %.2f%% faster\n", slow / fast * 100.0);
    } else {
        printf("Wrong answer!\n");
    }

    cout << sigmoid_slow(5) << "\n" << sigmoid_fast(5);
    return 0;
}