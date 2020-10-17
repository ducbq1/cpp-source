#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
  
}


int pour(int x, int y, int z) {
  
  if (x < y) { swap(x, y); }

  int from = 0, to = 0, step = 0;

  while ((from != z) && (to != z))
  {

    if (from == x) {
      step++;
      from = 0;
    }

    if (to == 0) {
      step++;
      to = y;
    }

    if ((from < x) && (to > 0)) {
      step++;
      int temp = min(x - from, to);
      from += temp;
      to -= temp;
    }
    
  }
  return step;
}


int main() {

  int x, y, z;
  cin >> x >> y >> z;
  if (z % gcd(x, y) == 0) {
    cout << pour(x, y, z) << '\n';
  } else {
    cout << -1 << '\n';
  }

  return 0;
}
