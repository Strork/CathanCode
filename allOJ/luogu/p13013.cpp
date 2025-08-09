#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll l, r, n, m, a, b;
ll ans = 0;

bool check(ll k) {
    int mi = ceil((n - b * k) * 1.0 / (a - b)); //x>=(n-bk)/(a-b)
    int ma = floor((m - a * k) * 1.0 / (b - a));//x<=(m-ak)/(b-a)
    if (k * (a + b) > n + m) return false;
    if (ma >= 0 && mi <= ma) return true;
    return false;
}

int main() {
    cin >> n >> m >> a >> b;
    if (a == b) { // a == b 时被除数为0，可以直接输出答案，最多就是min(n, m) / a
        cout << min(n, m) / a << endl;
        return 0;
    }
    if (a > b) swap(a, b);
    l = 0;
    r = min(n, m) / a;
    while (l <= r) {
        ll mid = l+r>>1;
        if (check(mid)) l = mid+1, ans = mid;
        else r = mid-1;
    }
    cout << ans << endl;
    return 0;
}