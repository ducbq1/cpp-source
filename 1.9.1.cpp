#include <iostream>
using namespace std;


int main() {
    int n;
    // cout << "Nhap vao so phan tu cua mang" << endl;
    cin >> n;
    // cout << "Nhap vao mang" << endl;
    int* M = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> *(M + i);
    }
    
    
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = i; k <= j; k++) {
                cout << *(M + k) << " ";
            }
            cout << '\n';
        }
    }

    return 0;

}