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
        if (t > tim) tim = t;
        a[s] += d;
        a[t+1] -= d;
    }
    for (int i = 1; i <= tim; ++i) {
        a[i] += a[i-1];
        if (a[i] > ans) ans = a[i];
    }
    cout << ans << endl;
    return 0;
}