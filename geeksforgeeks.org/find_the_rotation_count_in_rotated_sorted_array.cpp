#include <bits/stdc++.h>
using namespace std;

int countRotations(int arr[], int n) {
  int min = arr[0], indexMin;
  for (int i = 0; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
      indexMin = i;
    }
  }
  return indexMin;
}

int countRotationsNewMethod(int arr[], int low, int high) {
  
  if (high < low) return 0;
  if (high == low) return low;

  int mid = (high + low) / 2;

  if (mid < high && arr[mid + 1] < arr[mid]) return mid + 1;
  if (mid > low && arr[mid] > arr[mid - 1]) return mid;
  if (arr[high] > arr[mid]) return countRotationsNewMethod(arr, low, mid - 1);
  return countRotationsNewMethod(arr, mid + 1, high);
}

int main() {
  return 0;
}
