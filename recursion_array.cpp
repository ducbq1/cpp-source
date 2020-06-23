#include <bits/stdc++.h>
using namespace std;

int my_function(int n) {
    if (n < 3) return n;
    else if (n % 3 == 0) return my_function(n - 1) * 2 - 1;
    else if (n % 3 == 1) return my_function(n - 1) * 2 + 1;
    else return my_function(n - 1) * 2;
}

int main() {

    cout << my_function(9);
    return 0;
}