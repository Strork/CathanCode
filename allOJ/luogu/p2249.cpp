#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i) {
        int x;
        scanf("%d", &x);
        int id = lower_bound(a + 1, a + n + 1, x) - a; // a == &a[0]
        if (a[id] == x) printf("%d ", id);
        else printf("-1 ");
    }
    return 0;
}