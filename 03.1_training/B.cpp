#include <bits/stdc++.h>

using namespace std;

void permutation(int left, int right, int n) {

  int i;
  for (i = left; i <= right; i++) {
    cout << i << ' ';
    if (right == n) {
      return;
    } else {
      left++;
      permutation(left, right + 1, n);
      left--;
    }
    
  }

}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  permutation(1, 1, n);

  return 0;


}
