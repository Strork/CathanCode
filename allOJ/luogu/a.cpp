#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int b[1005][1005];
int c[1005][1005];
int m, n, maxx = -123456789;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    // 输入 A B 矩阵
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= k; ++j) {
            cin >> b[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int t = 1; t <= m; ++t) {
                c[i][j] += a[i][t] * b[t][j];
            }
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}