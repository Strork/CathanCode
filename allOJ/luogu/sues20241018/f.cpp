#include <bits/stdc++.h>
using namespace std;
int v, n, a[50];
int f[50];
int ans = 0;

void dfs(int x, int t) {
    if (x == n) {
        if (t + a[n] <= v) ans = max(ans, t+a[n]);
        else ans = max(ans, t);
        return;
    }
    if (t + a[x] <= v) dfs(x+1, t+a[x]);
    dfs(x+1, t);
}

int main() {
    cin >> v;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dfs(1, 0);
    cout << v - ans << endl;
    return 0;
}