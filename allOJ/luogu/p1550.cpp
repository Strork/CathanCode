#include <bits/stdc++.h>
using namespace std;
struct edge {
    int x, y, v;
}e[100010];
int n, m, fa[305], ans;

inline bool mycmp(edge a, edge b) { return a.v < b.v; }

int getfa(int x) {
    if (fa[x] == x) return fa[x];
    return fa[x] = getfa(fa[x]);
}

void kruskal() {
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
        int px = getfa(e[i].x);
        int py = getfa(e[i].y);
        if (px != py) {
            ans += e[i].v;
            ++cnt;
            fa[px] = py;
        }
        if (cnt >= n) break;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int w;
        cin >> w;
        e[++m] = {n + 1, i, w};
        fa[i] = i;
    }
    fa[n + 1] = n + 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int w;
            cin >> w;
            if (j > i) e[++m] = {i, j, w};
        }
    }
    sort(e + 1, e + 1 + m, mycmp);
    kruskal();
    cout << ans << endl;
    return 0;
}