#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int k, arr[100] = {};
  // cin >> s;
  getline(cin, s);
  cin >> k;
  
  for (int i = 0; i < s.length(); i++) {
    arr[s[i] - 32]++;
  }
  for (int i = 0; i < s.length(); i++) {
    if (arr[s[i] - 32] < k) {
      s.replace(i, 1, "_");
    }
  }
  cout << s;
}
