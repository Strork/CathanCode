#include <bits/stdc++.h>
using namespace std;
vector<int> a[100005];
bool f[100005];
int n, m;

void dfs(int x) {
    f[x] = 1;
    for (auto y : a[x]) { // for (int i = 0; i < a[x].size(); ++i) y = a[x][i]
        if (!f[y]) dfs(y);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!f[i]) dfs(i), ++ans;
    }
    cout << ans << endl;
    return 0;
}