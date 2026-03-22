#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll A, B, ca, cb, fa;
        cin >> A >> B >> ca >> cb >> fa;
        if (B >= cb) A += (B / cb) * ca, B %= cb;  // 一开始把能换的换完
        if (A >= fa) {                             // 直接满足条件
            cout << 0 << endl;
            continue;
        }
        ll needA = fa - A - 1;     // A芯片的缺口
        ll ans = cb - 1 - B % cb;  // 取一个极限：答案先加上一些废片
        if (ca >= cb)
            ans += needA;
        else {
            ll t = needA / ca * cb;  // 用亏的方式换：由于 -1，所以不够
            t += needA % ca;         // 加上余数
            ans += t;
        }
        cout << ans + 1 << endl;  // 前面所有的情况都是正好差一个就能满足
    }
    return 0;
}