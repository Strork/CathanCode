#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[25], m = 0;
bool p[5000100];
int ans = 0;

void dfs(int x, int sum, int cnt) {
    if (cnt == k) {
        if (!p[sum]) ++ans;
        return;
    }
    if (x >= n+1) return;
    dfs(x+1, sum+a[x], cnt+1);
    dfs(x+1, sum, cnt);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        m += a[i];
    }
    for (int i = 2; i <= m; ++i) {
        if (!p[i]) {
            for (int j = 2; j <= m; ++j) {
                if (i*j > m) break;
                p[i*j] = 1;
            }
        }
    }
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
