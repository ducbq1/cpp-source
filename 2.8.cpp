
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<vector<int>> a = {
        {1, 3, 7},
        {2, 3, 4, 5},
        {9, 8, 15},
        {10, 10}
    };

    sort(a.begin(), a.end(),
        [] (vector<int> &p, vector<int> &q) {
            int sump = 0, sumq = 0;
            for (int i = 0; i < p.size(); i++) {
                sump += p[i];
            }
            for (int i = 0; i < q.size(); i++) {
                sumq += q[i];
            }
            return sump > sumq;
        });

    for (const auto &v: a) {
        for (int it: v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}