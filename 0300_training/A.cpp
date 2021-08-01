#include <bits/stdc++.h>

using namespace std;

void tsp(int graph[][20], vector<bool>& v, int currentPosition, int n, int count, int cost, int& ans) {

  if (count == n && graph[currentPosition][0]) {
    ans = min(ans, cost + graph[currentPosition][0]);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!v[i] && graph[currentPosition][i]) {
      v[i] = 1;
      tsp(graph, v, i, n, count + 1, cost + graph[currentPosition][i], ans);
      v[i] = 0;
    }
  }
}

int main() {

  int n, m;
  cin >> n >> m;
  
  int graph[20][20];

  for (int i = 0; i < m; i++) {
    int temp1, temp2;
    cin >> temp1 >> temp2 >> graph[temp1][temp2];
  }

  vector<bool> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = 0;
  }

  v[0] = 1;
  int ans = INT_MAX;

  tsp(graph, v, 0, n, 1, 0, ans);

  cout << ans;

  return 0;
}
