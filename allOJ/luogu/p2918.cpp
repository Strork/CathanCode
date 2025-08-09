#include <bits/stdc++.h>
using namespace std;
int f[55005];
int n, h;

int main() {
    cin >> n >> h;
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int w, v;
        cin >> w >> v;
        for (int j = w; j <= h + 5001; ++j) {
            f[j] = min(f[j], f[j - w] + v);
        }
    }
    int ans = 1000000;
    for (int i = h; i <= h + 5001; ++i) {
        ans = min(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}