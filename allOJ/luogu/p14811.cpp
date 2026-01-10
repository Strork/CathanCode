#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll n, m;
struct farm {
    int w, l, r;
} a[N];
ll ans, got;
ll tim[N], sum[N];

bool mycmp(farm x, farm y) { return x.w > y.w; }

int main() {
    cin >> n >> m;
    ll k = m;
    for (int i = 1; i <= n; ++i) cin >> a[i].w >> a[i].l >> a[i].r;
    sort(a + 1, a + 1 + n, mycmp);
    for (int i = 1; i <= n; ++i) {
        k -= a[i].l;
        got += 1LL * a[i].l * a[i].w;
        tim[i] = tim[i - 1] + a[i].r - a[i].l;
        sum[i] = sum[i - 1] + (a[i].r - a[i].l) * a[i].w;  // 前缀和
    }
    for (int i = n; i >= 1; i--) {
        k += a[i].l;
        got -= 1LL * a[i].l * a[i].w;  // 从最低限制中减掉
        int id = lower_bound(tim + 1, tim + i, k) - tim;
        --id;                              // 找到第一个小于 k 的位置
        ll t = sum[id];                    // id 是通过 k 得到的截止下标
        t += (k - tim[id]) * a[id + 1].w;  // t 是额外获得的作物
        ans = max(t + got, ans);
        k -= a[i].l;
        got += 1LL * a[i].l * a[i].w;
    }
    cout << ans << endl;
    return 0;
}