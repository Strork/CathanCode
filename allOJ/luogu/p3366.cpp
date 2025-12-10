#include <bits/stdc++.h>
using namespace std;
struct edge {
    int x, y, v;
}e[200005];
bool cmp(edge a, edge b) { return a.v < b.v; }
int n, m;
int fa[5005];

int getfa(int x) {
    if (fa[x] == x) return x;
    fa[x] = getfa(fa[x]);
    return fa[x];
}

int ans;

int kruskal() {
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
        int fx = getfa(e[i].x);
        int fy = getfa(e[i].y);
        if (fx == fy) continue;
        fa[fx] = fy;
        ++cnt;
        ans += e[i].v;
        if (cnt == n - 1) break;
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> e[i].x >> e[i].y >> e[i].v;
    sort(e + 1, e + 1 + m, cmp); // 边排序
    for (int i = 1; i <= n; ++i) fa[i] = i; // 并查集初始化
    int cnt = kruskal();
    if (cnt < n - 1) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}