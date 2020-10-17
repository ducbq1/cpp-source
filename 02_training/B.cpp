#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> positive;
vector<pair<int, int>> negative;

long long int delivery(int k, vector<pair<int, int>> a) {
  if (a.size() == 0) {
    return 0;
  }

  long long int sum = 0;
  int last = a.size() - 1;

  while (last >= 0) {

    int done = 1, quantity = k, times, check = a[last].second;
    if (check % k == 0) {
      times = check / k;
      done = 0;
    } else {
      times = check / k + 1;
      quantity = k - check % k;
    }

    sum += (long long int) a[last].first * times * 2;
    last--;

    while (done == 1 && last >= 0) {
      int temp = a[last].second;
      if (temp < quantity) {
        quantity -= temp;
        last--;
      } else if (temp == quantity) {
        last--;
        done = 0;
      } else {
        a[last].second -= quantity;
        done = 0;
      }

      if (last < 0) {
        break;
      }
    }
  }
  return sum;
}



int main() {

  int n, k, x, m;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x >> m;
    if (x > 0) {
      positive.push_back(make_pair(x, m));
    } else {
      negative.push_back(make_pair(abs(x), m));
    }

    if (negative.size() > 0) {
      sort(negative.begin(), negative.end(), 
          [](pair<int, int> a, pair<int, int> b) {
          return a.first < b.first;
          });
    }

    if (positive.size() > 0) {
      sort(positive.begin(), positive.end(),
          [](pair<int, int> a, pair<int, int> b) {
          return a.first < b.first;
          });
    }

  }

  cout << delivery(k, positive) + delivery(k, negative) << '\n';

  return 0;
}
