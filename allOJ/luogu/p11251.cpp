#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 100005;
int n;
vector<int> a[N];
struct maxnum {
    int maxx, id;
};
int col[N];
int dis[N];
bool f[N]; // vis 访问标记
int ans = 0;

int bfs(int s) {
    queue<int> q;
    memset(f, 0, sizeof(f));
    dis[s] = 0;
    q.push(s);
    f[s] = 1;
    maxnum maxx{-1, 0};
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        //for (auto y : a[x]) {
        for (int i = 0; i < a[x].size(); ++i) {
            int y = a[x][i]; // 相邻节点
            if (!f[y]) { // 没有访问过
                f[y] = 1; // 标记
                dis[y] = dis[x] + 1; // 记下距离
                if (dis[y] > maxx.maxx) { // 记下最远的节点
                    maxx.maxx = dis[y];
                    maxx.id = y;
                }
                q.push(y);
            }
        }
    }
    return maxx.id;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> col[i];
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (col[x] ^ col[y]) {
            a[x].push_back(y);
            a[y].push_back(x);
        }
    }
    memset(dis, -1, sizeof(dis)); // 初始化dis为-1
    for (int i = 1; i <= n; ++i) {
        if (dis[i] == -1) {
            int s = bfs(i); // 找i的最远节点s
            s = bfs(s); // 找s的最远节点，即可得树的直径
            ans = max(ans, dis[s]); // 所有树的最长直径
        }
    }
    cout << ans+1 << endl;
    return 0;
}