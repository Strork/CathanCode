#include <bits/stdc++.h>
using namespace std;
int n;
bool f[3][1000];
char a[12][12];

void dfs(int x) {
    if (x > n) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << a[i][j];
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int y = 1; y <= n; ++y) {
        if (f[0][y] || f[1][y - x + n] || f[2][x + y]) continue;
        f[0][y] = f[1][y - x + n] = f[2][x + y] = 1;
        a[x][y] = 'Q';
        dfs(x + 1);
        a[x][y] = '.';
        f[0][y] = f[1][y - x + n] = f[2][x + y] = 0;
    }
}

int main() {
    cin >> n;
    memset(a, '.', sizeof(a));
    dfs(1);
    return 0;
}