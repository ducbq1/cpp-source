#include <bits/stdc++.h>
using namespace std;

void fix(int *, int);

void rearrange(int arr[], int n) {
  int newArr[n];
  // memcpy(&newArr, &arr, n);
  for (int i = 0; i < n; i++) {
    if (arr[i] != i) {
      for (int j = 0; j < n; j++) {
        if (arr[j] == i) {
          int x = arr[j];
          arr[j] = arr[i];
          arr[i] = arr[j];
          break;
        }
      }
    } else {
      continue;
    }
  }
}

int main() {
  int arr[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
  int n = sizeof (arr) / sizeof (arr[0]);
  fix(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
  return 0;
}

void fix(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] != -1 && arr[i] != i) {
      int x = arr[i];
      while (arr[x] != -1 && arr[x] != x)
      {
        int y = arr[x];
        arr[x] = x;
        x = y;
      }
      arr[x] = x;

      if (arr[i] != i) {
        arr[i] = -1;
      }
    }
  }
}


