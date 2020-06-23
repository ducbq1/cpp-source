#include <iostream>

double* maximum(double* a, int size) {
    double* max = &a[0];
    if (a == NULL) return NULL;
    for (int i = 0; i < size; ++i) {
        if (a[i] > *max) 
            max = a + i;
    }
    return max;
}

int main() {
    double myArray[] = {1, 5, 6, 343, 65, 4321, 43, 65};
    int size = sizeof(myArray) / sizeof(int);
    printf("%f", *maximum(myArray, size));
    return 0;
}
