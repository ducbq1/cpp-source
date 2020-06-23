#include <iostream>
using namespace std;

int n, c[100][100];
int x[100], best, curcost, visit[100] = {};
int cmin;


// tim min
void init () {
    x[1] = 1;
    visit[1] = 1;
    cmin = c[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (c[i][j] < cmin)
                cmin = c[i][j];
        }
}

void print() {
    cout << best;
}

void process(int i) {
    for (int j = 2; j <= n; i++) {
        if (!visit[i]) {
            x[i] = j;
            curcost += c[x[i-1]][j];
            if (i == n) {
                if (best > curcost + c[j][1])
                    best = curcost + c[j][1];
            } else if (curcost + (n - i + 1) * cmin < best)
                process(i + 1);
            curcost -= c[x[i-1]][j];
            visit[j] = 0;
        }
    }
}

int main() {
    while (n < 1 || n > 16) {
        cout << "Nhap n: ";
        cin >> n;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];
    init();
    process(2);
    print();
    return 0;
}