#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, c, x0, g, a;

ll low_mul(ll x, ll y) {
    ll t = 0;
    while (y) {
        if (y & 1) (t += x) %= m;
        (x += x) %= m;
        y >>= 1;
    }
    return t;
}

struct fac {
    ll a[3][3];
    fac operator*(const fac& b) const {
        fac t;
        for (int i = 1; i <= 2; ++i)
            for (int j = 1; j <= 2; ++j) {
                t.a[i][j] = 0;
                for (int k = 1; k <= 2; ++k)
                    t.a[i][j] = (t.a[i][j] + low_mul(a[i][k], b.a[k][j])) % m;
            }
        return t;
    }
} cc, fib;

void init() {
    cin >> m >> a >> c >> x0 >> n >> g;
    cc.a[1][1] = a, cc.a[1][2] = 0;
    cc.a[2][2] = cc.a[2][1] = 1;
    fib.a[1][1] = x0, fib.a[1][2] = c;
}

void fastpower(ll y) {
    while (y) {
        if (y & 1) fib = fib * cc;
        cc = cc * cc, y >>= 1;
    }
}

int main() {
    init();
    fastpower(n);
    cout << fib.a[1][1] % g << endl;
    return 0;
}