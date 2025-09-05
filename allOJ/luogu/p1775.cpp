#include <bits/stdc++.h>
using namespace std;
int f[305][305];
int n;
int a[305];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; 
        a[i] += a[i - 1]; // 前缀和
    }
    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l < n; ++l) {
            int r = l + len - 1;
            if (r > n) break;
            f[l][r] = 1e9;
            for (int k = l; k < r; ++k) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + a[r] - a[l - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}