#include <bits/stdc++.h>

using namespace std;

int main() {
  
  int n; 
  cin >> n;
   
  string location = "";

  string input;
  cin.ignore();

  for (int i = 0; i < n; i++) {
  
    getline(cin, input);
    cout << input << endl;

    /* if (input.compare("pwd")) {
      location = location == "" ? "/" : location;
      cout << location << '\n';
    } else if (input.find("cd" != 0)) {
      input = input.substr(2);
      cout << input;
      while (!input.empty()) {
        if (input[0] == '/') {
          location.push_back(input[0]);
          cout << location;
          input = input.substr(1);
        } else if (input.find("..") != 0) {
          input = input.substr(1); 
        }
      }
    } */
  }

  return 0;
}
