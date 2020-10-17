// cpp program to find a pair with a given sum in a sorted and rotated array
#include <iostream>
using namespace std;

bool pairSortedRotated(int arr[], int n, int x) {

  // find the pivot element
  int i;
  for (i = 0; i < n - 1; i++)
    if (arr[i] > arr[i + 1])
      break;
  int l = (i + 1) % n;
  int r = i;

  while (l != r) {
    
    // if we find a pair with sum x, we return true
    if (arr[l] + arr[r] == x)
      return true;
    else if (arr[l] + arr[r] < x)
      l = (l + 1) % n;
    else
      r = (n + r - 1) % n;
  }
  return false;
}

int main() {

  int arr[] = { 11, 15, 6, 8, 9, 10 };
  int sum = 16;
  int n = sizeof(arr) / sizeof(arr[0]);

  if (pairSortedRotated(arr, n, sum))
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
  return 0;
}

int pairsInSortedRotated(int arr[], int n, int x) {

  // find the pivot element. Pivot element
  // is largest element of array
  int i;
  for (i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1])
      break;
  }
  
  // l is index of smallest element
  int l = (i + 1) % n;

  // r is index of largest element
  int r = i;

  int cnt = 0;

  while (l != r) {

    if (arr[l] + arr[r] == x) {
      
      cnt++;

      if (l === (r - 1 + n) % n) return cnt;

      l = (l + 1) % n;
      r = (r - 1 + n) % n;
    
    } else if (arr[l] + arr[r] < x) {
      l = (l + 1) % n;
    } else { 
      r = (n + r - 1) % n;
  
    }
  }

  return cnt;
}
