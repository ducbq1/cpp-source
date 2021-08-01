#include <bits/stdc++.h>
using namespace std;

int max_sum_subarray(int a[], int size);

int main() {
  int size;
  cin >> size;
  int a[size];
  for (int i = 0; i < size; i++) {
    cin >> a[i];
  }
  cout << max_sum_subarray(a, size);
  return 0;
}

int max_sum_subarray(int a[], int size) {
  int max = -2147483648, max_ending = 0;

  for (int i = 0; i < size; i++) {
    max_ending = max_ending + a[i];

    if (max < max_ending) {
      max = max_ending;
    }

    if (max_ending < 0) {
      max_ending = 0;
    }
  }

  return max;
}
