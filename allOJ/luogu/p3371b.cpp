#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct edge { int y, v; };
vector<edge> a[10050];
ll dis[10005];
int n, m, s;

bool bellman_ford(int s) {
    for (int i = 1; i <= n; ++i) dis[i] = (1LL << 31) - 1;
    dis[s] = 0;
    bool change = 0;
    for (int i = 1; i <= n; ++i) {
        change = 0;
        for (int x = 1; x <= n; ++x) {
            if (dis[x] == (1LL << 31) - 1) continue;
            for (auto [y, v] : a[x]) {
                if (dis[y] > dis[x] + v) {
                    dis[y] = dis[x] + v;
                    change = 1;
                }
            }
        }
        if (!change) break;
    }
    return change;
}

int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        a[x].push_back({y, v});
    }
    bellman_ford(s);
    for (int i = 1; i <= n; ++i) {
        cout << dis[i] << ' ';
    }
    return 0;
}