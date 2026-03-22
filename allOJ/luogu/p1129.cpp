#include <bits/stdc++.h>
using namespace std;
const int N = 405;
bool vis[N];
int lk[N], n, t;
vector<int> e[N];

inline void insert(int x, int y) { e[x].push_back(y), e[y].push_back(x); }

void init() {
    memset(lk, 0, sizeof(lk));
    cin >> n;
    for (int i = 1; i <= n; ++i) e[i].clear();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> t;
            if (t) insert(i, j + n);
        }
    }
}

bool dfs(int x) {
    vis[x] = 1;
    for (auto y : e[x]) {
        if (!vis[y] && (vis[y] = 1) && (!lk[y] || dfs(lk[y]))) {
            lk[y] = x;
            return true;
        }
    }
    return false;
}

void solution() {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) ++cnt;
    }
    if (cnt == n)
        puts("Yes");
    else
        puts("No");
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        init();
        solution();
    }
    return 0;
}