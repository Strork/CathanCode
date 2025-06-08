#include <bits/stdc++.h>
using namespace std;
int n, m;
int dif[100100];
int tra[100100];
int A[100100], B[100100], C[100100];
long long sum = 0;

int main() {
    //freopen("P3406_8.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &tra[i]);
        if (i >= 2) {
            int x = tra[i-1], y = tra[i];
            if (x > y) swap(x, y);
            ++dif[x];
            --dif[y];
        }
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
        dif[i] += dif[i-1]; // 下面使用1LL乘以数强制转换成long long
        sum += min(1LL*A[i] * dif[i], 1LL*B[i] * dif[i] + C[i]);
    }
    cout << sum << endl; // 注意sum定义的时候也是 long long
    return 0;
}