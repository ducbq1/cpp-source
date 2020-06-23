#include <iostream>
#include <ostream>

using namespace std;

class Complex {
    public:    
        double real;
        double imag;
        Complex(double x, double y) {
            real = x;
            imag = y;
        }
};



Complex operator + (Complex a, Complex b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

Complex operator - (Complex a, Complex b) {
    return Complex(a.real - b.real, a.imag - b.imag);
}

Complex operator * (Complex a, Complex b) {
    return Complex(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real);
}

Complex operator / (Complex a, Complex b) {
    double temp = b.real * b.real - b.imag * b.imag;
    return Complex((a.real * b.real + a.imag * b.imag) / temp, (a.imag * b.real - a.real * b.imag) / temp);
}

ostream& operator << (ostream& out, const Complex &a) {
    cout << '(' << a.real << (a.imag >= 0 ? '+' : '-') << abs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    Complex a(-6, -3);
    Complex b(4, 6);
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    return 0;
}