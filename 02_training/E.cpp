#include <bits/stdc++.h>

using namespace std;

int main() {
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int t[n + 2];
  
  t[0] = -777;
  t[n + 1] = -999;

  int ret = 0;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];

    if (t[i] != t[i - 1]) {
      ret++;
    }

  }
  

  int q, p, c;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> p >> c;
    ret -= (c == t[p - 1]) + (c == t[p + 1]);
    ret += (t[p] == t[p - 1]) + (t[p] == t[p + 1]);
    t[p] = c;
    cout << ret << '\n';
  }

  return 0;
}
