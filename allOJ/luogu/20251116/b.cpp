#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool flag = 1;
int n, m;
int a[405][405];
struct dp {
    int x, y, v;
}f[405][405];

void solution3() {
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum += a[i][j];
        }
    }
    cout << sum * min(n, m) << endl;
}

ll s[405][405];
void solution2() {
    ll ans = -123123123123123LL;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
            for (int x = i; x >= 1; --x) {
                for (int y = j; y >= 1; --y) {
                    ll t = s[i][j] - s[i][y-1] - s[x-1][j] + s[x-1][y-1];
                    ans = max(t * min(i - x + 1, j - y + 1), ans);
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] < 0) flag = 0;
        }
    }
    if (flag) solution3();
    if (n <= 100 && m <= 100) solution2();
    return 0;
}