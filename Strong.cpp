#include <bits/stdc++.h>
using namespace std;

int main() {
	int i = 0;
	string myString, newString = "", tempString = "";
	vector<string> tempVector;
	getline(cin, myString);
	
	char mySpace = myString[i];
	while (mySpace == ' ') {
		newString += " ";
		mySpace = myString[++i];
	}

	while (mySpace != '\0') {
		if (mySpace != ' ') {
			tempString += mySpace;
			mySpace = myString[++i];
		} else {
			tempVector.push_back(tempString);
			tempString = "";
			mySpace = myString[++i];
		}
	}
	tempVector.push_back(tempString);	

	for (auto j : tempVector)
		if (j != "") newString += " " + j;
	cout << newString.substr(1, newString.length());
	return 0;
}
		