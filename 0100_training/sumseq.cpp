#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    unsigned int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    unsigned int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] % 1000000007;
        sum %= 1000000007;
    }

    cout << sum;
    return 0;
}