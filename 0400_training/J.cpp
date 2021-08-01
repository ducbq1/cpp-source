#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
  vector<pair<int, int>> point;
  int n;
  cin >> n;
  while (n--) {
    float x, y;
    cin >> x >> y;
    point.push_back(make_pair(x, y));
    // cout << point[0].first << ' ' << point[0].second << endl;
  }
  
  // for (pair<int, int> i : point) {
    // cout << i.first;
  // }
  
  float maxValue = MAXFLOAT;
  for (int i = 0; i < point.size() - 1; i++) {
    for (int j = 1; j < point.size(); j++) {
      float maxReturn = sqrt((point[i].first - point[j].first) 
                           * (point[i].first - point[j].first) 
                           + (point[i].second - point[j].second)
                           * (point[i].second - point[j].second));
      cout << maxReturn;
      maxValue = min(maxValue, maxReturn);
    }
  }

  cout << maxValue;
  
  return 0;
}
