#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, lengthArr = 0;
  vector<int> subArr;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (n == 1) {
    return arr[0];
  }

  int lookup[n];

  lookup[0] = arr[0];
  lookup[1] = max(arr[0], arr[1]);
  if (lookup[1] < lookup[0] + arr[2]) {
    subArr.push_back(1);
  }

  for (int i = 2; i < n; i++) {
    // lookup[i] = max(lookup[i - 1], lookup[i - 2] + arr[i]);
    if ((lookup[i - 2] + arr[i]) > lookup[i - 1]) {
      lookup[i] = lookup[i - 2] + arr[i];
      // subArr[0] = i - 1;
      subArr.push_back(i + 1);
    } else {
      lookup[i] = lookup[i - 1];
      // subArr.push_back(i);
      // lengthArr++;
    }
    // lookup[i] = max(lookup[i], arr[i]);
    if (arr[i] >= lookup[i]) {
      lookup[i] = arr[i];
      subArr.clear();
      // memset(subArr, 0, sizeof(subArr));
      // subArr[i - 2] = i + 1;
      // lengthArr++;
      subArr.push_back(i + 1);
    }
  }

  cout << lookup[n - 1] << endl;
  cout << subArr.size() << endl;
  for (auto u : subArr) {
    cout << u << ' ';
  }
  return 0;
}
