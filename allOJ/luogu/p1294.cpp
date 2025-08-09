#include <bits/stdc++.h>
using namespace std;
bool vis[25];
int a[25][25];
int n, m;
int ans;

void dfs(int x, int sum) {
    if (sum > ans) ans = sum; // 记录最长的路
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(i, sum + a[x][i]);
            vis[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        cin >> a[x][y];
        a[y][x] = a[x][y];
    }
    for (int i = 1; i <= n; ++i) {
        vis[i] = 1;
        dfs(i, 0);
        vis[i] = 0;
    }
    cout << ans << endl;
    return 0;
}