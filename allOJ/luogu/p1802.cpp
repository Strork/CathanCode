#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1005];
ll win[1005], lose[1005], w[1005];
int n, e;

void pre() {
    cin >> n >> e;
    for (int i = 1; i <= n; ++i) {
        cin >> lose[i] >> win[i] >> w[i];
        if (w[i] == 0) dp[0] += win[i];
        else dp[0] += lose[i];
    }
    for (int i = 1; i <= e; ++i) dp[i] = dp[i - 1];
}

int main() {
    pre();
    for (int i = 1; i <= n; ++i) {
        if (w[i] == 0) continue;
        for (int j = e; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + win[i] - lose[i]);
        }
    }
    cout << dp[e] * 5LL << endl;
    return 0;
}