#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, y;
};
int n, m;
char mp[105][50005];
bool f[105][50005];
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

void bfs(int sx, int sy) {
    queue<node> q;
    f[sx][sy] = 1;
    q.push({sx, sy});
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if (!f[nx][ny] && mp[nx][ny] == 'B')
                f[nx][ny] = 1, q.push({nx, ny});
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mp[i][j];
            if (mp[i][j] == '.') f[i][j] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        if (!f[n][i]) bfs(n, i), ans++;
    }
    cout << ans << endl;
    return 0;
}