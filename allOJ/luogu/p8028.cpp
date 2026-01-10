#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int d1[N], d2[N], vis[N];
vector<int> a[N];
int n, m, d;

void dfs(int x, int fa) {
    d1[x] = d2[x] = 0;
    vis[x] = 1;
    for (auto y : a[x]) {
        if (y == fa) continue;
        dfs(y, x);
        int dis = d1[y] + 1;
        if (dis > d1[x])
            d2[x] = d1[x], d1[x] = dis;
        else if (dis > d2[x])
            d2[x] = dis;
    }
    d = max(d, d1[x] + d2[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            d = 0;
            dfs(i, i);
            ans += d + 1;
        }
    }
    cout << ans << endl;
    return 0;
}