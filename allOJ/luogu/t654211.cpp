#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, y;
};
queue<node> q;
int n, m;
bool vis[55][55];
int dis[55][55];
const int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

void bfs(int sx, int sy) {
    q.push({sx, sy});  // 起点入队，并标记
    vis[sx][sy] = 1;
    while (!q.empty()) {
        auto h = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = h.x + dx[i], ny = h.y + dy[i];  // 枚举下一个点
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (vis[nx][ny]) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
            dis[nx][ny] = dis[h.x][h.y] + 1;  // 记录路程长度
        }
    }
}

int main() {
    cin >> n >> m;  // 简化输入
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> vis[i][j];
    bfs(1, 1);
    cout << dis[n][m];
    return 0;
}