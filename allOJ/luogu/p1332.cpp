#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int dis[505][505];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if (dis[nx][ny] <= dis[x][y]) continue;  // 最优化剪枝
        dis[nx][ny] = dis[x][y] + 1;
        dfs(nx, ny);
    }
}

int main() {
    // freopen("a.out", "w", stdout);
    cin >> n >> m >> a >> b;
    memset(dis, 10, sizeof(dis));  // 一开始给感染时间一个极大值
    for (int i = 1; i <= a; ++i) {
        int x, y;
        cin >> x >> y;
        dis[x][y] = 0;
        dfs(x, y);  // 从这个位置更新感染
    }
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) cout << dis[i][j] << ' ';
    //     cout << endl;
    // }
    for (int i = 1; i <= b; ++i) {
        int x, y;
        cin >> x >> y;
        cout << dis[x][y] << endl;
    }
    return 0;
}