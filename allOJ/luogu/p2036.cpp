#include <bits/stdc++.h>
using namespace std;
int n;
int s[15];
int b[15];
int ans = 2034567891;

void dfs(int x, int sd, int kd, int cnt) {
    if (x >= n+1) {
        if (cnt >= 1) ans = min(ans, abs(sd-kd));
        return;
    }
    dfs(x+1, sd*s[x], kd+b[x], cnt+1);
    dfs(x+1, sd, kd, cnt);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] >> b[i];
    }
    dfs(1, 1, 0, 0);
    cout << ans << endl;
    return 0;
}
