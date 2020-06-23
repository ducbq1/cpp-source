#include <bits/stdc++.h>

int n, X[100], Y[100], mark[100][100];
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void my_process(int i, int x, int y) {
    
    if (i > n * n) {
        for (int j = 0; j < i; ++j)
            printf("(%d %d)\n", X[j], Y[j]);
        exit(0);
    }
    
   
    for (int h = 0; h < 8; h++) {
        
        int xx = x + hx[h], yy = y + hy[h];
        if (xx <= n && yy <= n && !mark[xx][yy]) {
            if (xx < 0 || yy < 0) break;
            mark[xx][yy] = 1;
            X[i] = xx, Y[i] = yy;
            my_process(i + 1, xx, yy);
            mark[xx][yy] = 0;
        }
    }
}

int main() {
    n = 8;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    my_process(2, 1, 1);
    return 0;
}