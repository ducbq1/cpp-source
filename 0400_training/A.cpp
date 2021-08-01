#include <bits/stdc++.h>

using namespace std;

float max_pie(int radiiPie[], int myPie, int myFriend) {
  float maxPie = 0.0;
  if (myPie != 0) {
    for (int j = 0; j < myFriend; j++) {
      float temp = radiiPie[myPie - 0] * radiiPie[myPie - 1] * M_PI / (j + 1);
      maxPie = max(maxPie, temp);
      maxPie = max(maxPie, max_pie(radiiPie, myPie - 1, myFriend - j - 1));
    }
  }
  return maxPie;
}


int main() {
  int testCase;
  cin >> testCase;
  for (int i = 0; i < testCase; i++) {
    int myPie, myFriend;
    cin >> myPie >> myFriend;
    int radiiPie[myPie];
    for (int i = 0; i < myPie; i++) {
      cin >> radiiPie[i];
    }
    cout << max_pie(radiiPie, myPie, myFriend);
  }
  return 0;
}
