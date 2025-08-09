#include <bits/stdc++.h>
using namespace std;
vector<int> a[1000005];
int dis[1000005];
int id;

void dfs(int x, int fa) {
    for (auto y : a[x]) {
        if (y == fa) continue;
        dis[y] = dis[x] + 1;
        if (dis[y] > dis[id]) {
            id = y;
        }
        dfs(y, x);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 0);
    dis[id] = 0;
    dfs(id, 0);
    cout << dis[id] << endl;
    return 0;
}