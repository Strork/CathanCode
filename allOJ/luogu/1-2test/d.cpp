#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1001000];
int n;
ll ans = 0;
int tim;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        if (t > tim) tim = t; // 最大的时间节点
        a[s] += d; // 差分左端点
        a[t+1] -= d; // 差分操作：右端点
    }
    for (int i = 1; i <= tim; ++i) {
        a[i] += a[i-1];
        if (a[i] > ans) ans = a[i];
    }
    cout << ans << endl;
    return 0;
}