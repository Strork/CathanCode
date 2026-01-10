#include <bits/stdc++.h>
using namespace std;
int f[3][1<<11][1<<11];
int grass[105];
int c[1<<11];
int n, m, state;
int sta[1<<11];

void pre() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char x; cin >> x;
            if (x == 'P') grass[i] |= (1 << (j - 1));
        }
    }
    sta[++state] = 0;
    for (int i = 0; i < (1 << m); ++i) {
        if (i & (i << 1)) continue;
        if (i & (i << 2)) continue;
        if (i & (i >> 1)) continue;
        if (i & (i >> 2)) continue;
        sta[++state] = i;
        int t = i;
        while (t) {
            c[state]++;
            t = t & (t - 1);
        }
    }
    for (int i = 1; i <= state; ++i) {
        if (sta[i] & grass[0] != sta[i])
        f[0][i][0] = c[i];
    }
    for (int i = 1; i <= state; ++i) {
        if ((sta[i] & grass[1]) != sta[i]) continue;
        for (int j = 1; j <= state; ++j) { // 枚举上一行
            if (sta[i] & sta[j]) continue;
            if ((j & grass[0]) != j) continue;
            f[1][i][j] = c[j] + c[i];
        }
    }
}

int main() {
    pre();
    for (int i = 2; i < n; ++i) {
        int z = i % 3;
        int y = (i - 1) % 3;
        for (int j = 1; j <= state; ++j) { // 当前行
            if ((sta[j] & grass[i]) != sta[j]) continue;
            for (int k = 1; k <= state; ++k) { // 上一行
                if (sta[j] & sta[k]) continue; // i 和 i - 1 冲突
                if (sta[k] & grass[i - 1]) continue; // 草地不要冲突
                for (int l = 1; l <= state; ++l) { // 上两行 
                    if (sta[k] & sta[l]) continue;
                    if (sta[j] & sta[l]) continue;
                    if (sta[l] & grass[i - 2]) continue;
                    f[z][j][k] = max(f[z][j][k], f[y][k][l] + c[j]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= state; ++i) {
        for (int j = 1; j <= state; ++j) {
            ans = max(ans, f[(n - 1) % 3][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}