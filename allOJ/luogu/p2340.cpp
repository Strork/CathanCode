#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, eq[405], iq[405], f[N << 1], k = 4e5, ans = -0x7f3f3f3f;
int main() {
    cin >> n;
    memset(f, -0x3f, sizeof(f));
    f[k] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> eq[i] >> iq[i];
    }
    for (int i = 1; i <= n; i++) {
        if (eq[i] >= 0) {
            for (int j = 2 * k; j >= eq[i]; j--) {
                f[j] = max(f[j], f[j - eq[i]] + iq[i]);
            }
        } else {
            for (int j = 0; j <= 2 * k + eq[i]; j++) {
                f[j] = max(f[j], f[j - eq[i]] + iq[i]);
            }
        }
    }
    for (int i = k; i <= 2 * k; i++) {
        if (f[i] >= 0) {
            ans = max(ans, f[i] + i - k);
        }
    }
    cout << ans << endl;
    return 0;
}
