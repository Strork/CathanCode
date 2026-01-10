#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, cnt;
int c[500005];
inline int lowbit(int x) { return x & -x; }
int a[500005], b[500005];

inline void update(int x, int k) {
    for (int i = x; i <= cnt; i += lowbit(i)) c[i] += k;
}

inline int query(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i)) sum += c[i];
    return sum;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + 1 + n);
    cnt = 1;
    for (int i = 2; i <= n; ++i)
        if (b[i] != b[i - 1]) b[++cnt] = b[i];
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += query(cnt) - query(a[i]);  // a[i]+1 ~ cnt 的和
        update(a[i], 1);
    }
    cout << ans << endl;
    return 0;
}