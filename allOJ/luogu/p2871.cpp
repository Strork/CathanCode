#include <bits/stdc++.h>
using namespace std;
int n, V;
int v[230];
int dp[23330];
void so() {
    for (int i = 1; i <= n; ++i) { // 枚举每个物品 i
        for (int j = V; j >= v[i]; --j) { // 我付出 j，能得到的就是收获 f[i][j]
            if (dp[j - v[i]] + v[i] > dp[j]) dp[j] = dp[j - v[i]] + v[i];
        }
    }
}

int main() {
    cin >> V >> n;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    so();
    cout << V - dp[V] << endl;
    return 0;
}