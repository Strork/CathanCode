#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll a[200005];
ll s[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += a[i] * (s[n] - s[i]);
    }
    cout << ans << endl;
    return 0;
}