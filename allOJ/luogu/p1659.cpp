#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 19930726;
ll d[4000005];
ll df[4000005];
ll n, k;

inline ll fp(ll x, ll y) {
    ll su = 1;
    while (y) {
        if (y & 1) su = su * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return su;
}

void manacher() {
    string s;
    cin >> s;
    s = "4" + s + "5";
    int r = -1, mid = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (i <= r)
            d[i] = min(d[mid * 2 - i], 1LL * r - i + 1);
        else
            d[i] = 1;
        while (s[i + d[i]] == s[i - d[i]]) ++d[i];
        if (i + d[i] > r) r = i + d[i] - 1, mid = i;
        ++df[1], --df[d[i] << 1];
    }
}

int main() {
    cin >> n >> k;
    manacher();
    ll sum = 0;
    for (int i = 1; i <= n; ++i)
        df[i] += df[i - 1], sum += df[i];  // 统计长度个数
    if (sum < k) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 1, t = k;
    for (int i = n; i >= 3; --i) {
        if (!(i & 1)) continue;
        if (t > df[i])
            ans = ans * fp(i, df[i]) % mod, t -= df[i];
        else {
            ans = ans * fp(i, t) % mod;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}