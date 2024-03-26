#include<bits/stdc++.h>
#define ll long long
#define reg register int
#define cl(x) memset(x, 0, sizeof(x))
#define lc(x) tree[x].son[0]
#define rc(x) tree[x].son[1]
#define father(x) tree[x].fa

struct splay{
    int v;
    int siz, wit;
    int fa, son[2];
}tree[100010];
int n;
int root = 0;
int len = 0;

void dfs(int pos) {
    if (pos) {
        printf("%d %d\n", pos, tree[pos].v);
        dfs(lc(pos));
        dfs(rc(pos));
    }
}

int read() {
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

inline bool relation(int pos) {
    return pos == rc(tree[pos].fa);
}

inline void maintain(int pos) {
    tree[pos].siz = tree[lc(pos)].siz + tree[rc(pos)].siz + tree[pos].wit;
}

inline void ins(int x, int y, int z) {
    tree[x].son[z] = y;
    tree[y].fa = x;
}

inline void rotate(int pos) {
    int f = father(pos);
    bool flag = relation(pos);
    ins(father(f), pos, relation(f));
    ins(f, tree[pos].son[flag^1], flag);
    ins(pos, f, flag^1);
    maintain(f);
    maintain(pos);
    if (!father(pos)) root = pos;
}

void splay(int pos, int tar = 0) {
    while (tree[pos].fa != tar) {
        if (tree[father(pos)].fa != tar) {
            if (relation(pos) == relation(father(pos))) rotate(father(pos));
            else rotate(pos);
        }
        rotate(pos);
    }
}

int pre(int v) {
    int pos = root, ans = 0;
    while (pos) {
        if (tree[pos].v >= v) pos = lc(pos);
        else {
            ans = pos;
            pos = rc(pos);
        }
    }
    splay(ans);
    return root;
}

int succ(int v) {
    int ans = 0, pos = root;
    while (pos) {
        if (tree[pos].v <= v) pos = rc(pos);
        else {
            ans = pos;
            pos = lc(pos);
        }
    }
    splay(ans);
    return root;
}

int find(int v) {
    int pos = root;
    while (pos && tree[pos].v != v) {
        if (v < tree[pos].v) pos = lc(pos);
        else pos = rc(pos);
    }
    if (pos) {
        splay(pos);
        //return root;
    }
    return root;
}

void del(int v) {
    int pos = find(v);
    if (tree[pos].wit > 1) {
        --tree[pos].siz;
        --tree[pos].wit;
        return;
    }
    int y = succ(v); 
    int x = pre(v);
    splay(y, x);
    //lc(y) = 0;
    tree[y].son[0] = 0;
    --tree[y].siz;
    --tree[x].siz;
    //dfs(root);
}

int insert(int v) {
    int pos = root, lt = 0;
    while (pos && tree[pos].v != v) {
        ++tree[pos].siz;
        lt = pos;
        if (v < tree[pos].v) pos = lc(pos);
        else pos = rc(pos);
    }
    if (pos) {
        ++tree[pos].siz;
        ++tree[pos].wit;
    }
    else {
        pos = ++len;
        tree[pos].v = v;
        tree[pos].siz = tree[pos].wit = 1;
        lc(pos) = rc(pos) = 0;
        father(pos) = lt;
        tree[lt].son[v > tree[lt].v] = pos;
    }
    splay(pos);
    return root;
}

int rank(int v) {
    int pos = find(v);
    if (!pos) {
        pos = insert(v);
        int ans = tree[lc(pos)].siz;
        del(v);
        return ans;
    }
    return tree[lc(pos)].siz;
}

int kth(int k) {
    int pos = root;
    int sz = tree[lc(pos)].siz;
    while (k < sz || k >= sz + tree[pos].wit) {
        if (k < sz) pos = lc(pos);
        else {
            k -= sz + tree[pos].wit;
            pos = rc(pos);
        }
        sz = tree[lc(pos)].siz;
    }
    splay(pos);
    return tree[pos].v;
}

void put(int x) {
    if (!x) {putchar('0'); putchar('\n');}
    if (x < 0) {putchar('-'); x = -x;}
    char ch[15];
    int top = 0;
    while (x) {ch[++top] = x % 10 + '0'; x /= 10;}
    while (top) putchar(ch[top--]);
    putchar('\n');
}

int main() {
    n = read();
    insert(0x7fffffff);
    root = 1;
    insert(0x80000000);
    for (reg i = 1; i <= n; ++i) {
        //dfs(root);
        int o = read(), v = read();
        if (o == 1) insert(v);
        else if (o == 2) del(v);
        else if (o == 3) put(rank(v));
        else if (o == 4) put(kth(v));
        else if (o == 5) put(tree[pre(v)].v);
        else if (o == 6) put(tree[succ(v)].v);
    }
    return 0;
}
