#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ans, sum;

void dfs(int x, int y) {
    a[x][y] = 0;
    ++sum;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
        if (!a[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 1) {
                sum = 0;
                dfs(i, j);
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}