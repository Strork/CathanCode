#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
priority_queue<pii, vector<pii>, greater<pii>> q; // 小根堆
int dis[100005];
vector<pii> a[100005];
bool vis[100005];
int n, m, s;

int main() {
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        a[x].push_back({v, y}); // 读入边
    }
    dis[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        pii t = q.top(); // 堆顶
        q.pop();
        int k = t.second; // k 是最短的节点
        if (vis[k]) continue; // 如果 k 用过了跳过
        vis[k] = 1;
        for (auto to : a[k]) { // 遍历 k 的相邻的节点
            int y = to.second;
            if (dis[k] + to.first < dis[y]) {
                dis[y] = dis[k] + to.first;
                q.push({dis[y], y});
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << dis[i] << ' ';
    return 0;
}