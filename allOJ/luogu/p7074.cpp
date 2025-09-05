#include <bits/stdc++.h>
using namespace std;
long long f[1005][1005][2];
int a[1005][1005];
int n, m;

int main() {
    cin >> n >> m;
    memset(f, -10, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    f[1][1][0] = f[1][1][1] = a[1][1]; // 第一个点
    for (int i = 2; i <= n; ++i) f[i][1][0] = f[i-1][1][0] + a[i][1]; // 第一列只能往下走
    for (int j = 2; j <= m; ++j) { // 枚举第 j 列
        for (int i = 1; i <= n; ++i) {
            f[i][j][0] = max(f[i][j-1][0], f[i][j-1][1]) + a[i][j]; // 从左侧转移最大值
            f[i][j][0] = max(f[i][j][0], f[i-1][j][0]) + a[i][j]; // 从上侧选最大值
        }
        for (int i = n; i >= 1; --i) {
            f[i][j][1] = max(max(f[i][j-1][0], f[i][j-1][1]), f[i+1][j][1]) + a[i][j]; // 从左侧和上侧选最大值
        }
    }
    cout << max(f[n][m][0], f[n][m][1]) << endl;
    return 0;
}