#include <bits/stdc++.h>
using namespace std;
int a[5000], cnt[10];

void mul(int n, int m) {
    a[1] = 1, a[0] = 1; // a = 1
    for (int i = 2; i <= n; ++i) {
        int x = 0;
        for (int j = 1; j <= a[0]; ++j) {
            a[j] = a[j] * i + x; // 每一位 * i
            x = a[j] / 10; // 留下来余数的给之后的影响
            a[j] %= 10; // 这一位
        }
        while (x) { // 最后剩下的余数
            a[++a[0]] = x % 10;
            x /= 10;
        }
    }
    int cnt = 0;
    for (int i = a[0]; i >= 1; --i) {
        if (a[i] == m) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    int T; cin >> T; while (T--) {
        int n, m; cin >> n >> m;
        mul(n, m);
    }
    return 0;
}