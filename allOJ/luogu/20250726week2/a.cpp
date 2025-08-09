#include <bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<ll, ll> tim;
int n;
ll a[100005], m;
ll ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        m = max(m, (a[i]<<1));
        for (int k = 1; (1LL<<k) <= m; ++k) {
            if ((1LL<<k) <= a[i]) continue;
            ll t = (1LL << k) - a[i];
            if (tim.find(t) == tim.end()) continue;
            ans += tim[t];
        }
        if(tim.find(a[i]) == tim.end()) tim[a[i]] = 1;
        else ++tim[a[i]];
    }
    cout << ans << endl;
    return 0;
}