#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> a[N];
int dep[N];
int n, s;

void dfs(int x, int fa) {
    for (auto y : a[x]) {
        if (y == fa) continue;
        dep[y] = dep[x] + 1;
        if (dep[y] > dep[s]) s = y;
        dfs(y, x);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    dep[s] = 0;
    dfs(s, s);
    cout << dep[s] << endl;
    return 0;
}