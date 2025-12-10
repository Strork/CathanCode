#include <bits/stdc++.h>
using namespace std;
int n;
int p[5][14];
int a[55];


void dfs(int x, int cnt) {
    if (cnt >= ans) return; // 最优化剪枝
    if (x >= n + 1) {
        if (check()) ans = cnt;
        return;
    }
    for (int i = 0; i < 4; ++i) {

    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; char b; cin >> x >> b;
        if (isdigit(b)) {
            p[x][b - '0'] = 1;
            a[i] = (x - 1) * 13 + b - '0';
        }
        else if (b == 'A') p[x][1] = 1, a[i] = (x - 1) * 13 + 1;
        else if (b == 'J') p[x][11] = 1, a[i] = (x - 1) * 13 + 11;
        else if (b == 'Q') p[x][12] = 1, a[i] = (x - 1) * 13 + 12;
        else if (b == 'K') p[x][13] = 1, a[i] = (x - 1) * 13 + 13;
    }
    dfs(1);
    return 0;
}