#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[105][105][105];
ll a[105][105];
bool vis[105][105][105];
int n, k;

ll dfs(int x, int y, int cnt) {
    if (x > n || y > n) return 0;
    if (vis[x][y][cnt]) return f[x][y][cnt];
    if (cnt < k) {
        f[x][y][cnt] = max(f[x][y][cnt], dfs(x + 1, y, cnt + 1) + a[x][y] * 3);
        f[x][y][cnt] = max(f[x][y][cnt], dfs(x + 1, y + 1, cnt + 1) + a[x][y] * 3);
    }
    f[x][y][cnt] = max(f[x][y][cnt], dfs(x + 1, y, cnt) + a[x][y]);
    f[x][y][cnt] = max(f[x][y][cnt], dfs(x + 1, y + 1, cnt) + a[x][y]);
    vis[x][y][cnt] = 1;
    return f[x][y][cnt];
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) cin >> a[i][j];
    }
    memset(f, -0x3f, sizeof(f));
    ll ans = dfs(1, 1, 0);
    cout << ans << endl;
    return 0;
}