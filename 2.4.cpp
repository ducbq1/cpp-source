#include <iostream>

using namespace std;

int cube(int x) {
    return x * x * x;
}

double cube(double x) {
    return x * x * x;
}

int main() {
    int n = 17;
    cout << "int: " << cube(n) << endl;
    cout << "double: " << cube(17.1) << endl;
}