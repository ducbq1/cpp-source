#include <bits/stdc++.h>
#include <string>

using namespace std;

void test_case() {
  string a, b, c = "";
  cin >> a >> b;
  if (a.length() < b.length()) {
    swap(a, b);
  }

  int lengthA = a.length(), lenghtB = b.length();

  for (int i = 0; i < lengthA - lenghtB; i++) {
    b.push_back('0');
  }

  bool carry = 0;
  for (int i = lengthA - 1; i >= 0; i--) {
    int sum = (a[i] - '0') + (b[i] - '0') + carry;
    c = to_string(sum % 10) + c;
    carry = sum / 10;
  }
  if (carry) {
    c = "1" + c;
  }
  cout << a << endl;
  cout << b << endl;
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
