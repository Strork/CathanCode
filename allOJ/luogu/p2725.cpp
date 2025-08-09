#include <bits/stdc++.h>
using namespace std;
int k, n;
int v[505], w[505];
int f[2000005];
int maxf;
int cnt;

int main() {
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    cin >> k >> n;
    for (int i = 1; i <= n; ++i) {
        int money;
        cin >> money;
        maxf = max(maxf, money);
        int t = k, a = 1;
        while (t) {
            if (a > t) t = a;
            w[++cnt] = money * a;
            v[cnt] = 1 * a;
            t -= a;
            a <<= 1;
        }
    }
    maxf *= k;
    for (int i = 1; i <= cnt; ++i) {
        for (int j = maxf+1; j >= w[i]; --j) {
            f[j] = min(f[j], f[j - w[i]] + v[i]);
        }
    }
    for (int i = 1; i <= maxf+1; ++i) {
        if (f[i] > k) {
            cout << i-1 << endl;
            break;
        }
    }
    return 0;
}