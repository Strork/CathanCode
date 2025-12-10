#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[20];

bool dfs(int dep) {
    int h = getH();
    if (dep + h > ans) return false;
    if (!h) return true;
    for (int len = 1; len < n; ++len) {
        for (int l = 1; l <= n; ++l) {
            int r = l + len - 1;
            if (r > n) break;
            for (int k = r + 1; k <= n; ++k) {
                
            }
        }
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int ans = 1;
        while (ans < 5 && !dfs(1)) ans++;
        if (ans >= 5) cout << "5 or more" << endl;
        else cout << ans << endl;
    }
    return 0;
}