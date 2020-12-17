#include <bits/stdc++.h>
using namespace std;

int part(int m, int n) {
    if (m == 0) return 1;
    else if (n == 0) return 0;
    else if (m < n) return part(m, m);
    else return part(m, n - 1) + part(m - n, n);
}

int main() {
    // cout << part(34, 3) << " ";
    int a, b;
    cin >> a >> b;
    cout << part(a, b) << endl;
    return 0;
}
