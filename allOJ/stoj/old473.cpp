#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105][105];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
struct node {
    int x, y;
};

void bfs(node st) {
    queue<node> q;
    q.push(st);
    while (!q.empty()) {
        node t = q.front();
        a[t.x][t.y] = 0;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (a[nx][ny] == 1) q.push({nx, ny});
        }
    }
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
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 1) {
                node t = {i, j};
                bfs(t);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}