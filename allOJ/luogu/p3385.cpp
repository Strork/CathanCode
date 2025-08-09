    #include <bits/stdc++.h>
    #define N 2005
    using namespace std;
    bool vis[N];
    struct edge { int y, v; };
    vector<edge> a[N];
    int cnt[N], dis[N];
    int n, m;

    bool spfa() {
        queue<int> q;
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));
        // for (int i = 1; i <= n; ++i) {
        //     q.push(i);
        //     vis[i] = 1;
        // }
        q.push(1);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            vis[x] = 0;
            for (auto [y, v] : a[x]) {
                if (dis[x] == dis[2004]) continue;
                if (dis[y] > dis[x] + v) {
                    dis[y] = dis[x] + v;
                    cnt[y] = cnt[x] + 1;
                    if (cnt[y] >= n) return true;
                    if (!vis[y]) vis[y] = 1, q.push(y);
                }
            }
        }
        return false;
    }

    int main() {
        int T; cin >> T;
        while (T--) {
            cin >> n >> m;
            for (int i = 1; i <= m; ++i) {
                int x, y, v;
                cin >> x >> y >> v;
                if (v >= 0) {
                    a[x].push_back({y, v});
                    a[y].push_back({x, v});
                } else a[x].push_back({y, v});
            }
            if (spfa()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        return 0;
    }