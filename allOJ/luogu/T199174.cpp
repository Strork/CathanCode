#include <bits/stdc++.h>
using namespace std;
int a[100005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        int j = lower_bound(a + 1, a + 1 + n, x) - a;
        if (a[j] == x) cout << j << endl;
        else cout << -1 << endl;
    }
    return 0;
}