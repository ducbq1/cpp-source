#include <bits/stdc++.h>

using namespace std;

void print_array(int array[], int n) {
  for (int i = 0; i < n; i++) {
    cout << array[i] << ' ';
  }
  cout << '\n';
}

void permute(int array[], int left, int right) {
  
  if (left == right) {
    print_array(array, right + 1);
  } else {
    for (int i = left; i <= right; i++) {
      swap(array[i], array[left]);
      permute(array, left + 1, right);
      swap(array[i], array[left]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int array[n];
  for (int i = 1; i <= n; i++) {
    array[i - 1] = i;
  }

  permute(array, 0, n - 1);

  return 0;
}
