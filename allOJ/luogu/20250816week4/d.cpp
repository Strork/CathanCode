#include <bits/stdc++.h>
using namespace std;
int f[305][305];
int g[305][305];
int T, n, m;

int main() {
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        n = max(n, x), m = max(m, y);
        ++f[x][y], ++g[y][x];
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) f[i][j] += f[i][j-1];
    for (int j = 1; j <= m; ++j) for (int i = 1; i <= n; ++i) g[j][i] += g[j][i-1];
    return 0;
}