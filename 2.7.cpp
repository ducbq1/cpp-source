#include <iostream>

using namespace std;

template <typename T> 
T arr_sum(T a[], int m, T b[], int n) {
    T s = 0;
        cout << sizeof(a) / sizeof(a[0]) << " " << sizeof(b) / sizeof(b[0]) << endl;
        for (int i = 0; i < m; i++) {
            s += a[i];
        }
        for (int i = 0; i < n; i++) {
            s += b[i];
        }
        return s;
}


int main() {
        
    {
    int a[] = {3, 2, 0, 5};
    int b[] = {5, 6, 1, 2, 7};
    cout << arr_sum<int>(a, 4, b, 5) << endl;
    }
    {
    double a[] = {3.0, 3, 0.7};
    double b[] = {5.4, 2, 2.3, 7};
    cout << arr_sum<double>(a, 3, b, 4);
    }
    return 0;
}