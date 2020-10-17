// cpp program to split array and move first
// part to the end
#include <bits/stdc++.h>
using namespace std;

void split_array(int arr[], int n, int k) {
  for (int i = 0; i < k; i++) {
    int m = arr[0];
    for (int j = 0; j < n - 1; ++j)
      arr[j] = arr[j + 1];
    arr[n - 1] = m;
  }
}

int main() {
  int arr[] = {12, 10, 5, 6, 52, 36};
  int n = sizeof(arr) / sizeof(arr[0]);
  int position = 2;
  split_array(arr, n, position);

  for (int i = 0; i < n; i++)
    cout << arr[i] << ' ';
  return 0;
}
