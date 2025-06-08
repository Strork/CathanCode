#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105][105];
int sum;

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int j = 1; j <= n; ++j) {
        sum += a[1][j];
        sum += a[m][j];
    }
    for (int i = 1; i <= m; ++i) {
        sum += a[i][1];
        sum += a[i][n];
    }
    sum -= a[1][1];
    sum -= a[1][n];
    sum -= a[m][1];
    sum -= a[m][n];
    if (m == 1 && n == 1) cout << a[1][1];
    else if (m == 1) cout << a[1][1] + a[1][n];
    else if (n == 1) cout << a[1][1] + a[m][1];
    else cout << sum;
    return 0;
}