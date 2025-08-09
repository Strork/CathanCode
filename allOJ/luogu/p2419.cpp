#include <bits/stdc++.h>
using namespace std;
bitset<105> a[105];
int n, m, ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (a[i][k]) a[i] = a[i] | a[k];
        }
    }
    for (int k = 1; k <= n; ++k) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i][k]) ++ sum;
        }
        sum += a[k].count();
        if (sum == n - 1) ++ans;
    }
    cout << ans << endl;
    return 0;
}