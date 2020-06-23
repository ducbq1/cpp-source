#include <stdio.h>

int lucas(int n) {
    if (n < 2) {
        return 2 - n;
    } else {
        return lucas(n-1) + lucas(n-2);
    }
}

int main() {
    for (int n = 0; n <= 10; ++n) {
        printf("L[%d] = %d\n", n, lucas(n));
    }
    return 0;
}