#include<bits/stdc++.h>
#define reg register int
#define ll long long
#define lc(x) c[x][0]
#define rc(x) c[x][1]

using std::swap;
using std::cout;

int c[300100][2];
int fa[300100];
int v[300100];
int st[300100];
bool rev[300100];
int ans[300100];
int n, m;

inline int read() {
    char ch = getchar();
    int k = 0, f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { k = k * 10 + ch - '0'; ch = getchar(); }
    return k * f;
}

inline void revers(int x) {
    swap(lc(x), rc(x));
    rev[x] ^= 1;
}

inline void pushup(int x) {
    ans[x] = ans[lc(x)] ^ ans[rc(x)] ^ v[x];
}

inline void pushdown(int x) {
    if (rev[x]) {
        rev[x] = 0;
        if (lc(x)) revers(lc(x));
        if (rc(x)) revers(rc(x));
    }
}

inline bool son(int x) {
    return x == c[fa[x]][1];
}

inline void ins(int x, int y, int z) {
    c[x][z] = y;
    fa[y] = x;
}

inline bool noroot(int x) {
    return c[fa[x]][0] == x || c[fa[x]][1] == x;
}

inline void rotate(int x) {
    int f = fa[x]; //cout<<f;
    bool flag = son(x);
    if (noroot(f)) ins(fa[f], x, son(f));
    else fa[x] = fa[f];
    ins(f, c[x][flag^1], flag);
    ins(x, f, flag^1);
    pushup(f);
}

inline void splay(int x) {
    int tot = 0;
    st[++tot] = x;
    int t = x;
    while (noroot(t)) {
        t = fa[t];
        st[++tot] = t;
    }
    while (tot) pushdown(st[tot--]);
    while (noroot(x)) {
        if (noroot(fa[x])) {
            if (son(x) == son(fa[x])) rotate(fa[x]);
            else rotate(x);
        }
        rotate(x);
    }
    pushup(x);
}

inline void access(int x) {
    for (reg y = 0; x; x = fa[x]) {
        splay(x);
        rc(x) = y;
        pushup(x);
        y = x;
    }
}

inline void makeroot(int x) {
    access(x);
    splay(x);
    revers(x);
}

int findroot(int x) {
    access(x);
    splay(x);
    while (lc(x)) {
        pushdown(x);
        x = lc(x);
    }
    splay(x);
    return x;
}

inline void split(int x, int y) {
    makeroot(x);
    access(y);
    splay(y);
}

inline void addlink(int x, int y) {
    makeroot(x);
    if (findroot(y) != x) fa[x] = y;
}

inline void cut(int x, int y) {
    makeroot(x);
    if (findroot(y) != x || fa[y] != x || c[y][0]) return;
    fa[y] = c[x][1] = 0;
    pushup(x);
}

int main() {
    n = read(); m = read();
    for (reg i = 1; i <= n; ++i) v[i] = read();
    for (reg i = 1; i <= m; ++i) {
        int op = read();
        int x = read(), y = read();
        if (op == 0) { split(x, y); printf("%d\n", ans[y]); }
        else if (op == 1) addlink(x, y);
        else if (op == 2) cut(x, y);
        else if (op == 3) { splay(x); v[x] = y; }
    }
    return 0;
}
