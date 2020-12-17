#include <bits/stdc++.h>

using namespace std;

void test_case() {
  string a, b, c = "";
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  if (a.length() > b.length()) {
    swap(a, b);
  }
  int minLength = a.length();
  int maxLength = b.length();
  bool remember = 0;
  for (int i = 0; i < minLength; i++) {
    int temp = (a[i] - '0') + (b[i] - '0') + remember;
    c.push_back(temp % 10 + '0');
    remember = temp / 10;
  }
  for (int i = minLength; i < maxLength; i++) {
    int temp = (b[i] - '0') + remember;
    c.push_back(temp % 10 + '0');
    remember = temp / 10;
  }
  if (remember) {
    c.push_back(remember + '0');
  }
  reverse(c.begin(), c.end());
  cout << c << endl;
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
