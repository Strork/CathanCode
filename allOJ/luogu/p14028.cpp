#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
ll a[200005], s[200005];

ll read() {
    ll read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

int main() {
    int T = read();
    while (T--) {
        memset(s, 0, sizeof(s));
        n = read(), m = read();
        for (int i = 1; i <= n; ++i) a[i] = read();
        for (int i = 1; i <= m; ++i) {
            int l = read(), r = read();
            s[l]++, s[r + 1]--;
        }
        for (int i = 1; i <= n; ++i) s[i] += s[i - 1]; // 统计某个数操作了多少次
        ll maxx = -2e9, minn = 2e9;
        for (int i = 1; i <= n; ++i) {
            minn = min(a[i] + s[i], minn);
            maxx = max(a[i] - s[i], maxx);
        }
        if (maxx >= minn) cout << maxx - minn << endl;
        else cout << 0 << endl;
    }
    return 0;
}