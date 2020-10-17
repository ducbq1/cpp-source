#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end);
void leftRotate(int arr[], int d, int n);
void printArray(int arr[], int n);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    d = d % n;
    leftRotate(arr, d, n);
    printArray(arr, n);

    return 0;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void leftRotate(int arr[], int d, int n) {
    if (d == 0) {
        return;
    }
    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
    reverseArray(arr, 0, n - 1);
}