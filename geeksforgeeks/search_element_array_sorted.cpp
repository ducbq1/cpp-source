#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low,
                 int high, int key)
{
    if (high < low)
        return -1;
    
    int mid = (low + high) / 2;
    if (key == arr[mid])
        return mid;
    
    if (key > arr[mid]) {
        return binarySearch(arr, (mid + 1), high, key);
    } else {
        return binarySearch(arr, 0, (mid - 1), key);
    }
}

int main() {
    int arr[] = {1, 2, 5, 6, 7, 134, 256};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 134;
    cout << binarySearch(arr, 0, n-1, key);
    cout << '\n' << n;
    return 0;
}