#include <bits/stdc++.h>
using namespace std;
int n;
int a[10005];
int f[10005];
int sum_out[10005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 5000; j >= a[i]; --j) {
            f[j] += f[j - a[i]]; // 凑出f[j]的方案数
        }
        for (int j = )
    }
    return 0;
}