#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
struct edge {
    int y, v;
};
vector<edge> e[100005];
ll ans, dis[100005], max_dis;

void dfs(int x, int fa) {
    // for (int i = 0; i < e[x].size(); ++i) { // 找每个子节点
    for (auto i : e[x]) {
        int y = i.y, v = i.v; // e[x][i].y
        if (y != fa) { // 不往回走 !vis[y]
            dis[y] = dis[x] + v; // 记录从 1 到 y 的路程
            max_dis = max(max_dis, dis[y]); // 记录最远的一条路
            ans += (v * 2);
            dfs(y, x); // dfs(y);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        e[x].push_back({y, v});
        e[y].push_back({x, v});
    }
    dfs(1, 0);
    cout << ans - max_dis << endl;
    return 0;
}