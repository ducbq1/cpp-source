#include <bits/stdc++.h>

using namespace std;

int n;
bool check[100] = {};
int arr[100];

void my_try(int k) {
  
  for (int i = 1; i <= n; i++) {
    if (!check[i]) {
      arr[k] = i;
      check[i] = true;
      if (k == n - 1) {
        for (int i = 0; i < n; i++) {
          cout << arr[i] << ' ';
        }
        cout << '\n';
      } else {
        my_try(k + 1);
      }
      check[i] = false; // backtrack
    }
  }
}

int main() {

  cin >> n;

  my_try(0);

  return 0;
}
