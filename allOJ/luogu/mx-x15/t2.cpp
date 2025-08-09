#include <bits/stdc++.h>
using namespace std;
int leef, n, T;
vector<int> a[100005];

void dfs(int x, int fa) {
    bool f = 0;
    for (auto y : a[x]) {
        if (y == fa) continue;
        f = 1;
        dfs(y, x);
    }
    if (!f) leef++;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) a[i].clear();
        for (int i = 1; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        if (a[1].size() == 1) leef = 1;
        dfs(1, 0);
        cout << leef - 1 << endl;
    }
    return 0;
}