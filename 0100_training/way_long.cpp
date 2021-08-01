#include <bits/stdc++.h>
using namespace std;

// int main() {

//     int n;
//     cin >> n;

//     string a[n];

//     for (int i = 0; i < n; i++) {
//         // getline(cin, a[i], '\n');
//         cin >> a[i];
//     }

//     for (int i = 0; i < n; i++) {

//         int sum = a[i].length() - 2;
//         if (sum >= 10) {
//             a[i] = a[i].at(0) + to_string(sum) + a[i].at(sum + 1);
//             // cout << a[i][0] << sum << a[i][sum + 1] << '\n';
//             cout << a[i] << '\n';
//         } else {
//             cout << a[i] << '\n';
//         }
//     }

//     return 0;
// }

int main() {

    int n;
    cin >> n;
    string a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        int length = a.length();
        if (length > 10) {
            cout << a[0] << length - 2 << a[length - 1] << '\n';
        } else {
            cout << a << '\n';
        }
    }

    return 0;
}