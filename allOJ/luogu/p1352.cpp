#include <bits/stdc++.h>
using namespace std;
vector<int> a[10000];
int fa[10000];
int n;
int f[10000][2];

void dfs(int x) {
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        dfs(y); // 先向下搜索
        f[x][0] += max(f[y][0], f[y][1]); // 当前节点不参加
        f[x][1] += f[y][0]; // 当前节点参加
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i][1];
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> y >> x;
        fa[y] = x;
        a[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i) {
        if (!fa[i]) {
            dfs(i);
            cout << max(f[i][0], f[i][1]);
        }
    }
    return 0;
}