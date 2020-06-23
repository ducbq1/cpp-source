#include <bits/stdc++.h>
using namespace std;

int my_function_one(int m) {
    if (m < 2) return m;
    else return (m % 2) + my_function_one(m / 2) * 10;
}

void my_function_two(int m) {
    if (m > 0) {
        my_function_two(m / 2);
        cout << m % 2;
    }
}

void my_function_three(int m) {
    stack<int> myStack;
    while (m > 0) {
        int temp = m % 2;
        myStack.push(temp);
        m = m / 2;
    }
    while (!myStack.empty()) {
        cout << myStack.top();
        myStack.pop();
    }
}

int main() {
    cout << "Function 1: " << my_function_one(35) << '\n';
    cout << "Function 2: ";
    my_function_two(35); 
    cout << '\n';
    cout << "Function 3: ";
    my_function_three(35);
    cout << '\n';
    return 0;
}