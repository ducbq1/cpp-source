#include <bits/stdc++.h>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int lo = 0, hi = n - 1;
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        if (lo == hi) {
            if (arr[lo] == x) return lo;
            return -1;
        }

        int pos = lo + (double)(hi - lo) / (arr[hi] - arr[lo]) * (x - arr[lo]);

        if (arr[pos] == x) return pos;
        if (arr[pos] < x) lo = pos + 1;
        else hi = pos - 1;
    }
    return -1;
}


int main() {

  int arr[] = { 53, 45, 6, 7, 2, 234, 543, 565 ,764523, 3, 3, 2, 3254 };
  int n = sizeof(arr) / sizeof(arr[0]);
  sort(arr, arr + n);
  cout << interpolationSearch(arr, n, 565) << '\n';
  return 0;
}
