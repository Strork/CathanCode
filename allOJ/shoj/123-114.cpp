#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;

int main() {
    cin >> t >> a >> b >> c;
    int ans = t;
    ans -= t/a; ans -= t/b; ans -= t/c;
    ans += t/lcm(a,b);
    ans += t/lcm(a,c);
    ans += t/lcm(b,c);
    ans -= t/lcm(lcm(a, c), b);
    cout << ans << endl;
    return 0;
}