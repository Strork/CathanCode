#include <bits/stdc++.h>
using namespace std;
int a[505][505];
int b, n, cnt, ans;
bool vis[505];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> q;  // 小根堆，找最短边

void prim() {
    while (cnt <= n) {  // 树中节点不够 n + 1
        auto node = q.top();
        q.pop();
        int x = node.second;
        if (vis[x]) continue;
        vis[x] = 1, ++cnt, ans += node.first;
        cout << x << " : ";
        for (int i = 0; i <= n; ++i) {  // 找新加入节点可以扩展的节点
            if (a[x][i] && a[x][i] <= b && !vis[i]) {
                q.push({a[x][i], i});
                cout << i << ' ';
            }
        }
        cout << endl;
    }
    cout << ans << endl;
}

int main() {
    cin >> b >> n;
    for (int i = 1; i <= n; ++i) {
        a[0][i] = a[i][0] = b;
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (a[i][j] > b) a[i][j] = 0;
        }
    }
    cnt = 1, vis[n] = 1;  // 随便选择起点，选 n 号点
    for (int i = 0; i < n; ++i)
        if (a[n][i] <= b) q.push({a[n][i], i});
    prim();
    return 0;
}