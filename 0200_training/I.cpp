#include <bits/stdc++.h>

using namespace std;

int check(char a, char b) {
  return ((a == '[') && b == ']') || ((a == '(') && (b == ')'));
}

int main() {
  string sequence;
  cin >> sequence;

  stack<char> st;
  int counting = 0;

  for (int i = 0; i < sequence.length(); i++) {
    if (sequence[i] == '(' || sequence[i] == '[') {
      st.push(sequence[i]);
    } else if (sequence[i] == ')') {
      if (!st.empty() && check(st.top(), sequence[i])) {
        st.pop();
      } 
    } else if (sequence[i] == ']') {
      if (!st.empty() && check(st.top(), sequence[i])) {
        st.pop();
        counting++;
      } 
    } 
  }

  if (st.empty()) {
    cout << counting << '\n';
    cout << sequence << '\n';
  } else {
    cout << 0;
  }

  return 0;
}
