#include<bits/stdc++.h>
#define ll long long

using namespace std;
int a, b, c, d;
ll f[100100];
int n;
int money[100100];

inline int mymin(int x1, int x2, int x3, int x4, int x5) {
    int t = x1;
    if (x2 < t) t = x2;
    if (x3 < t) t = x3;
    if (x4 < t) t = x4;
    if (x5 < t) t = x5;
    return t;
}

int main() {
    scanf("%d", &n);
    scanf("%d %d %d %d", &a, &b, &c, &d);
    for (int i = 1; i <= n; ++i) scanf("%d", &money[i]);
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        ll minn = mymin(a, b, c, d, money[i]);
        f[i] = f[i-1] + minn;
        if (i - 30 >= 0) {
            ll x1 = f[i - 30] + b;
            ll x2 = min(f[i - 30] + c, f[i - 30] + d);
            minn = min(x1, x2);
            f[i] = min(f[i], minn);
        }
        else {
            ll x1 = b;
            ll x2 = min(c, d);
            minn = min(x1, x2);
            f[i] = min(f[i], minn);
        }
        if (i - 365 >= 0) {
            minn = min(f[i - 365] + c, f[i - 365] + d);
            f[i] = min(f[i], minn);
        }
        else {
            minn = min(c, d);
            f[i] = min(f[i], minn);
        }
        if (i - 3650 >= 0) f[i] = min(f[i], f[i - 3650] + d);
        else f[i] = min(f[i], f[0] + d);
    }
    cout << f[n] << endl;
    return 0;
}