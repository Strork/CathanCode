#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005];
ll n, m;
ll sum = 0;
ll maxx = 0;

void binary_search(ll l, ll r) {
    while (l+1 < r) {
        ll mid = (l+r)/2;
        ll cnt = 1;
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (sum + a[i] <= mid) {
                sum += a[i];
            } else {
                ++cnt;
                sum = a[i];
            }
        }
        if (cnt > m) l = mid;
        else r = mid;
    }
    ll cnt = 1;
    for (int i = 1; i <= n; ++i) {
        if (sum + a[i] <= l) {
            sum += a[i];
        } else {
            ++cnt;
            sum = a[i];
        }
    }
    if (cnt > m) cout << r;
    else cout << l << endl;
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        maxx = max(a[i], maxx);
    }
    binary_search(maxx, 100000000);
    return 0;
}