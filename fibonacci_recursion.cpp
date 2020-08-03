#include <stdio.h>
#include <conio.h>

int Fibonacci1(int n) {
    if (n == 1 || n == 2)
        return 1;
    return Fibonacci1(n-1) + Fibonacci1(n-2);
}

int Fibonacci2(int n) {
    int before = 1, after = 1;
    int i = 1;
    while ((i++) < n) {
        after = before + after;
        before = after - before;
    }
    return after;
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    prinft("%d\n%d", Fibonacci1(n), Fibonacci2(n));
    return 0;
}