#include <bits/stdc++.h>
using namespace std;
int n, m;
bool a[1005][1005];
bool f[1005];
int ans;

void dfs(int x) {
    f[x] = 1;
    if (x > ans) ans = x;
    for (int i = 1; i <= n; ++i) {
        if (a[x][i] && !f[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        memset(f, 0, sizeof(f));
        ans = 0;
        dfs(i);
        cout << ans << ' ';
    }
    return 0;
}