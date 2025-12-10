#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005], b[200005];

inline ll read() {
    ll read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

int main() {
    freopen("gift.in", "r", stdin);
    freopen("gift.out", "w", stdout);
    ll n = read(), m = read(), d = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int j = 1; j <= m; ++j) b[j] = read();
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    int i = n, j = m;
    ll ans = -1;
    while (i && j && abs(a[i] - b[j]) > d) {
        if (a[i] > b[j]) --i;
        else --j;
    } 
    if (i && j) ans = max(ans, a[i] + a[j]);
    cout << ans << endl;
    return 0;
}