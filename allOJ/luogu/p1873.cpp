#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, need, m;
ll h[1000100];

int main() {
    cin >> n >> need;
    for (int i = 1; i <= n; ++i) cin >> h[i], m = max(m, h[i]);
    ll l = 0, r = m;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll sum = 0;
        for (int i = 1; i <= n; ++i) if (h[i] > mid) sum += h[i] - mid;
        if (sum >= need) m = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << m << endl;
    return 0;
}