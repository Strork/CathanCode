#include <bits/stdc++.h>
using namespace std;
int f[10005];
int w[505], v[505];
int n, l;

int main() {
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    cin >> n >> l;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
        if (w[i] > l) w[i] = l; // 我最多需要 l 毫升的饮料
        sum += w[i];
    }
    if (sum < l) {
        cout << "no solution" << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 2*l; j >= w[i]; --j) {
            f[j] = min(f[j], f[j-w[i]] + v[i]);
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = l; i <= 2*l; ++i) {
        ans = min(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}
