#include <bits/stdc++.h>
using namespace std;

int main() {
    int* myArray;
    int n;
    cout << "Nhap vao n: ";
    cin >> n;
    myArray = new int[n];
    cout << "Nhap vao phan tu cua mang\n";
    for (int i = 0; i < n; i++) {
        cout << "myArray[" << i + 1 << "] = ";
        cin >> myArray[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = i; k <= j; k++)
                cout << myArray[k] << " ";
            cout << '\n';
        }
    }

    delete[] myArray;
    return 0;        
}