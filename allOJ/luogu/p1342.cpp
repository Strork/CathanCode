#include <bits/stdc++.h>
#define ll long long
#define pli pair<ll, int>
using namespace std;
const int N = 1e6 + 5;
ll dis[2][N];
bool vis[2][N];
int n, m;
struct edge {
    int y, v;
};
vector<edge> a[2][N];
ll ans = 0;

void dijkstra(int t) {
    priority_queue<pli, vector<pli>, greater<pli>> q; // 小根堆
    memset(dis, 0x3f, sizeof(dis));
    dis[t][1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        pli p = q.top();
        q.pop();
        if (vis[t][p.second]) continue;
        ll k = p.second, d = p.first;
        vis[t][k] = 1;
        for (int i = 0; i < a[t][k].size(); ++i) {
            ll y = a[t][k][i].y, v = a[t][k][i].v;
            if (dis[t][y] > d + v) {
                dis[t][y] = d + v;
                q.push({dis[t][y], y});
            }
        }
    }
    for (int i = 2; i <= n; ++i) ans += dis[t][i];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        a[0][x].push_back({y, v});
        a[1][y].push_back({x, v});
    }
    dijkstra(0);
    dijkstra(1);
    cout << ans << endl;
    return 0;
}