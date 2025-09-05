#include <bits/stdc++.h>
using namespace std;
int f[105][105];
int a[105][105];
int n, m;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};

int dfs(int x, int y) {
    if (f[x][y]) return f[x][y]; // 返回已知
    for (int i = 0; i < 4; ++i) { // 四个方向
        int nx = x + dx[i], ny = y + dy[i];
        if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue; // 判断边界
        if (a[nx][ny] < a[x][y]) { // 能不能滑
            f[x][y] = max(f[x][y], dfs(nx, ny) + 1);
        }
    }
    if (f[x][y]) return f[x][y]; // 返回更新完的值
    return 1; // 如果f[x][y] 没更新，代表周围都比他高
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}