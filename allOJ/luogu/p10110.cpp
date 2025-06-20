#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, st, ed;
int val[N];
vector<int> a[N];
int dis[N];

int main() {
    cin >> n >> m >> st >> ed;
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
    }
    queue<int> q;
    q.push(st);
    memset(dis, -1, sizeof(dis));
    dis[st] = 0;
    bool f = 0;
    while (!q.empty()) {
        if (f) break;
        int x = q.front();
        q.pop();
        for (auto y : a[x]) {
            if (dis[y] == -1) {
                dis[y] = dis[x] + 1;
                if (y == ed) {
                    f = 1;
                    cout << dis[y] + val[ed] - val[st];
                    break;
                }
                q.push(y);
            }
        }
    }
    if (!f) cout << "No solution" << endl;
    return 0;
}