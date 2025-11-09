#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[100005];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= q; ++i) {
        int x;
        cin >> x;
        int l = lower_bound(a + 1, a + 1 + n, x) - a;
        if (a[l] != x) {
            printf("-1 -1\n");
            continue;
        }
        int r = upper_bound(a + 1, a + 1 + n, x) - a;
        printf("%d %d\n", l - 1, r - 2);
    }
    return 0;
}