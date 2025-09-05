#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int f[105][105];
int ans[105];
int n, m;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    memset(f, -10, sizeof(f));
    for (int i = 0; i <= n; ++i) {
        f[i][0] = 0;
    }
    for (int i = 0; i <= m; ++i) {
        f[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= m; ++j) {
            if (f[])
        }
    }
    return 0;
}