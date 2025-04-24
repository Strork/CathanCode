#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[100100];
ll t[100100];
ll f[100100];

int main() {
    cin >> n;
    for (ll i = 1; i <= n; ++i) cin >> a[i];
    for (ll i = 1; i < n; ++i) cin >> t[i];
    for (ll i = 1; i < n; ++i) {
        ll y = t[i];
        if (f[i-1] + a[i] > f[i]) f[i] = f[i-1] + a[i];
        if (f[i] + a[y] > f[y]) f[y] = f[i] + a[y];
    }
    cout << f[n] << endl;
    return 0;
}
