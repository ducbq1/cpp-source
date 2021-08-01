#include <bits/stdc++.h>

using namespace std;

int m, n, cost = 0, minCost = INT_MAX, cmin = INT_MAX, vt[20] = {};
int c[20][20] = {};
bool v[20] = { false };


void tsp(int k) {
  for (int i = 1; i < n; i++) {
    if (v[i] == false) {
      if (c[vt[k - 1]][i] != 0) {
        vt[k] = i;
        v[i] = true;
        cost += c[vt[k - 1]][i];
        if (cost + cmin * (n - k + 1) <= minCost) {
          if (k == n - 1) {
            if (c[i][0] != 0) {
              minCost = min(minCost, cost + c[i][0]);
            }
          } else {
            tsp(k + 1);
          }
        }

        v[i] = false;
        cost -= c[vt[k - 1]][i];
      }
    }
  }
}


int main() {

  
  cin >> n >> m;
  int temp1, temp2, temp3;
  for (int i = 0; i < m; i++) {
    cin >> temp1 >> temp2 >> temp3;
    c[temp1 - 1][temp2 - 1] = temp3;
    cmin = min(cmin, temp3);
  }

  v[0] = true;
  tsp(1);

  cout << minCost << '\n';
  
  return 0;
}
