#include <bits/stdc++.h>
#define ll long long
using namespace std;
int sch[100005];
int n, m;


int main() {
    cin >> m >> n;
    ll ans = 0;
    for (int i = 1; i <= m; ++i) cin >> sch[i];
    sch[m + 1] = -10000000;
    sch[m + 2] = 10000000;
    m += 2;
    sort(sch + 1, sch + 1 + m);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        int id = lower_bound(sch + 1, sch + 1 + m, x) - sch;
        int dif = abs(sch[id] - x);
        dif = min(abs(sch[id - 1] - x), dif); // 离估分最近的学校
        ans += dif;
    }
    cout << ans << endl;
    return 0;
}