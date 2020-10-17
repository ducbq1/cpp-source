#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;



int main() {
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (1) {
    
    ull n;
    cin >> n;
    if (n == 0) {
      break;
    }

    ull a[n];

    for (ull i = 0; i < n; i++) {
      cin >> a[i];
    }


    stack<ull> st;
    ull max_area = 0;
    ull top_stack;
    ull top_area;
    ull i = 0;

    while (i < n) {
      if (st.empty() || a[st.top()] <= a[i]) {
        st.push(i++);
      } else {
        top_stack = st.top();
        st.pop();
        top_area = a[top_stack] * (st.empty() ? i : i - st.top() - 1);
        
        max_area = max(max_area, top_area);
      }
    }

    while (!st.empty()) {
      top_stack = st.top();
      st.pop();
      top_area = a[top_stack] * (st.empty() ? i : i - st.top() - 1);
      max_area = max(max_area, top_area); 
    }

    cout << max_area << '\n';
    
  }
  return 0;
}
