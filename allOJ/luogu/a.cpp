#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int> e[N];
bool vis[N];
int lk[N], n;

bool dfs(int x) {
    for (auto y : a[x]) {
        if (!vis[y] && (vis[y] = 1)) {
            if (!lk[y] || dfs(lk[y])) {
                lk[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(0));
        if (dfs(i)) ++ans;
    }
    return 0;
}