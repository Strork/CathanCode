#include <bits/stdc++.h>
using namespace std;
int n, h, ans;
int a[25];

void dfs(int x, int sum) {
    if (sum - h > ans) return;
    if (x >= n + 1) {
        if (sum - h >= 0) ans = sum - h;
        return;
    }
    dfs(x + 1, sum + a[x]);
    dfs(x + 1, sum);
}

int main() {
    cin >> n >> h;
    ans = 123456789;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n, greater<int>());
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}