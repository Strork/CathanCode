#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b;

int main() {
    cin >> a >> b;
    if (a > b) a = a % b;  // 整体上仍然是容斥的思想
    ll ans = b - gcd(a, b);
    cout << ans << endl;
    return 0;
}
