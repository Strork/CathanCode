#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N], tr[N];
int n, cnt;

inline int lowbit(int x) { return x & (-x); }

inline void update(int x, int k) {
    for (int i = x; i <= cnt; i += lowbit(i)) tr[i] += k;
}

inline int query(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i)) sum += tr[i];
    return sum;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    cnt = 1;
    for (int i = 2; i <= n; ++i)
        if (b[i] != b[i - 1]) b[++cnt] = b[i];
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, query(cnt) - query(a[i]));
        update(a[i], 1);
    }
    printf("%d\n", ans + 1);
    return 0;
}