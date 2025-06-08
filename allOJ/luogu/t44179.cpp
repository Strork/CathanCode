#include <bits/stdc++.h>
using namespace std;
bool vis[105][105];
int oldColor, newColor;
int a[105][105];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m;

void dfs(int x, int y) {
    a[x][y] = newColor;
    vis[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx > n || ny > m || nx <= 0 || ny <= 0) continue;
        if (!vis[nx][ny] && a[nx][ny] == oldColor) dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    int sx, sy;
    cin >> sx >> sy >> newColor;
    oldColor = a[sx][sy];
    dfs(sx, sy);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}