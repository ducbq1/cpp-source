#include <bits/stdc++.h>

int count_even(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int myArray[] = {4, 6, 34, 7, 4, 5, 90};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int test = count_even(myArray, size);
    printf("%d", test);
    return 0;
}