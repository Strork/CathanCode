#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[2005][2005];
bool f[2005][2005];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
    f[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx <= 0 || ny <= 0 || nx > m || ny > n) continue;
        if (f[nx][ny] || a[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    dfs(1, 1);
    if (f[m][n]) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}
