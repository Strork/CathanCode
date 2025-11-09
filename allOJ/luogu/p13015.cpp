#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005];
int f[1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) { // i 是枚举物品，同时也是物品重量
        for (int j = i; j <= n; ++j) { // j 是枚举背包容量
            f[j] = max(f[j - i] + a[i], f[j]); // a[i]即：第 i 个物品的价值
        }
    }
    cout << f[n] << endl; 
    return 0;
}