#include <bits/stdc++.h>
using namespace std;
int fa[200005];
int dep[200005];
int n, m;

int find(int x) {
    if (fa[x] == x) return x;
    else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (dep[x] < dep[y]) fa[x] = y;
    else fa[y] = x;
    if (dep[x] == dep[y] && x != y) ++dep[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) fa[i] = i, dep[i] = 1;
    for (int i = 1; i <= m; ++i) {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1) merge(x, y);
        else find(x) == find(y) ? puts("Y") : puts("N");
    }
    return 0;
}