#include <bits/stdc++.h>
using namespace std;
int v, n, c;
int f[10005];

int main() {
    cin >> v >> n >> c;
    for (int i = 1; i <= n; ++i) {
        int need, got;
        cin >> got >> need;
        for (int j = c; j >= need; --j) {
            f[j] = max(f[j], f[j - need] + got);
        }
    }
    bool flag = 0;
    for (int i = 0; i <= c; ++i) {
        if (f[i] >= v) {
            cout << c - i << endl;
            flag = 1;
            break;
        }
    }
    if (!flag) cout << "Impossible" << endl;
    return 0;
}