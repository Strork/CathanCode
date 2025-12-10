#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, x;
int a[100005];
ll ans;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int t = a[i] + a[i + 1] - x;
        if (t > 0) {
            a[i + 1] -= t;
            ans += t;
            if (a[i + 1] < 0) {
                a[i] += a[i + 1];
                a[i + 1] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}