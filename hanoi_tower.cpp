#include <iostream>

void move(int n, int a, int b, int c) {
    if (n > 0) {
        move(n - 1, a, c, b);
        printf("\n Move disk %d from %c to %c", n, a, c);
        move(n - 1, b, a, c);
    }
}

int main() {

    move(4, 'A', 'B', 'C');
    return 0;
}
