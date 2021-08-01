#include <bits/stdc++.h>

using namespace std;

int main() {

  int test;
  cin >> test;
  for (int i = 0; i < test; i++) {
    int m, n;
    cin >> m >> n;
  
    bool imageOne[m][n], imageTwo[m][n];

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> imageOne[i][j];
      } 
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> imageTwo[i][j];
      }
    }
  
    int count;
    vector<pair<int, int>> temp;

    /* for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (imageOne[i][j] == 1) {
          for (int k = 0; k < m; k++) {
            for (int h = 0; h < n; h++) {
              if (imageTwo[k][h] == 1) {
                temp.push_back(make_pair(i - k, j - h));
              }
            }
          }
        }

      }

    } */

    vector<pair<int, int>> temp1;
    vector<pair<int, int>> temp2;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (imageOne[i][j]) {
          temp1.push_back(make_pair(i, j));
        }
        if (imageTwo[i][j]) {
          temp2.push_back(make_pair(i, j));
        }
      }
    }

    for (int i = 0; i < temp1.size(); i++) {
      for (int j = 0; j < temp2.size(); j++) {
        temp.push_back(make_pair(temp1.at(i).first - temp2.at(j).first,
                                 temp1.at(i).second - temp2.at(j).second));
      }
    }


    sort(temp.begin(), temp.end());

     // for (auto i : temp) {
    //   cout << i.first << ' ' << i.second << '\n';
    // }

    int ret = 1;
    int maxPing = 0;

    for (int i = 1; i < temp.size(); i++) {
      if (temp.at(i) == temp.at(i - 1)) {
        ret++;
        maxPing = max(maxPing, ret);
      } else {
        ret = 1;
      }
    }

    cout << maxPing << '\n';
    cout << temp1.size() << endl;
    cout << temp2.size() << endl;

  }

  
  return 0;
}
