#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
int dis[2550];
struct node {
    int y, v;
};
vector<node> a[2550];
bool vis[2550];

int main() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        a[x].push_back({y, v});
        a[y].push_back({x, v});
    }
    memset(dis, 0x3f, sizeof(dis)); // 所有的点初始化最大值
    dis[s] = 0; 
    for (int tim = 1; tim <= n; ++tim) {
        int k = -1;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i] && (k == -1 || dis[i] < dis[k])) k = i;
        }
        vis[k] = 1; // 找到最近的，并且没有加入到集合的点
        for (int i = 0; i < a[k].size(); ++i) { // 遍历所有 k 的边
            int y = a[k][i].y, v = a[k][i].v;
            if (dis[k] + v < dis[y]) dis[y] = dis[k] + v;
        }
    }
    cout << dis[t] << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
    
//     return 0;
// }