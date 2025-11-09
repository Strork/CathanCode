#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> tree[200005];
bool vis[200005];

void dfs(int x, int fa) {
    for (int i = 0; i < tree[x].size(); ++i) {
        int y = tree[x][i];
        if (y == fa) continue;
        dfs(y, x);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    return 0;
}