// test keyboard

#include <bits/extc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<bool> visited(n, 0);
  for (int i = 0; i < n; i++) {
    if (visited[i] == true)
      continue;
    int count = 1;
    for (int j = i + 1; j < n; j++) {
      if (arr[i] == arr[j]) {
        visited[j] = true;
        count++;
      }
    }
    cout << arr[i] << ' ' << count << endl;
  }
  return 0;
}
