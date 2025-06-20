#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[505];
int f[505][505]; // 前面i个人，取j本书的最短时间   求min值

int main() {
    memset(f, 10, sizeof(f));
    cin >> n >> m;
    f[1][0] = 0;
    for (int i = 1; i <= n; ++i) f[1][i] = a[i] + f[1][i-1];
    for (int i = 2; i <= n; ++i) {
        for (int j = i; ++i) {
            
        }
    }
    return 0;
}