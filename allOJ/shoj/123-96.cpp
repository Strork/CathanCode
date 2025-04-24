#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int f[100010][3];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    f[1][1] = a[1];
    f[1][2] = a[1] << 1;
    for (int i = 2; i <= n; ++i) {
        f[i][0] = max(f[i][0], f[i-1][2]);
        f[i][1] = max(f[i-1][1], f[i-1][0]) + a[i];
        f[i][2] = max(f[i-1][1], f[i-1][0]) + (a[i]<<1);
    }
    cout << max(f[n][0], max(f[n][1], f[n][2])) << endl;
    return 0;
}
