#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n;
        scanf("%lld", &n);
        ll t = 1;
        while (t <= n) t <<= 1;
        t >>= 1;  // 从最高位的 1 开始
        ll a = t, b = 0;
        t >>= 1;
        while (!(t & n) && t) t >>= 1;  // 找第二位 1
        b = t;
        t >>= 1;
        while (t) {
            if (t & n)
                a |= t;  // a += t;
            else
                a |= t, b |= t;  // a += t, b += t;
            t >>= 1;
        }
        printf("%lld\n", a + b);
    }
    return 0;
}