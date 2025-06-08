#include <bits/stdc++.h>
using namespace std;
bool a[105][105];
int n;
bool vis[105];
int ans = -1;

bool check_vis() {
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) return false;
    }
    return true;
}

bool bfs(int s) {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i) {
            if (a[x][i] && !vis[i]) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return check_vis();
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[y][x] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (bfs(i)) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}