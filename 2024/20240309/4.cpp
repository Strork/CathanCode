#include <bits/stdc++.h>
using namespace std;
int a[100010][6];
int sum[6];
int n, k;
int tm;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i][1]);
        tm = a[i][1];
        while ((tm & 1) == 0 && tm > 0) {
            a[i][2]++;
            tm = tm >> 1;
        }
        sum[2] += a[i][2];
        while (tm % 5 == 0 && tm > 0) {
            a[i][5]++;
            tm = tm / 5;
        }
        sum[5] += a[i][5];
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int s2 = sum[2];
        int s5 = sum[5];
        for (int j = i; j <= n; ++j) {
            s2 -= a[j][2];
            s5 -= a[j][5];
            int t = s2;
            if (s5 < s2) t = s5;
            if (t < k) break;
            ++ans;
        }
    }
    printf("%lld", ans);
}
// 64 位输出请用 printf("%lld")