#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
vector<int> a[200005];
bool vis[200005];
int dis[200005];

void pre() {
    for (int i = 0; i < n; ++i) {
        a[i].clear();
        dis[i] = 1234567890;
        vis[i] = 0;
    }
}

void bfs() {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    int mex = 0;
    while (vis[mex] && mex < n) ++mex;
    a[s].push_back(mex);
    a[mex].push_back(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        while (vis[mex] && mex < n) ++mex;
        a[x].push_back(mex);
        a[mex].push_back(x);
        for (auto y : a[x]) {
            if (!vis[y]) {
                dis[y] = min(dis[y], dis[x] + 1);
                vis[y] = 1;
                q.push(y);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        scanf("%d %d %d %d", &n, &m, &s, &t);
        pre();
        for (int i = 1; i <= m; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (x == y) continue;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        if (s == t) {
            cout << 0 << endl;
            continue;
        }
        bfs();
        cout << dis[t] << endl;
    }
    return 0;
}