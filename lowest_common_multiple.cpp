#include <iostream>
using namespace std;

class gfg {
	public: 
		int gcd(int a, int b) {
			if (a == 0) return b;
			return gcd(b % a, a);
		}

		int lcm(int a, int b) {
			return (a * b) / gcd(a, b);
		}
};

int main() {
	gfg gTest;
	int a = 15, b = 20;
	cout << gTest.lcm(a, b);
	return 0;
}
