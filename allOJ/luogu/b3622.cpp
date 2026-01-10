#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[520][520];
bool vis[520][520];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
    if (x == fx && y == fy) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1) continue;
        if (vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        dfs(nx, ny);
        vis[nx][ny] = 0;
    }
}

int main() {
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> c[i][j];
            if (c[i][j] == '*') vis[i][j] = 1;
        }
    }
    vis[0][0] = 1;
    dfs(0, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!vis[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}