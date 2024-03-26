#include<bits/stdc++.h>
#define ll long long
#define reg register int

using std::cout;
using std::cin;
int ch[30];

ll change(int a, int b, int c) {
    ll num = 0;
    int k = 0;
    while (c) {
        ch[++k] = c % 10;
        c /= 10;
    }
    while (b) {
        ch[++k] = b % 10;
        b /= 10;
    }
    while (a) {
        ch[++k] = a % 10;
        a /= 10;
    }
    while (k) {
        num = num * 10 + ch[k--];
    }
    return num;
}

int main() {
    freopen("a.txt", "w", stdout);
    int n;
    cin >> n;
    for (n = 1; n <= 1000000; ++n) {
    //cout << n;
    ll ans = 0;
    for (reg i = 1; i <= n; ++i) {
        for (reg j = 1; j <= n; ++j) {
            int a = i, b = j, c = i * j;
            //cout << a <<' '<< b <<' '<< c <<' ';
            ll g = change(a, b, c);
            //cout << g << '\n';
            if (g % c == 0) {
                ++ans;
                //cout << i << ' ' << j << '\n';
            }
        }
    }
    cout << ans << '\n';        }
    return 0;
}
