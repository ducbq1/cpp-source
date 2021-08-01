#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100];

void combination_list(int k) {
  for (int i = arr[k - 1] + 1; i <= n - m + k; i++) {
    arr[k] = i;
    if (k == m) {
      for (int i = 1; i <= m; i++) {
        cout << arr[i] << ' ';
      }
      cout << '\n';
    } else { combination_list(k + 1); }
   
  }
    
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  arr[0] = 0;
  combination_list(1);

  return 0;
}
