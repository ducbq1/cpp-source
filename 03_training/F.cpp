#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

int calc(int a[], int n, int** elementDistance) {
  int returnValue = 0;
  for (int i = 0; i < n; i++) {
    returnValue += elementDistance[a[i]][a[i] + n];
  }
  for (int i = 0; i < n - 1; i++) {
    returnValue += elementDistance[a[i] + n][a[i + 1]];
  }
  return returnValue + elementDistance[0][a[0]] + elementDistance[a[n - 1] + n][0];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, cost;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  int m = 2 * n + 1;
  int** elementDistance;
  elementDistance = new int* [m];
  for (int i = 0; i < m; i++) {
    elementDistance[i] = new int[m];
    for (int j = 0; j < m; j++) {
      cin >> elementDistance[i][j];
    }
  }
  int answer = INT_MAX;
  while (next_permutation(a, a + n)) {
    cost = calc(a, n, elementDistance);
    answer = min(answer, cost);
  }
  cout << answer;
  return 0;
}
