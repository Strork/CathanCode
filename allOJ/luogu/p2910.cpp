#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[105][105];
int n, m;
int p[10005];
ll ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    for (int i = 1; i < m; ++i) ans += a[p[i]][p[i + 1]];
    cout << ans << endl;
    return 0;
}