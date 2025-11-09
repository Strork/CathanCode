#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int n, a[100005];
int cnt[5003];
ll ans = 0;

inline int mod(int a) { return (1LL * a * (a - 1) >> 1) % MOD;}
inline int mod(int a, int b) {return 1LL * a * b % MOD; }

int main() {
    cin >> n;
    int m = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        m = max(m, a[i]);
    }
    for (int i = 2; i <= m; ++i) {
        if (cnt[i] <= 1) continue; // 长度为 i 的木棍不能作为两个单独的边
        int m = i >> 1;
        if (!(i & 1) && cnt[m] >= 2) {
            ll t = mod(cnt[m]); // 两根拼边的方案数
            t = mod(t, mod(cnt[i]));
            ans = (ans % MOD + t % MOD) % MOD;
        }
        if ((i & 1) == 0) m -= 1;
        for (int j = 1; j <= m; ++j) {
            if (!cnt[j] || !cnt[i - j]) continue;
            ll t = mod(cnt[j], cnt[i - j]);
            t = mod(t, mod(cnt[i]));
            ans = (ans + t) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}