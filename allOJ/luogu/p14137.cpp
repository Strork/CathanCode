#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005], n, k;
int maxx = 0, minn = 1e9;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        minn = min(minn, a[i]);
    }
    if (k <= 1) cout << 0 << endl;
    else cout << 1LL * (maxx - minn) * (maxx - minn) << endl;
    return 0;
}