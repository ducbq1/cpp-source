#include <bits/stdc++.h>

using namespace std;

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i];
  }
  cout << '\n';
}

void binary_list(int n, int arr[], int i) {

  if (i == n) {
    print_array(arr, n);
    return;
  }

  arr[i] = 0;
  binary_list(n, arr, i + 1);

  arr[i] = 1;
  binary_list(n, arr, i + 1);
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  binary_list(n, arr, 0);
  return 0;
}
