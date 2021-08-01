#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, temp1, temp2;
  cin >> n;
  cin >> temp1;
  for (int i = 1; i < n; i++) {
    cin >> temp2;
    if (temp2 <= temp1) {
      cout << 0;
      return 0;
    }
    temp1 = temp2;
  }
  cout << 1;
  return 0;
}
