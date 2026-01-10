#include <bits/stdc++.h>
using namespace std;
int n, m, obs_num;
int st, ed, fx, fy;
bool vis[10][10];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans;

void dfs(int x, int y) {
    if (x == fx && y == fy) {
        ++ans;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if (!vis[nx][ny]) {
            vis[nx][ny] = 1;
            dfs(nx, ny);
            vis[nx][ny] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> obs_num;
    cin >> st >> ed >> fx >> fy;
    for (int i = 1; i <= obs_num; ++i) {
        int x, y;
        cin >> x >> y;
        vis[x][y] = 1;
    }
    vis[st][ed] = 1;
    dfs(st, ed);
    cout << ans << endl;
    return 0;
}