
#include <bits/stdc++.h>
using namespace std;
bool vis[1005];
int cnt[1005];
vector<int> a[1005];
vector<int> cow;
int n, k, m;

void dfs(int x) {
    vis[x] = 1;
    cnt[x]++;
    for (auto y : a[x]) {
        if (!vis[y]) dfs(y);
    }
}

int main() {
    cin >> k >> n >> m;
    for (int i = 1; i <= k; ++i) {
        int x;
        cin >> x;
        cow.push_back(x);
    }
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    for (auto x : cow) {
        memset(vis, 0, sizeof(vis));
        dfs(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (cnt[i] == k) ++ans;
    cout << ans << endl;
    return 0;
}