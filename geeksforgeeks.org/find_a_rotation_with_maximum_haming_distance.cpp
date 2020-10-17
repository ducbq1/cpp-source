#include <bits/stdc++.h>
using namespace std;

int maxHaming(int arr[], int n) 
{
  int brr[2 * n];
  for (int i = 0; i < n; i++)
    brr[i] = brr[i + n] = arr[i];
  
  int maxHam = 0; 

  for (int i = 1; i < n; i++)
  {
    int currHam = 0;
    for (int j = i, k = 0; j < i + n; j++, k++)
      if (brr[j] != brr[k])
        currHam++;

    if (currHam == n)
      return n;

    maxHam = max(maxHam, currHam);
  }

  return maxHam;
}

int main() {
  int arr[] = {2, 4, 6, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << maxHaming(arr, n);
  return 0;
}
