#include <bits/stdc++.h>
using namespace std;

int ucln_method_one(int m, int n) {
    if (n == 0) return m;
    else return ucln_method_one(n, m % n);
}

int ucln_method_two(int m, int n) {
    while (n != 0) {
        int temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}

int main() {
    cout << ucln_method_one(12, 15) << '\n';
    cout << ucln_method_two(15, 12) << '\n';
    return 0;
}