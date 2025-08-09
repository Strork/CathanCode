#include <bits/stdc++.h>
using namespace std;
int f[305][305];
int n;
int a[305];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int c = 2; c <= n; ++c) {
        for (int i = 1; i < n; ++i) {
            int j = i + c - 1;
            if (j > n) break;
            f[i][j] = 998244353;
            for (int k = i; k < j; ++k) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}