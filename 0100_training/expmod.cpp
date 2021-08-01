#include <bits/stdc++.h>
using namespace std;

long long int expmod(string a, string b, long long int mod) {
    
    long long int remainder_b = 0;
    long long int remainder_a = 0;

    // b % (mod - 1)
    for (long long int i = 0; i < b.length(); i++) {
        remainder_b = (remainder_b * 10 + (b[i] - '0')) % (mod - 1);
    }

    // a % mod
    for (long long int i = 0; i < a.length(); i++) {
        remainder_a = (remainder_a * 10 + (a[i] - '0')) % mod;
    }

    long long int temp = 1;

    for (long long int i = 0; i < remainder_b; i++) {
        temp = (temp * remainder_a) % mod;
    }

    return temp;
}


int main() {
    long long int mod = 1000000007;
    string a, b;
    cin >> a >> b;
    cout << expmod(a, b, mod);
    return 0;
}