#include<bits/stdc++.h>
#define reg register int
#define ll long long
#define cl(x) memset(x, 0, sizeof(x))
#define lc(x) tree[x].son[0]
#define rc(x) tree[x].son[1]
#define fa(x) tree[x].father

struct splay{
    int son[2];
    int father;
    int v;
    int siz;
    bool rev;
}tree[100100];
int root = 0;
int len = 0;
int n, m;
int a[100100];

inline int read() {
    char ch = getchar();
    int k = 0, f = 1;
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

inline bool cp(int pos) {
    return pos == rc(fa(pos));
}

inline void maintain(int pos) {
    tree[pos].siz = tree[lc(pos)].siz + tree[rc(pos)].siz + 1;
}

inline void ins(int x, int y, bool z) {
    tree[x].son[z] = y; fa(y) = x;
}

inline void pushdown(int pos) {
    if (tree[pos].rev) {
        tree[pos].rev = 0;
        std::swap(lc(pos), rc(pos));
        if (lc(pos)) tree[lc(pos)].rev ^= 1;
        if (rc(pos)) tree[rc(pos)].rev ^= 1;
    }
}

inline void rotate(int pos) {
    int f = fa(pos);
    bool flag = cp(pos);
    ins(fa(f), pos, cp(f));
    ins(f, tree[pos].son[flag^1], flag);
    ins(pos, f, flag^1);
    maintain(f);
    maintain(pos);
    if (!fa(pos)) root = pos;
}

void splay(int pos, int tar = 0) {
    while (fa(pos) != tar) {
        if (fa(fa(pos)) != tar) {
            if (cp(pos) == cp(fa(pos))) rotate(fa(pos));
            else rotate(pos);
        }
        rotate(pos);
    }
}

int find(int pos, int v) {
    pushdown(pos);
    if (tree[lc(pos)].siz + 1 == v) return pos;
    else if (tree[lc(pos)].siz >= v) return find(lc(pos), v);
    else return find(rc(pos), v - tree[lc(pos)].siz - 1);
}

int insert(int v) {
    int pos = root;
    int lt = 0;
    while (pos && tree[pos].v != v) {
        lt = pos;
        if (v < tree[pos].v) pos = lc(pos);
        else pos = rc(pos);
    }
    pos = ++len;
    tree[pos].v = v;
    tree[pos].siz = 1;
    lc(pos) = rc(pos) = 0;
    tree[pos].rev = 0;
    fa(pos) = lt;
    tree[lt].son[v > tree[lt].v] = pos;
    splay(pos);
    return root;
}

void rever(int x, int y) {
    int xx = find(root, x);
    int yy = find(root, y + 2);
    splay(xx);
    splay(yy, xx);
    tree[lc(yy)].rev ^= 1;
}

void dfs(int pos) {
    pushdown(pos);
    if (lc(pos)) dfs(lc(pos));
    if (tree[pos].v >= 1 && tree[pos].v <= n) printf("%d ", tree[pos].v);
    if (rc(pos)) dfs(rc(pos));
}

int main() {
    n = read();
    insert(0);
    root = 1;
    for (reg i = 1; i <= n + 1; ++i) insert(i);
    m = read();
    for (reg i = 1; i <= m; ++i) {
        int x = read();
        int y = read();
        rever(x, y);
    }
    dfs(root);
    return 0;
}
