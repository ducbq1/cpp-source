#include <bits/stdc++.h>
using namespace std;

int main() {

    int m, n;

    cin >> m;
    int* a = new int[m + 1];
    for (int i = 0; i < m + 1; i++) cin >> *(a + i);
    cin >> n;
    int* b = new int[n + 1];
    for (int i = 0; i < n + 1; i++) cin >> *(b + i);

    int* c = new int[m + n + 1];
    if (c == nullptr) exit(1);
    for (int i = 0; i < m + n + 1; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
                c[i + j] += a[i] * b[j];
        }
    }

    int conclusion = 0;
    for (int i = 0; i < m + n + 1; i++) {
        conclusion ^= c[i];
    }

    cout << conclusion;
    return 0;
}