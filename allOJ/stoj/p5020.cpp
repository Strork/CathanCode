#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int a[105];
int f[25005];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        int m = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] > m) m = a[i];
        }
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = a[i]; j <= m; ++j) {
                f[j] += f[j - a[i]];
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (f[a[i]] == 1) ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
