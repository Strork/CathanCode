#include <bits/stdc++.h>
using namespace std;
int a[300005];
int n, m;

bool check(int x) {
    int p = 0;
    for (int i = 1; i <= m; ++i) { // 8  4 个一份
        p += a[i] / x;
        if (a[i] % x) ++p;
        if (p > n) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        r = max(a[i], r);
    }
    int ans = r;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}