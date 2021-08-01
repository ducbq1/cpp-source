#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	
	int n, b;
	cin >> n >> b;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int maxPrefix[n], maxSuffix[n];
 	// for (int i = 0; i < n; i++) {
	// 	maxPrefix[i + 1] = max(maxPrefix[i], a[i + 1]);
	// 	maxSuffix[n - i - 2] = max(a[n - i - 2], maxSuffix[n - i - 1]);
	// }
  //
  maxPrefix[0] = 0;
  for (int i = 1; i < n; i++) {
    maxPrefix[i] = max(maxPrefix[i - 1], a[i - 1]);
  }

  maxSuffix[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    maxSuffix[i] = max(maxSuffix[i + 1], a[i + 1]);
  }

	
	int maxTest = 0;
	
	// for (int i = 1; i < n - 1; i++) {
	// 	if (maxPrefix[i - 1] - a[i] >= b && maxSuffix[i + 1] - a[i] >= b) {
	// 		maxTest = max(maxTest, maxPrefix[i - 1] + maxSuffix[i + 1] - a[i] - a[i]);
	// 	}
	// }
  //
  for (int i = 0; i < n; i++) {
    if (maxPrefix[i] - a[i] >= b && maxSuffix[i] - a[i] >= b) {
      maxTest = max(maxTest, maxPrefix[i] + maxSuffix[i] - a[i] - a[i]);
    }
  }
	
	if (maxTest == 0) cout << -1;
	else cout << maxTest;
	return 0;
 
}
