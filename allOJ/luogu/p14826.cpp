#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        if (k == 0) {
            puts("0");
            continue;
        }
        ll ans = n * k;
        for (ll a = 1; a * a <= n; ++a) {
            ans = min(ans, a + n / a + k * (n - a * (n / a)));
        }
        cout << ans << endl;
    }
    return 0;
}