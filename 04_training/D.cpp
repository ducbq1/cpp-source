#include <bits/stdc++.h>

using namespace std;

bool check(long long maxVal, int n, int m, int a[]) {
  vector<int> pos;
  long long sum = 0; 
  for (int i = n - 1; i >= 0; i--) {
    if (sum + a[i] <= maxVal) {
      sum += a[i];
    } else {
      sum = a[i];
      if (a[i] > maxVal) {
        return false;
      }
      pos.push_back(i);
    }
  }
  if (pos.size() >= m) {
    return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int testCase;
  cin >> testCase;
  // while(testCase--) {}
  for (int i = 0; i < testCase; i++) {
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
      if (check(a[i], n, m, a)) {
        cout << "1";
      }
      // 100 / 100 / 100 / 100 100
    }
  }
  return 0;
}
