#include <bits/stdc++.h>
using namespace std;
bool isp[10000005];
int p[10000005];
int a[10000005];
int n, m, c;

void ola() {
    memset(isp, 1, sizeof(isp));
    isp[0] = isp[1] = 0;
    for (int i = 2; i <= m; ++i) {
        if (isp[i]) {
            p[++c] = i;
            a[i] = 1;
        }
        for (int j = 1; j <= c && i * p[j] <= m; ++j) {
            isp[i * p[j]] = 0;
            if (i % p[j] == 0) break;
        }
    }
}

int fj(int x) {
    int cnt = 0;
    int t = 1;
    int sum = 1;
    while (!isp[x] && !a[x]) {
        if (x % p[t] == 0) {
            x /= p[t];
            sum *= p[t];
            ++cnt;
            a[sum] = cnt;
        }
        else ++t;
    }
    return cnt + a[x];
}

int main() {
    cin >> n >> m;
    ola();
    int ans = 1;
    for (int i = n; i <= m; ++i) {
        if (isp[i]) continue;
        if (!a[i]) {
            a[i] = fj(i);
        }
        ans = max(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}