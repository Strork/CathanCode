#include <bits/stdc++.h>
using namespace std;
int n, m;

struct mat {
    int c[35][35];
    mat operator*(const mat& b) const {
        mat t;
        for (int i = 0; i <= n; ++i) {  // 0 号表示爆炸
            for (int j = 0; j <= n; ++j) {
                t.c[i][j] = 0;
                for (int k = 0; k <= n; ++k) {
                    t.c[i][j] += c[i][k] * b.c[k][j];
                }
                t.c[i][j] %= 2017;
            }
        }
        return t;
    }
} st, a;

void fstp(int y) {
    while (y) {
        if (y & 1) st = st * a;
        a = a * a;
        y >>= 1;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a.c[x][y] = a.c[y][x] = 1;
    }
    for (int i = 0; i <= n; ++i) a.c[i][i] = a.c[i][0] = st.c[i][i] = 1;
    int t;
    cin >> t;
    fstp(t);
    int sum = 0;
    for (int i = 0; i <= n; ++i) (sum += st.c[1][i]) %= 2017;
    cout << sum << endl;
    return 0;
}