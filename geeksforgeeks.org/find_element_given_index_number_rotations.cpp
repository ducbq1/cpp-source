// cpp code to rotate an array and answer the index query
#include <bits/stdc++.h>
using namespace std;

// function to compute the element at given index
int findElement(int arr[], int ranges[][2], int rotation, int index) {
  
  for (int i = rotation - 1; i >= 0; i--) {

    int left = ranges[i][0];
    int right = ranges[i][1];

    // rotation will not have any effect
    if (left <= index && right >= index) {
      
      if (index == left)
        index = right;
      else
        index--;
    }
  }

  return arr[index];
}

// driver
int main() {
  
  int arr[] = {1, 2, 3, 4, 5};
  int rotations = 2;
  int ranges[rotations][2] = { {0, 2}, {0, 3} };
  int index = 1;

  cout << findElement(arr, ranges, rotations, index);
  return 0;
}
