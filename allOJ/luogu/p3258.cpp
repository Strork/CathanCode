#include <bits/stdc++.h>
#define debug(x) cout << x << endl;
using namespace std;
typedef long long ll;
const int N = 3e5 + 5;
int tr[N];
int n, id;
vector<int> a[N];
int g[N], fa[N], dep[N], siz[N], dfn[N], rnk[N], son[N], top[N];
int del[N];

inline int lowbit(int x) { return x & (-x); }

inline ll query(int r) {
    ll sum = 0;
    for (int i = r; i; i -= lowbit(i)) sum += tr[i];
    return sum;
}

inline ll query(int l, int r) { return query(r) - query(l - 1); }

inline void add_tr(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += k;
}

void dfs1(int x, int f) {
    fa[x] = f, dep[x] = dep[f] + 1, siz[x] = 1;
    for (auto y : a[x]) {
        if (y == f) continue;
        dfs1(y, x);
        siz[x] += siz[y];
        if (siz[y] > siz[son[x]]) son[x] = y;
    }
}

void dfs2(int x, int ftop) {
    top[x] = ftop, dfn[x] = ++id, rnk[id] = x;
    if (son[x]) dfs2(son[x], ftop);
    for (auto y : a[x]) {
        if (y != fa[x] && y != son[x]) dfs2(y, y);
    }
}

void add_xtoy(int x, int y) {   // 利用 树状数组 + 差分，对区间进行操作
    while (top[x] != top[y]) {  // 判断同一条链
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        add_tr(dfn[top[x]], 1);
        add_tr(dfn[x] + 1, -1);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    add_tr(dfn[x], 1);
    add_tr(dfn[y] + 1, -1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> g[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y), a[y].push_back(x);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i < n; ++i) add_xtoy(g[i], g[i + 1]);
    for (int i = 1; i <= n; ++i) printf("%d\n", query(dfn[g[i]]) - 1);
    return 0;
}