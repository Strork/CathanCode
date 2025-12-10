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
    int ans = f[0];
    f[0] = 0;
    for (int i = 0; i < n; ++i) { // 以第 i 关 出发
        for (int j = 1; j <= m; ++j) {
            int ed = i + a[j];
            if (ed >= n) ans = max(ans, f[i] + b[i]);
            else f[ed] = max(f[ed], f[i] + b[i]);
        }
    }
    cout << ans << endl;
    return 0;
}