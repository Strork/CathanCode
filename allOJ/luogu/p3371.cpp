#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dis[10005];
struct node {
    ll y, v; // y 是点，v 就是长度
};
vector<node> a[10005];
bool vis[10005];

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i) dis[i] = (1LL<<31)-1;
    for (int i = 1; i <= m; ++i) {
        ll x, y, v;
        cin >> x >> y >> v;
        a[x].push_back({y, v});
    }
    dis[s] = 0;
    int T = n;
    while (T--) {
        int k = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i] && (!k || dis[i] < dis[k])) {
                k = i; // 遍历所有的点，找最小的dis且未标记的点
            }
        }
        vis[k] = 1;
        for (auto to : a[k]) {
            int y = to.y, v = to.v;
            if (dis[k] + v < dis[y]) {
                dis[y] = dis[k] + v;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << dis[i] << ' ';
    }
    return 0;
}