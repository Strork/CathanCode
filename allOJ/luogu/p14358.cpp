#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i) cin >> a[i];
    int r = a[1];
    sort(a + 1, a + 1 + n * m, greater<int>());
    int rank = 1;
    while (rank <= n * m) {
        if (a[rank] == r) break;
        rank++;
    }
    int x = rank / n;
    if (rank % n) x++;
    int y;
    if (x & 1) {
        y = rank % n;
        if (y == 0) y = n;
    } else {
        y = n - rank % n + 1;
        if (y == n + 1) y = 1;
    }
    cout << x << ' ' << y << endl;
    return 0;
}