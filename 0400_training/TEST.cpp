#include <bits/stdc++.h>

using namespace std;

void test_case() {
  unsigned long long a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int testCase;
  cin >> testCase;
  for (int i = 0; i < testCase; i++) {
    test_case();
  }
  return 0;
}
