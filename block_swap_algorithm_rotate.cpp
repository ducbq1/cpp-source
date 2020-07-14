#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
}

void swap(int arr[], int fi, int si, int d) {
    int i, temp;
    for (i = 0; i < d; i++) {
        temp = arr[fi+i];
        arr[fi+i] = arr[si+i];
        arr[si+i] = temp;
    }
}

void leftRotate(int arr[], int d, int n) {
    if (d == 0 || d == n)
        return;
    
    if (n - d == d) {
        swap(arr, 0, n - d, d);
        return;
    }

    if (d < n - d) {
        swap(arr, 0, n - d, d);
        leftRotate(arr, d, n - d);
    } else {
        swap(arr, 0, d, n - d);
        leftRotate(arr + n - d, 2 * d - n, d);
    }
}



int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);
    leftRotate(arr, 2, n);
    printArray(arr, n);
    return 0;
}