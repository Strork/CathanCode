#include<bits/stdc++.h>
#define ll long long
#define reg register int
#define cl(x, y) memset(x, y, sizeof(x))
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

using std::swap;

inline int read() {
    int k = 0, f = 1;
    char ch = getchar();
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

struct qaq{
    int y, nt;
}e[200100];
int len = 0;
int lin[100100];

struct qwq{
    int l, r;
    int laz;
    int sum;
}tree[400100];

int fa[100100], id[100100], son[100100];
int siz[100100], top[100100], dep[100100];
int tot = 0;

int n, m;
char ch[15];

void dfs(int x) {
    siz[x] = 1;
    son[x] = n;
    for (reg i = lin[x]; i; i = e[i].nt) {
        int y = e[i].y;
        if (y != fa[x]) {
            fa[y] = x;
            dep[y] = dep[x] + 1;
            dfs(y);
            if (siz[y] > siz[son[x]]) son[x] = y;
            siz[x] += siz[y];
        }
    }
}

void dfs2(int x, int p) {
    id[x] = ++tot;
    top[x] = p;
    if (son[x] != n) dfs2(son[x], p);
    for (reg i = lin[x]; i; i = e[i].nt) {
        int y = e[i].y;
        if (y != son[x] && y != fa[x]) dfs2(y, y);
    }
}

void build(int p, int a, int b) {
    tree[p].l = a;
    tree[p].r = b;
    tree[p].laz = -1;
    if (a == b) return;
    int mid = (a + b) >> 1;
    build(ls(p), a, mid);
    build(rs(p), mid + 1, b);
}

void pushdown(int p) {
    if (tree[p].laz == -1) return;
    else if (tree[p].laz == 1) {
        tree[ls(p)].sum = tree[ls(p)].r - tree[ls(p)].l + 1;
        tree[rs(p)].sum = tree[rs(p)].r - tree[rs(p)].l + 1;
        tree[ls(p)].laz = 1;
        tree[rs(p)].laz = 1;
        tree[p].laz = -1;
    }
    else {
        tree[ls(p)].sum = 0;
        tree[rs(p)].sum = 0;
        tree[ls(p)].laz = 0;
        tree[rs(p)].laz = 0;
        tree[p].laz = -1;
    }
}

void update(int p, int a, int b, int v) {
    int l = tree[p].l;
    int r = tree[p].r;
    if (r < a || l > b) return;
    if (a <= l && r <= b) {
        tree[p].laz = v;
        tree[p].sum = v * (r - l + 1);
        return;
    }
    pushdown(p);
    update(ls(p), a, b, v);
    update(rs(p), a, b, v);
    tree[p].sum = tree[ls(p)].sum + tree[rs(p)].sum;
}

int get_sum(int p, int a, int b) {
    int l = tree[p].l;
    int r = tree[p].r;
    if (r < a || l > b) return 0;
    if (a <= l && r <= b) return tree[p].sum;
    pushdown(p);
    return get_sum(ls(p), a, b) + get_sum(rs(p), a, b);
}

int work(int x) {
    int y = 0;
    int ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        int temp = get_sum(1, id[top[x]], id[x]);
        ans += temp;
        update(1, id[top[x]], id[x], 1);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    ans += get_sum(1, id[x], id[y]);
    update(1, id[x], id[y], 1);
    return ans;
}

inline void insert(int x, int y) {
    e[++len].nt = lin[x];
    lin[x] = len;
    e[len].y = y;
}

int main() {
    cl(fa, -1);
    n = read();
    for (reg i = 1; i < n; ++i) {
        int x = read();
        insert(x, i);
        insert(i, x);
    }
    dfs(0);
    dfs2(0, 0);
    build(1, 1, n);
    m = read();
    for (reg i = 1; i <= m; ++i) {
        scanf("%s", ch);
        int x = read();
        if (ch[0] == 'i') {
            int ans = work(x);
            printf("%d\n", dep[x] + 1 - ans);
        }
        else if (ch[0] == 'u') {
            int ans = get_sum(1, id[x], id[x] + siz[x] - 1);
            update(1, id[x], id[x] + siz[x] - 1, 0);
            printf("%d\n", ans);
        }
    }
    return 0;
}
