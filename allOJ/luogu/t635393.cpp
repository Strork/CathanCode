#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int s[105][105];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1];
            if (a[i][j]) ++s[i][j];
        }
    } // 二位前缀和 1的数量
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= min(n, m); ++k) {
                int x = i + k - 1, y = j + k - 1; // 右下角坐标
                if (x > n || y > m) break;
                if (s[x][j] - s[i-1][j] - s[x][j-1] + s[i-1][j-1] != k) continue;
                if (s[i][y] - s[i-1][y] - s[i][j-1] + s[i-1][j-1] != k) continue;
                if (s[x][y] - s[i-1][y] - s[x][y-1] + s[i-1][y-1] != k) continue;
                if (s[x][y] - s[x-1][y] - s[x][j-1] + s[x-1][j-1] != k) continue;
                ans = max(ans, k*k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}