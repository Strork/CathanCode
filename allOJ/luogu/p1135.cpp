#include <bits/stdc++.h>
using namespace std;
int n, a, b;
queue<int> q;
int dis[23333];
int p[2333];

int main() {
    cin >> n >> a >> b;
    memset(dis, -1, sizeof(dis));
    for (int i = 1; i <= n; ++i) cin >> p[i];
    dis[a] = 0;
    q.push(a);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int up = x + p[x], down = x - p[x];
        if (up <= n && dis[up] == -1) q.push(up), dis[up] = dis[x] + 1;
        if (down >= 1 && dis[down] == -1) q.push(down), dis[down] = dis[x] + 1;
    }
    cout << dis[b] << endl;
    return 0;
}