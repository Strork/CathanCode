#include<bits/stdc++.h>
#define oo 0x7f7f7f7f
#define ll long long
#define reg register int

using namespace std;

int n;
int ans = 0;

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

struct treap{
    int fix;
    int val;
    int cnt;
    treap *l, *r;
};
treap *root = NULL;

void left_rotate(treap* &a) {
    treap *b = a -> r;
    a -> r = b -> l;
    b -> l = a;
    a = b;
}

void right_rotate(treap* &a) {
    treap *b = a -> l;
    a -> l = b -> r;
    b -> r = a;
    a = b;
}

void treap_insert(treap* &p, int val) {
    if (p == NULL) {
        p = new treap;
        p -> val = val;
        p -> fix = rand();
        p -> cnt = 1;
        p -> l = p -> r = NULL;
        return;
    }
    if (val == p -> val) p -> cnt += 1;
    else if (val < p -> val) {
        treap_insert(p -> l, val);
        if (p -> l -> fix < p -> fix)
            right_rotate(p);
    }
    else if (val > p -> val) {
        treap_insert(p -> r, val);
        if (p -> r -> fix < p -> fix)
            left_rotate(p);
    }
}

inline int treap_max(treap *p) {
    while (p -> r)
        p = p -> r;
    return p -> val;
}

inline int treap_min(treap *p) {
    while (p -> l)
        p = p -> l;
    return p -> val;
}

void treap_delete(treap *&p, int val) {
    if (!p) return;
    if (val == p -> val) {
        p->cnt -= 1;
        if (!p -> cnt) {
            if (!p -> l || !p -> r) {
                treap *t = p;
                if (!p -> l) p = p -> r;
                else p = p -> l;
                delete t;
            }
            else {
                if (p -> l -> fix < p -> r -> fix) {
                    right_rotate(p);
                    treap_delete(p -> r, val);
                }
                else {
                    left_rotate(p);
                    treap_delete(p -> l, val);
                }
            }
        }
    }
    else if (val < p -> val) 
        treap_delete(p -> l, val);
    else 
        treap_delete(p -> r, val);
}

int main() {
    //freopen("prom.in", "r", stdin);
    //freopen("prom.out", "w", stdout);
    srand((unsigned)time(NULL));
    n = read();
    for (int i = 1; i <= n; ++i) {
        int m = read();
        for (int j = 1; j <= m; ++j) {
            int val = read();
            treap_insert(root, val);
        }
        int maxx = treap_max(root);
        int minn = treap_min(root);
        ans += maxx - minn;
        treap_delete(root, maxx);
        treap_delete(root, minn);
    }
    printf("%d\n", ans);
    return 0;
}


