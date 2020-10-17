#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int head, int tail) {
  while (head < tail) {
    int temp = arr[head];
    arr[head] = arr[tail];
    arr[tail] = temp;
    head++;
    tail--;
  }
}

void reverseRecursive(int arr[], int start, int end) {
  if (start >= end) {
    return;
  }
  int temp = arr[start];
  arr[start] = arr[end];
  arr[end] = temp;
  reverseRecursive(arr, start + 1, end - 1);
}
