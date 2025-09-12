#include <bits/stdc++.h>
using namespace std;
int a[105];
int b[20005];
int f[20005];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i]; // 通道长度
    for (int i = 0; i < n; ++i) cin >> b[i]; // 关卡积分
    memset(f, -0x3f, sizeof(f));
    f[0] = b[0];
    for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int pre = i - a[j];
            if (pre < 0) continue;
            f[i] = max(f[i], f[pre] + b[i]);
        }
    }
    int ans = -0x3f3f3f3f;
    //for (int i = 0; i <= 2 * n; ++i) cout << f[i] << ' '; cout << endl;
    for (int i = n; i <= 2 * n; ++i) ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}