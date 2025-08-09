#include <bits/stdc++.h>
#define ll long long
using namespace std;
int l, r, n;
ll a[60];
unsigned ll sum;
ll less_than = 0;
ll more_than = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> l >> r;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > r) more_than += a[i] - r;
        if (a[i] < l) less_than += l - a[i];
    }
    if (sum < l*n || sum > r*n) cout << -1 << endl;
    else cout << max(more_than, less_than);
    return 0;
}