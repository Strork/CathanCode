#include <bits/stdc++.h>
using namespace std;
bool yx[30], y[30], xy[30];
int n;
int ans[15];
int cnt;

void dfs(int s) {
    if (s == n+1) {
        ++cnt;
        if (cnt <= 3) {
            for (int i = 1; i <= n; ++i) {
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; ++i) { // 枚举列
        if (!y[i] && !xy[s+i] && !yx[s-i+n]) {
            y[i] = 1;
            xy[s+i] = 1;
            yx[s-i+n] = 1;
            ans[s] = i;
            dfs(s+1);
            y[i] = 0;
            xy[s+i] = 0;
            yx[s-i+n] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    cout << cnt << endl;
    return 0;
}