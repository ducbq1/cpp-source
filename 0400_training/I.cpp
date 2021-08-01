#include <bits/stdc++.h>

using namespace std;

int find_three_number(int arr[], int arrSize, int sum) {
  int left, right, count = 0;
  sort(arr, arr + arrSize); 
  for (int i = 0; i < arrSize - 2; i++) {
    left = i + 1;
    right = arrSize - 1;
    while (left < right) {
      if (arr[i] + arr[left] + arr[right] == sum) {
        count++;
        left++;
        right--;
      } else if (arr[i] + arr[left] + arr[right] < sum) {
        left++;
      } else {
        right--;
      }
    }
  }
  return count;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << find_three_number(arr, n, k);
  return 0;
}
