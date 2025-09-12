#include <bits/stdc++.h>
using namespace std;
long long dp[1050];
long long ti[100010], ci[100010];
int tree, n;

int main() {
    long long T, a, b, c, d;
    scanf("%lld:%lld %lld:%lld", &a, &b, &c, &d);
    T = (c - a) * 60 + d - b;
    cin >> tree;
    for (int i = 1; i <= tree; ++i) {
        cin >> a >> b >> c; // 时间 美学 棵树
        if (c == 0) {
            for (int j = a; j <= T; ++j) dp[j] = max(dp[j], dp[j - a] + b); // 完全背包
        } else {
            d = 1;
            while (d <= c) {
                ++n;
                ti[n] = d * a;
                ci[n] = d * b;
                d *= 2;
                c -= d;
            } 
            if (c > 0) {
                ++n;
                ti[n] = c * a;
                ci[n] = c * b;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = T; j >= ti[i]; --j) {
            dp[j] = max(dp[j], dp[j - ti[i]] + ci[i]);
        }
    }
    cout << dp[T] << endl;
    return 0;
}
