#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, d;
int v[N], a[N];
typedef long long ll;

int main() {
    cin >> n >> d;
    for (int i = 1; i < n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll ans = 0;
    int dis = 0, mn = a[1];
    for (int i = 1; i < n; ++i) {
        int buy = (v[i] - dis - 1) / d + 1;
        ans += buy * mn;
        if (a[i + 1] < mn) mn = a[i + 1];
        dis = buy * d + dis - v[i];
    }
    cout << ans << endl;
    return 0;
}