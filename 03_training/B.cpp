#include <bits/stdc++.h>

using namespace std;
int n, b, gt = 0, kl = 0, maxItem = 0;
int a[30], c[30];

void process(int k) {
  for (int i = k; i < n; i++) {
    if (kl + a[i] <= b) {
      kl += a[i];
      gt += c[i];
      maxItem = max(maxItem, gt);
      process(i + 1);
      kl -= a[i];
      gt -= c[i];
    }
  }
}


int main() {

  // freopen("in.txt", "r", stdin);
  cin >> n >> b;

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> c[i];
  }

  process(0);
  cout << maxItem << endl;

  return 0;
}
