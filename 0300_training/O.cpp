#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  for (int i = 0; i < k - 1; i++) {
    if (!next_permutation(a, a + n)) {
      cout << -1;
      return 0;
    };
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}
