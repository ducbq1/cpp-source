#include <bits/stdc++.h>

using namespace std;

int n, mydistance[23][23] = {}, k, mycount = 0, summin = INT_MAX, sum = 0, distanceMin = INT_MAX;
int check[11] = {};

void process(int i, int k) {
  if (mycount == 2 * n) {
    summin = min(summin, sum + mydistance[i][0]);
    return;
  }

  for (int v = 1; v <= n; v++) {
  if (check[v] == 0 && k > 0 && (sum + mydistance[i][v] + distanceMin * (2 * n - mycount - 1) < summin)) {
    check[v] = 1;
    mycount++;
    sum += mydistance[i][v];
    process(v, k - 1);
    check[v] = 0;
    mycount--;
    sum -= mydistance[i][v];
  } else if (check[v] == 1 && (sum + mydistance[i][v + n] + distanceMin * (2 * n - mycount - 1) < summin)) {
    check[v] = 2;
    sum += mydistance[i][v + n];
    mycount++;
    process(v + n, k + 1);
    check[v] = 1;
    sum -= mydistance[i][v + n];
    mycount--;
  }
  

  }
}


int main() {
  cin >> n >> k;
  for (int i = 0; i < 2 * n + 1; i++) {
    for (int j = 0; j < 2 * n + 1; j++) {
      cin >> mydistance[i][j];
      if (i != j) {
        distanceMin = min(distanceMin, mydistance[i][j]);
      }
    }
  }
  process(0, k);
  cout << summin;
  return 0;
}
