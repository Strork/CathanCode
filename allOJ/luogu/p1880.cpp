#include <bits/stdc++.h>
using namespace std;
int f[305][305];
int g[305][305];
int n;
int a[305];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
        a[i] += a[i - 1];
    }
    for (int i = n + 1; i <= 2 * n; ++i) a[i] += a[i - 1];
    for (int c = 2; c <= n; ++c) {
        for (int i = 1; i <= 2 * n; ++i) {
            int j = i + c - 1;
            if (j > 2 * n) break;
            f[i][j] = 998244353;
            for (int k = i; k < j; ++k) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
                g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j] + a[j] - a[i - 1]);
            }
        }
    }
    int maxx = 0, minn = 123445423;
    for (int i = 1; i <= n; ++i) {
        maxx = max(maxx, g[i][n + i - 1]);
        minn = min(minn, f[i][n + i - 1]);
    }
    cout << minn << endl << maxx << endl;
    return 0;
}