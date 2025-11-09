#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool f[5];

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    ll x, y, z;
    cin >> x >> y >> z;
    if (x == 0) puts("1");
    else if (x * 2 * y + 1 <= 4) cout << x * 2 * y + 1 << endl;
    else cout << x * 2 * y * 5 * z + 1 << endl;
    return 0;
}