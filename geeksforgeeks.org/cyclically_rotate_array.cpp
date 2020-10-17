#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n) {
    int x = arr[n - 1];
    for (int i = 1; i < n - 1; i++)
        arr[i] = arr[i - 1];
    arr[0] = x;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    rotate(arr, n);
    return 0;
}
