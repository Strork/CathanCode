#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[100500];
int ans[100500];
bool f[100500];

int dfs(int x) {
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if (!ans[y]) {
           int t = dfs(y);
           ans[x] = max(x, t);
        } else return ans[y];
    }
    return max(ans[x], x);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i) {

        if (!f[i]) {
            int mx = max(dfs(i), i);
            ans[i] = mx;
        }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    return 0;
}