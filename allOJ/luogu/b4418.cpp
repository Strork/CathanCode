#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

ll fast_power(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main() {
    cout << -8 % 5 << endl;
    return 0;
}