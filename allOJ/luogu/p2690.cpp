#include <bits/stdc++.h>
using namespace std;
int t, w;
int f[1005][33][5];
int a[1005], cp[5];

int dfs(int x, int swp, int pos) {
    if (x <= 0) return 0;
    if (swp < 0) return f[x][0][cp[pos]];
    if (f[x][swp][pos]) return f[x][swp][pos];
    if (a[x] == pos)
        f[x][swp][pos] =
            max(dfs(x - 1, swp, pos), dfs(x - 1, swp - 1, cp[pos])) + 1;
    else
        f[x][swp][pos] =
            max(dfs(x - 1, swp, pos), dfs(x - 1, swp - 1, cp[pos]));
    return f[x][swp][pos];
}

int main() {
    cin >> t >> w;
    for (int i = 1; i <= t; ++i) cin >> a[i];
    cp[1] = 2, cp[2] = 1;
    dfs(t, w, 1);
    dfs(t, w, 2);
    int ans = 0;
    for (int i = 0; i <= w; ++i) {
        ans = max({f[t][i][1], f[t][i][2], ans});
    }
    cout << ans << endl;
    return 0;
}