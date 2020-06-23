#include <stdio.h>

int get_value(int x, int a = 2, int b = 1, int c = 0) {
    if (x == 7) throw "Error!";
    return a * x * x + b * x + c;
}

int main() {
    try {
        int x;
        printf("Nhap x: ");
        while (scanf("%d", &x) && x >= 100) printf("Nhap lai x: ");
        // scanf("%d", &x);
        int a = 2017;
        int b = 3023;
        int c = 20173023;
        printf("a = %d, b = %d, c = %d: %d\n", a, b, c, get_value(x, a, b, c));
    } catch (const char* temp) {
        printf("%s", temp);
    }
    
    
    return 0;
}