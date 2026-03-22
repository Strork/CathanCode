#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
ll n;
// https://www.luogu.com.cn/team/105136
struct fac {
    ll a[3][3];
    fac operator*(const fac& b) const {
        fac t;
        for (int i = 1; i <= 2; ++i) {
            for (int j = 1; j <= 2; ++j) {
                t.a[i][j] = 0;
                for (int k = 1; k <= 2; ++k) {
                    t.a[i][j] = (t.a[i][j] + a[i][k] * b.a[k][j]) % M;
                }
            }
        }
        return t;
    }
} cc, fib;

void init() {
    cc.a[1][1] = cc.a[1][2] = cc.a[2][1] = 1;
    fib.a[1][1] = fib.a[1][2] = 1;
}

void fastpower(ll y) {
    while (y) {
        if (y & 1) fib = fib * cc;
        cc = cc * cc;
        y >>= 1;
    }
}

int main() {
    init();
    cin >> n;
    if (n <= 2)
        cout << 1 << endl;
    else {
        fastpower(n - 2);
        cout << fib.a[1][1] << endl;
    }
    return 0;
}