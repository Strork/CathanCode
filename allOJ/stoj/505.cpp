#include <bits/stdc++.h>
using namespace std;
int c[15];
int amout, n;
int f[10005];

int main() {
    memset(f, 10, sizeof(f));
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    cin >> amout;
    f[0] = 0;
    for (int i = 1; i <= amout; ++i) {
        for (int j = 1; j <= n; ++j) {
            int money = i - c[j];
            if (money < 0) continue;
            f[i] = min(f[i], f[money] + 1);
        }
    }
    if (f[amout] != f[10001]) cout << f[amout] << endl;
    else cout << -1 << endl;
    return 0;
}