#include<bits/stdc++.h>
#define ll long long
#define reg register int
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
using namespace std;

struct qaq{
    int y, nt, v;
}e[200100];
struct qwq{
    int sum;
    int laz;
    int l, r;
}tree[400100];

int lin[100100];
int len = 0, tot = 0;
int n, m, r, mod;
int val[100100], siz[100100], son[100100];
int fa[100100], top[100100], deep[100100];
int id[100100], di[100100];

int read() {
    char ch = getchar();
    int f = 1, k = 0;
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        k = k * 10 + ch - '0';
        ch = getchar();
    }
    return k * f;
}

inline void insert(int x, int y) {
    e[++len].nt = lin[x];
    lin[x] = len;
    e[len].y = y;
}

void dfs(int x) {
    siz[x] = 1;
    son[x] = 0;
    for (int i = lin[x]; i; i = e[i].nt) {
        int y = e[i].y;
        if (y != fa[x]) {
            fa[y] = x;
            deep[y] = deep[x] + 1;
            dfs(y);
            if (siz[y] > siz[son[x]]) son[x] = y;
            siz[x] += siz[y];
        }
    }
}

void dfs2(int x, int p) {
    id[x] = ++tot;
    di[tot] = x;
    top[x] = p;
    if (son[x]) dfs2(son[x], p);
    for (int i = lin[x]; i; i = e[i].nt) {
        int y = e[i].y;
        if (y != son[x] && y != fa[x]) {
            dfs2(y, y);
        }
    }
}

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (l == r) {
        tree[p].sum = val[di[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    tree[p].sum = tree[ls(p)].sum + tree[rs(p)].sum;
}

void pushdown(int p) {
    if (tree[p].laz) {
        int temp = tree[p].laz;
        tree[ls(p)].laz += temp;
        tree[rs(p)].laz += temp;
        tree[ls(p)].sum += (tree[ls(p)].r - tree[ls(p)].l + 1) * temp;
        tree[rs(p)].sum += (tree[rs(p)].r - tree[rs(p)].l + 1) * temp;
        tree[p].laz = 0;
    }
}

int get_sum(int p, int a, int b) {
    int l = tree[p].l;
    int r = tree[p].r;
    if (r < a || l > b) return 0;
    if (a <= l && r <= b) {
        return tree[p].sum;
    }
    pushdown(p);
    int ans = 0;
    ans = get_sum(ls(p), a, b) + get_sum(rs(p), a, b);
    return ans % mod;
}

void update(int p, int a, int b, int val) {
    int l = tree[p].l;
    int r = tree[p].r;
    if (l > b || r < a) return;
    if (a <= l && r <= b) {
        tree[p].sum += val * (r - l + 1);
        tree[p].laz += val;
        return;
    }
    pushdown(p);
    update(ls(p), a, b, val);
    update(rs(p), a, b, val);
    tree[p].sum = (tree[ls(p)].sum + tree[rs(p)].sum) % mod;
}

void work1(int x, int y, int v) {
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        update(1, id[top[x]], id[x], v);
        x = fa[top[x]];
    }
    if (deep[x] > deep[y]) swap(x, y);
    update(1, id[x], id[y], v);
}

void work2(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        ans += get_sum(1, id[top[x]], id[x]);
        ans %= mod;
        x = fa[top[x]];
    }
    if (deep[x] > deep[y]) swap(x, y);
    ans += get_sum(1, id[x], id[y]);
    ans %= mod;
    printf("%d\n", ans);
}

void prt(int x) {
    printf("%d %d\n", x, id[x]);
    for (reg i = lin[x]; i; i = e[i].nt) {
        if (e[i].y != fa[x]) prt(e[i].y);
    }
}

void init() {
    n = read(), m = read(), r = read(), mod = read();
    for (reg i = 1; i <= n; ++i) val[i] = read();
    for (reg i = 1; i < n; ++i) {
        int x = read(), y = read();
        insert(x, y);
        insert(y, x);
    }
    dfs(r);
    dfs2(r, r);
    build(1, 1, n);
    for (reg i = 1; i <= m; ++i) {
        int p = read();
        if (p == 1) {
            int x = read(), y = read(), v = read();
            work1(x, y, v);
        }
        else if (p == 2) {
            int x = read(), y = read();
            work2(x, y);
        }
        else if (p == 3) {
            int x = read(), v = read();
            update(1, id[x], id[x] + siz[x] - 1, v);
        }
        else if (p == 4) {
            int x = read();
            int ans = get_sum(1, id[x], id[x] + siz[x] - 1);
            ans %= mod;
            printf("%d\n", ans);
        }
    }
}

int main() {
    init();
    return 0;
}

