#include <bits/stdc++.h>
using namespace std;
int prime[1000000];
bool p[1000100];
int len;
int n, m, a;

int main() {
    cin >> n >> m >> a;
    memset(p, 1, sizeof(p));
    p[1] = 0;
    int ans = 0;
    for (int i = 2; i <= n+m; ++i) {
        if (p[i]) prime[++len] = i;
        for (int j = 1; j <= len && i * prime[j] <= n+m; ++j) {
            p[prime[j]*i] = 0;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = n; i <= n+m; ++i) {
        if (i <= a) { // 本来就满足
            ++ans;
            continue;
        }
        if (p[i]) { // 不满足且无法分解
            continue;
        }
        int t = i;
        bool flag = 0;
        for (int j = 1; j <= len; ++j) {
            while (t % prime[j] == 0) {
                t /= prime[j];
                if (t <= a || p[t]) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        if (t <= a) ++ans;
    }
    cout << ans << endl;
    return 0;
}