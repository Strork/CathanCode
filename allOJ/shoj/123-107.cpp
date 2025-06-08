#include <bits/stdc++.h>
#define ll long long
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define MOD 1000000007
using namespace std;

const int maxn = 200100;
struct qaq{
    ll maxx, deladd;
    ll delx;
}tree[maxn * 4];
int n, q;
int x, y;

void push_down(ll id, ll l, ll r) {
    if (tree[id].delx == 1 && tree[id].deladd == 0) return;
    ll tad = tree[id].deladd;
    ll txx = tree[id].delx;
    ll mid = (l + r) >> 1;
    tree[L(id)].deladd = (tree[L(id)].deladd * txx + tad) % MOD;
    tree[R(id)].deladd = (tree[R(id)].deladd * txx + tad) % MOD;
    tree[L(id)].delx = (tree[L(id)].delx * txx) % MOD;
    tree[R(id)].delx = (tree[R(id)].delx * txx) % MOD;
    tree[L(id)].maxx = (tree[L(id)].maxx * txx + (mid - l + 1) * tad) % MOD;
    tree[R(id)].maxx = (tree[R(id)].maxx * txx + (r - mid) * tad) % MOD;
    tree[id].deladd = 0;
    tree[id].delx = 1;
    return;
}

void build(ll l, ll r, ll id) {
    tree[id].delx = 1;
    tree[id].deladd = 0;
    if (l == r) return;
    ll mid = (l + r) >> 1;
    build(l, mid, L(id));
    build(mid + 1, r, R(id));
}

void updatamul(ll l, ll r, ll id, ll v) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        tree[id].deladd = (tree[id].deladd * v) % MOD;
        tree[id].delx = (tree[id].delx * v) % MOD;
        tree[id].maxx = (tree[id].maxx * v) % MOD;
        return;
    }
    push_down(id, l, r);
    ll mid = (l + r) >> 1;
    updatamul(l, mid, L(id), v);
    updatamul(mid + 1, r, R(id), v);
    return;
}

void updataadd(ll l, ll r, ll id, ll v) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        tree[id].deladd = (tree[id].deladd + v) % MOD;
        tree[id].maxx = (tree[id].maxx + (r - l + 1) * v) % MOD;
        return;
    }
    push_down(id, l, r);
    ll mid = (l + r) >> 1;
    updataadd(l, mid, L(id), v);
    updataadd(mid + 1, r, R(id), v);
    return;
}

ll findit(int l, int r, int id) {
    if (l > y || r < x) return 0;
    if (x <= l && r <= y) {
        return tree[id].maxx % MOD;
    }
    push_down(id, l, r);
    ll mid = (l + r) >> 1;
    ll t1 = findit(l, mid, L(id));
    ll t2 = findit(mid + 1, r, R(id));
    return (t1 + t2) % MOD;
}

int main () {
    cin >> n >> q;
    build(1, n, 1);
    for (int i = 1; i <= q; ++i) {
        char ch;
        cin >> ch;
        if (ch == '+') {
            int v;
            cin >> x >> v;
            y=x;
            updataadd(1, n, 1, v);
        } else if (ch == '*') {
            int v;
            cin >> v;
            x = 1, y = n;
            updatamul(1, n, 1, v);
        }
    }
    for (int i = 1; i <= n; ++i) {
        x = y = i;
        cout << findit(1, n, 1) << ' ';
    }
    return 0;
}