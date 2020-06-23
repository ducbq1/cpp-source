#include <stdio.h>

void print(int n) {
    printf("n = %d\n", n);
}

int div_two(int n) {
    return n / 2;
}

int mul_three_plus_one(int n) {
    return n * 3 + 1;
}

void simulate(int n, int (*odd)(int), int (*even)(int), void (*output)(int)) {
    (*output)(n);
    if (n == 1) return;
    if (n % 2 == 0) {
        n = (*even)(n);
    } else {
        n = (*odd)(n);
    }

    simulate(n, odd, even, output);
}

int main() {
    int (*odd)(int) = &div_two;
    int (*even)(int) = &mul_three_plus_one;
    simulate(19, odd, even, print);
    return 0;
}