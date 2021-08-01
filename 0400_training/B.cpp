#include <bits/stdc++.h>
#include <string>

using namespace std;

string initial_fibwords(int n) {
  if (n == 0) return "0";
  if (n == 1) return "1";
  return initial_fibwords(n - 1).append(initial_fibwords(n - 2));
}

long long countPattern(string fibWord, string bitPattern) {
  int count = 0;
  size_t found = fibWord.find(bitPattern, 0);
  while (found != string::npos) {
    found = fibWord.find(bitPattern, found + 1);
    count++;
  }
  return count;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, i = 0;
  while (cin >> n) {
    string bitPattern;
    cin >> bitPattern;
    string fibWord = initial_fibwords(n);
    cout << "Case " << i + 1 << ": " << countPattern(fibWord, bitPattern);
    i++;
  }
  // string bitPattern;
  // cin >> n >> bitPattern;
  // cout << initial_fibwords(n);
  // string fibWord = initial_fibwords(n);
  //cout << countPattern(fibWord, bitPattern);
  return 0;
}
