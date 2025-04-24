#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];
int f[100100][2];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        f[i][0] = max(f[i-1][1], f[i-1][0]);
        f[i][1] = f[i-1][0] + a[i];
    }
    cout << max(f[n][0], f[n][1]) << endl;
    return 0;
}
