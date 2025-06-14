#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int n, m;
char a[105][105];
int ans;
bool vis[105][105];
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
        if (!vis[nx][ny]) dfs(nx, ny);
    }
}

void bfs(int sx, int sy) {
    queue<pii> q;
    q.push(make_pair(sx, sy));
    vis[sx][sy] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if (!vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
        q.pop();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '.') vis[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!vis[i][j]) {
                // dfs(i, j);
                bfs(i, j);
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}