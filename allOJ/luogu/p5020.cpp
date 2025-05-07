#include<bits/stdc++.h>
using namespace std;
int n;
int a[105];
int f[25005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        int m = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] > m) m = a[i];
        }
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = a[i]; j <= m; ++j) {
                f[j] += f[j - a[i]];
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (f[a[i]] == 1) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
