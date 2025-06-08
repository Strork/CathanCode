#include <bits/stdc++.h>
using namespace std;
bool f[105][105];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n, m;
int ans;
struct node {
    int x, y;
    char ch;
}a[105][105];

void bfs(int x, int y) {
    queue<node> q;
    q.push(a[x][y]);
    while (!q.empty()) {
        node id = q.front();
        q.pop();
        f[id.x][id.y] = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = id.x + dx[i];
            int ny = id.y + dy[i];
            if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
            if (!f[nx][ny]) q.push(a[nx][ny]);
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j].ch;
            if (a[i][j].ch == '0') f[i][j] = 1;
            a[i][j].x = i;
            a[i][j].y = j;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!f[i][j]) {
                bfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
