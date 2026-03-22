#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int dfn[N], low[N], cnt[N], cd[N], vis[N], stk[N << 1], id[N];
vector<int> a[N], b[N], c;
int n, m, dfn_id, top, pid;

void init() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        b[y].push_back(x);
    }
}

void tarjan(int x) {
    low[x] = dfn[x] = ++dfn_id;
    vis[stk[++top] = x] = 1;  // 标记入栈
    for (auto y : a[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (vis[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x]) {
        ++pid;
        int k;
        do {
            k = stk[top--];
            vis[k] = 0, id[k] = pid, ++cnt[pid];
        } while (k != x);
    }
}

void solution_tarjan() {
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    int star = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto j : a[i])
            if (id[j] != id[i]) ++cd[id[i]];  // 统计缩点后，所有的点的出度
    }
    for (int i = 1; i <= pid; ++i) {
        if (cd[i] == 0) ++star, ans = max(ans, cnt[i]);  // 缩点后的出度统计
    }
    if (star == 1)  // 不能有多个终点（这样没有牛能被所有人喜欢）
        cout << ans << endl;
    else
        cout << 0 << endl;
}

void dfs1(int x) {
    vis[x] = 1;
    for (auto y : a[x])
        if (!vis[y]) dfs1(y);
    c.push_back(x);
}

void dfs2(int x) {
    id[x] = pid, ++cnt[pid];
    for (auto y : b[x])
        if (!id[y]) dfs2(y);
}

void solution_kosaraju() {
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs1(i);
    for (int i = n - 1; i >= 0; --i)
        if (!id[c[i]]) ++pid, dfs2(c[i]);

    int star = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto j : a[i])
            if (id[j] != id[i]) ++cd[id[i]];  // 统计缩点后，所有的点的出度
    }
    for (int i = 1; i <= pid; ++i) {
        if (cd[i] == 0) ++star, ans = max(ans, cnt[i]);  // 缩点后的出度统计
    }
    if (star == 1)  // 不能有多个终点（这样没有牛能被所有人喜欢）
        cout << ans << endl;
    else
        cout << 0 << endl;
}

int main() {
    init();
    // solution_tarjan();
    solution_kosaraju();
    return 0;
}