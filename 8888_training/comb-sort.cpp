// #include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
using namespace std;

void comb_sort(int n, float arr[]) {
  int gap = n;
  bool sorted = false;

  while (sorted == false) {
    // gap = floor(gap / shrink);
    gap = gap * 10 / 13;
    if (gap <= 1) {
      gap = 1;
      sorted = true;
    }
    int i = 0; 
    while (i + gap < n) {
      if (arr[i] > arr[i + gap]) {
        swap(arr[i], arr[i + gap]);
        sorted = false;
      }
      i++;
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
