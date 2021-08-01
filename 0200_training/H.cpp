#include <bits/stdc++.h>

using namespace std;

bool checkPair(char x, char y) {
  map<char, char> my_parentheses;
  my_parentheses.insert(make_pair('(', ')'));
  my_parentheses.insert(make_pair('{', '}'));
  my_parentheses.insert(make_pair('[', ']'));
  return my_parentheses[x] == y;
}

bool balanced(string exp) {
  stack<char> st;
  for (int i = 0; i < exp.size(); i++) {
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
      st.push(exp[i]);
    } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
      if (!st.empty() && checkPair(st.top(), exp[i])) {
        st.pop();
      } else {
        return false;
      }
    }
  }
  return st.empty();
}

int main() {
  
  int n;
  cin >> n;

  string temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    cout << balanced(temp) << '\n';
  }

  return 0;
}
