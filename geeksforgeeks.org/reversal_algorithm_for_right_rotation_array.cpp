#include <bits/stdc++.h>
using namespace std;

void reversalArray(int arr[], int start, int end)
{
  while (start < end) 
  {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

void rightRotate(int arr[], int d, int n)
{
  reversalArray(arr, 0, n - 1);
  reversalArray(arr, 0, d - 1);
  reversalArray(arr, d, n - 1);
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << ' ';
}
