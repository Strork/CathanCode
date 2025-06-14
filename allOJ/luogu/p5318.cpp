#include <bits/stdc++.h>
using namespace std;
vector<int> a[100010];
int cnt = 0;
int n, m;
bool vis[100010];

inline void addE(int x, int y) {
    a[x].push_back(y);
}

void dfs(int x) {
    cout << x << ' ';
    sort(a[x].begin(), a[x].end());
    for (auto i : a[x]) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(i);
        }
    }
}

void bfs(int s) {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        cout << x << ' ';
        q.pop();
        for (int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            if (!vis[y]) {
                vis[y] = 1;
                q.push(y);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        addE(x, y);
    }
    vis[1] = 1;
    dfs(1); 
    cout << endl;
    bfs(1);
    return 0;
}
