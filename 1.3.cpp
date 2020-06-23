#include <stdio.h>

int main() {
    int x = 25, y = 50, z = 75;
    int* ptr;
    printf("Here are the values of x, y and z: \n");
    printf("%d %d %d\n", x, y, z);
    ptr = &x;
    (*ptr) += 100;
    ptr = &y;
    (*ptr) += 100;
    ptr = &z;
    (*ptr) += 100;
    printf("Once again, here are the values of x, y and z: \n");
    printf("%d %d %d", x, y, z);
    return 0;
}