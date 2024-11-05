#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[10002];
bool f[10002], vis[10002];
int ans = 0;

void dfs(int x) {
    vis[x] = 1;
    for (auto i : a[x]) {
        if (vis[i]) ++ans;
        else {
            dfs(i);
            
        }
    }
}

int main() {
    scanf("%d &d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i);
        f[i] = 1;
    }
    return 0;
}