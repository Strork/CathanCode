#include <bits/stdc++.h>
using namespace std;
bool f[105];

int main() {
    freopen("flowers.in", "r", stdin);
    freopen("flowers.out", "w", stdout);
    for (int i = 1; i <= 100; ++i) {
        if (!(i & 1)) continue;
        if (i & 1 && i % 3 == 2) continue;
        f[i] = 1;
    }
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        while (!f[x--]) ++ans;
    }
    cout << ans << endl;
    return 0;
}