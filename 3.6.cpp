#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b) {
        while (a != b) {
            if (a > b) 
                a -= b;
            else 
                b -= a;
        }
        return a;
}

// int gcd3(int a, int b) {
//     int tmp;
//     while (b != 0) {
//         tmp = a % b;
//         a = b;
//         b = tmp;
//     }
//     return a;
// }

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return EXIT_SUCCESS;
}