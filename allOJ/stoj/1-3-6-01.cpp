#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, t, fx, fy, sx, sy;
bool vis[10][10], obs[10][10];
int cnt;

void dfs(int x, int y) {
    if (x == fx && y == fy) {
        cnt++;
        return;
    }
    //if (vis[x][y] || obs[x][y] || x<=0 || x >n || y<=0||y>m) return;
    // vis[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (vis[x][y] || obs[x][y] || x<=0 || x >n || y<=0||y>m) continue;
        vis[nx][ny] = 1;
        dfs(nx, ny);
        vis[nx][ny] = 0;
    }
}

int main() {
    cin >> n >>m >>t;
    cin >> sx>>sy>>fx>>fy;
    for (int i = 1; i <= t; ++i) {
        int a,b;
        cin >>a>>b;
        obs[a][b] = 1;
    }
    vis[sx][sy] = 1;
    dfs(sx, sy);
    cout <<cnt<<endl;
    return 0;
}