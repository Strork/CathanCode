
struct qaq{
    ll maxx, deladd;
    ll delx;
}tree[maxn * 4];

#define L(x) (x<<1)
void push_down(ll id, ll l, ll r) {
    if (tree[id].delx == 1 && tree[id].deladd == 0) return;
    ll tad = tree[id].deladd;
    ll txx = tree[id].delx;
    ll mid = (l + r) >> 1;
    tree[L(id)].deladd = (tree[L(id)].deladd * txx + tad) % mo;
    tree[R(id)].deladd = (tree[R(id)].deladd * txx + tad) % mo;
    tree[L(id)].delx = (tree[L(id)].delx * txx) % mo;
    tree[R(id)].delx = (tree[R(id)].delx * txx) % mo;
    tree[L(id)].maxx = (tree[L(id)].maxx * txx + (mid - l + 1) * tad) % mo;
    tree[R(id)].maxx = (tree[R(id)].maxx * txx + (r - mid) * tad) % mo;
    tree[id].deladd = 0;
    tree[id].delx = 1;
    return;
}

void build(ll l, ll r, ll id, ll v) {
    // if (l > y || r < x) return;
    tree[id].delx = 1;
    tree[id].deladd = 0;
    if (x <= l && r <= y) {
        tree[id].maxx = v;
        return;
    }
    ll mid = (l + r) >> 1;
    build(l, mid, L(id), v);
    build(mid + 1, r, R(id), v);
    tree[id].maxx = (tree[L(id)].maxx + tree[R(id)].maxx) % mo;
    return;
}

void updatamul(ll l, ll r, ll id, ll v) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        tree[id].deladd = (tree[id].deladd * v) % mo;
        tree[id].delx = (tree[id].delx * v) % mo;
        tree[id].maxx = (tree[id].maxx * v) % mo;
        return;
    }
    push_down(id, l, r);
    ll mid = (l + r) >> 1;
    updatax(l, mid, L(id), v);
    updatax(mid + 1, r, R(id), v);
    tree[id].maxx = (tree[L(id)].maxx + tree[R(id)].maxx) % mo;
    return;
}

void updataadd(ll l, ll r, ll id, ll v) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        tree[id].deladd = (tree[id].deladd + v) % mo;
        tree[id].maxx = (tree[id].maxx + (r - l + 1) * v) % mo;
        return;
    }
    push_down(id, l, r);
    ll mid = (l + r) >> 1;
    updataadd(l, mid, L(id), v);
    updataadd(mid + 1, r, R(id), v);
    tree[id].maxx = (tree[L(id)].maxx + tree[R(id)].maxx) % mo;
    return;
}

ll findit(int l, int r, int id) {
    if (l > y || r < x) return 0;
    if (x <= l && r <= y) {
        return tree[id].maxx % mo;
    }
    push_down(id, l, r);
    ll mid = (l + r) >> 1;
    ll t1 = findit(l, mid, L(id));
    ll t2 = findit(mid + 1, r, R(id));
    return (t1 + t2) % mo;
}
