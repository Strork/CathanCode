#include <bits/stdc++.h>
#define ll long long
using namespace std;
int f[25][25][25];

int func(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return func(20, 20, 20);
    // 返回已知答案
    if (f[a][b][c]) return f[a][b][c];
    if (a < b && b < c) {
        f[a][b][c] = func(a, b, c-1) + func(a, b-1, c-1) - func(a, b-1, c);
    }
    f[a][b][c] = func(a-1, b, c) + func(a-1, b-1, c) +
                 func(a-1, b, c-1) - func(a-1, b-1, c-1);
    return f[a][b][c];
}

int main() {
    ll a, b, c;
    while (cin >> a >> b >> c) {
        if (a == b && b == c && c == -1) break;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, func(a, b, c));
    }
    return 0;
}