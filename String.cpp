#include <bits/stdc++.h>
using namespace std;

int main() {
	string myString, newString = "", tempString = "";
	getline(cin, myString);
	// size_t pos = myString.find(" ");
	int i = 0;
	char mySpace = myString[i];
	while (mySpace == ' ') {
		// newString = newString.push_back(' ');
		// newString += " ";
		// newString = newString.append(" ");
		newString.append(" "); // + also true
		mySpace = myString[++i];
	}
	while (1) {
		if (mySpace != ' ') {
			tempString += mySpace;
			mySpace = myString[++i];
		} else {
			
		}
	}
	cout << "Helo";
	cout << newString.append("TEST");
	return 0;
}