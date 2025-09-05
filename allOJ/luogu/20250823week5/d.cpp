#include <bits/stdc++.h>
using namespace std;
struct edge {
    int x, y, v;
}e[2000010];
int n, m, jump[1005], len, ans;
int x[1005], y[1005], fa[1005];

bool mycmp(edge a, edge b) { return a.v < b.v; }

int getfa(int xx) {
    if (fa[xx] == xx) return fa[xx];
    fa[xx] = getfa(fa[xx]);
    return fa[xx];
}

void kruskal() {
    sort(e + 1, e + 1 + len, mycmp);
    int cnt = 0;
    for (int i = 1; i <= len; ++i) {
        int fx = getfa(e[i].x);
        int fy = getfa(e[i].y);
        if (fx != fy) {
            ++cnt;
            fa[fx] = fy;
        }
        if (cnt == n - 1) {
            ans = e[i].v;
            return;
        }
    }
}

int main() {
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> jump[i];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        fa[i] = i;
        for (int j = 1; j < i; ++j) {
            int tx = x[i] - x[j], ty = y[i] - y[j];
            e[++len].x = i;
            e[len].y = j, e[len].v = tx * tx + ty * ty;
        }
    }
    kruskal();
    int cnt = 0;
    for (int i = 1; i <= m; ++i) if (jump[i] * jump[i] >= ans) ++cnt;
    cout << cnt << endl;
    return 0;
}