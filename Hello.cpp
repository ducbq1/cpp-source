#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<string> myName;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string temp;
		getline(cin, temp);
		myName.push_back(temp);
	}
	// vi tri bat dau
	int position = 0;
	while (myName.size() > 0) {
		myName.erase(myName.begin() + (position + k) % n);
		position = (position + k) % n;
	}
	// cout << "Hello";
	cout << myName.front();
	return 0;
}