#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int next_gap(int gap) {
  gap = gap * 10 / 13;
  if (gap < 1) {
    return 1;
  }
  return gap;
}

void comb_sort(int n, float arr[]) {
  int gap = n;
  // float shrink = 1.3;
  // bool sorted = false;
  bool swapped = true;
  
  while (gap != 1 || swapped == true) {
    gap = next_gap(gap);
    swapped = false;
    for (int i = 0; i < n - gap; i++) {
      if (arr[i] > arr[i + gap]) {
        swap(arr[i], arr[i + gap]);
        swapped = true;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  float arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  comb_sort(n, arr);
  for (int i = 0; i < n; i++) {
    cout << fixed << setprecision(2) << arr[i] << ' ';
  }
  return 0;
}
