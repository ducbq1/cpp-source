#include <bits/stdc++.h>
using namespace std;

string addLarge(string a, string b)
{
  if (a.length() > b.length()) {
    swap(a, b);
  }

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int over_ten = 0;
  string c = "";

  for (int i = 0; i < a.length(); i++) {
    int sum = (a[i] - '0') + (b[i] - '0') + over_ten;
    c.push_back(sum % 10 + '0');
    over_ten = sum / 10;
  }

  for (int i = a.length(); i < b.length(); i++) {
    int sum = (b[i] - '0') + over_ten;
    c.push_back(sum % 10 + '0');
    over_ten = sum / 10;
  }
  
  if (over_ten) {
    c.push_back(over_ten + '0');
  }
  reverse(c.begin(), c.end());
  return c;
}


int main() {

  string a , b;
  getline(cin, a);
  getline(cin, b);

  cout << addLarge(a, b);
}
