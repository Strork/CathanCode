#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll s[100005];
ll a[100005];

ll read() {
    ll read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int c = read(), T = read();
    while (T--) {
        ll n = read(), k = read();
        for (int i = 1; i <= n; ++i) a[i] = read();
        sort(a + 1, a + 1 + n);
        ll ans = k;
        int min_index = 1;
        for (int i = 2; i <= n; ++i) {
            s[i] = 1LL * i * k - a[i] + a[1];
            if (s[i] < s[min_index]) min_index = i;
            else ans = max(ans, s[i] - s[min_index] + k);
        }
        cout << ans << endl;
    }
    return 0;
}