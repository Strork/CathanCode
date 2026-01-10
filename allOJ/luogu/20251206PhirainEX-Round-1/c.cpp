#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[1005][1005];

void dfs(int x, int y) {
    c[x][y] = '.';
    if (c[x + 1][y - 1] == '#')
        dfs(x + 1, y - 1);
    else if (c[x + 1][y + 1] == '#')
        dfs(x + 1, y + 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) cin >> c[i][j];
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (c[i][j] == '#') dfs(i, j), ++ans;
        printf("%d %d\n", ans, 0);
    }
    return 0;
}