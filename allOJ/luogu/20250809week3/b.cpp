#include <bits/stdc++.h>
using namespace std;
int p[205], l;
bool f[205];
int dp[2005];

void ola() {
    memset(f, 1, sizeof(f));
    f[0] = f[1] = 0;
    for (int i = 2; i <= 200; ++i) {
        if (f[i]) p[++l] = i;
        for (int j = 1; j <= l && p[j] * i <= 200; ++j) {
            f[i * p[j]] = 0;
            if (i % p[j] == 0) break;
        }
    }
}

void pack() {
    dp[0] = 1;
    for (int i = 1; i <= l; ++i) {
        for (int j = p[i]; j <= 200; ++j) {
            dp[j] += dp[j - p[i]];
        }
    }
}

int main() {
    ola();
    int n;
    pack();
    while (cin >> n) {
        cout << dp[n] << endl;
    }
    return 0;
}