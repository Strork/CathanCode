#include <bits/stdc++.h>
#define MAXN 1500000000LL
#define ll long long
using namespace std;
ll n, m;

void baoli() {
    ll t = m - (n - 1) * n / 2;
    cout << t - 1 << ' ';
    ll p = n - 1;
    ll ans = 1;
    while (t - n + 1 > p) p++, ans++, t -= n - 1;
    cout << t - ans << endl;
}

int main() {
    int T; cin >> T; while (T--) {
        cin >> n >> m;
        if (n >= MAXN*2 || n * (n + 1) / 2 > m) cout << "-1 -1\n";
        else {
            ll t = m - (n - 1) * n / 2;
            cout << t - 1 << ' '; // 最大值
            t -= (t - n) / n * n;
            cout << t - 1 << endl;
        }
    }
    return 0;
}