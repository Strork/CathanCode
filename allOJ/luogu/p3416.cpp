#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int x[205], y[205], r[205];
bitset<205> a[205];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i] >> r[i];
        for (int j = 1; j < i; ++j) {
            ll dis = ((x[i]-x[j]) * (x[i]-x[j])) + ((y[i]-y[j]) * (y[i]-y[j]));
            if (1LL * r[i] * r[i] >= dis) a[i][j] = 1;
            if (1LL * r[j] * r[j] >= dis) a[j][i] = 1;
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (a[i][k]) a[i] |= a[k];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, int(a[i].count()));
    cout << ans << endl;
    return 0;
}