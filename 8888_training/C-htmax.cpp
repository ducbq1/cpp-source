#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, lengthSub = 0;
  cin >> n;
  int a[n], indexSub[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int include = a[0];
  int exclude = 0;
  int exclude_new;

  for (int i = 1; i < n; i++) {
    exclude_new = max(include, exclude);
    include = exclude + a[i];
    exclude = exclude_new;
  }

  cout << max(include, exclude);


  return 0;
}
