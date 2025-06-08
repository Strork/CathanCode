#include <bits/stdc++.h>
using namespace std;
bool vis[505][505];
char ch[505][505];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int n, m;
struct oibh {
    int x, y;
}a[505][505];

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n+1; ++i) {
        for (int j = 0; j <= m+1; ++j) {
            a[i][j].x = i;
            a[i][j].y = j;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> ch[i][j];
            if (ch[i][j] == '*') vis[i][j] = 1;
        }
    }
    queue<oibh> q;
    vis[0][0] = 1;
    q.push(a[0][0]);
    while (!q.empty()) {
        oibh id = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = id.x + dx[i];
            int y = id.y + dy[i];
            if (x < 0 || y < 0 || x > n+1 || y > m+1) continue;
            if (!vis[x][y]) {
                vis[x][y] = 1;
                q.push(a[x][y]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!vis[i][j] && ch[i][j] == '0') ans++;
        }
    }
    cout << ans << endl;
    return 0;
}