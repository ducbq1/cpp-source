#include <bits/stdc++.h>

using namespace std;

int main() {
  while (1) {
    int n; 
    cin >> n;
    if (n == 0) {
      break;
    }

    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int ret = 0, update = 0;
    
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) continue;
      update = a[i];
      ret = max(ret, 1 * update);
      for (int j = i; j < n; j++) {
        if (a[j] == 0) break;
        update = min(update, a[j]);
        ret = max(ret, (j - i + 1) * update);
      }
    }

    cout << ret << '\n';
  }
  return 0;
}
