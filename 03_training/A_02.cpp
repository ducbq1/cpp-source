#include <bits/stdc++.h>

using namespace std;

int n, m;
int temp1, temp2, temp3, graph[20][20] = {};
int cmin = INT_MAX;
int visit[20] = {};
int x[20];
int best, currentCost;


void tsp(int k) {
  for (int i = 2; i <= n; i++) {
    if (!visit[k]) {
      x[k] = i;
      visit[k] = true;
      currentCost += graph[x[k - 1]][i];
      if (i == n) {
        best = min(best, currentCost + graph[i][1]);
      } else if (currentCost + (n - k + 1) * cmin < best) {
        tsp(k + 1);
      }

      currentCost -= graph[x[k - 1]][i];
      visit[i] = 0;
    }
  }
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

 
  for (int i = 0; i < m; i++) {
    cin >> temp1 >> temp2 >> temp3;
    graph[temp1 - 1][temp2 - 1] = temp3;
    cmin = min(cmin, temp3);
  }

  x[1] = 1;
  visit[0] = true;
  tsp(1);
  cout << best << '\n';
    
  return 0;
}
