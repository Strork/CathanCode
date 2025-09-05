#include <bits/stdc++.h>
using namespace std;
struct jerry {
    int x, y, t;
}a[10005];
int f[10005];
int ans;

inline bool heat(jerry i, jerry j) {
    return i.t - j.t >= abs(i.x - j.x) + abs(i.y - j.y);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].t >> a[i].x >> a[i].y;
        f[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (heat(a[i], a[j])) f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}