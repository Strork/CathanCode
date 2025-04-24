#include<bits/stdc++.h>
using namespace std;
int n;
int sum[100100];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        sum[i] = sum[i-1] + t;
    }
    int ans = 1234567890;
    for (int i = 1; i <= n; ++i) {
        int t = abs((sum[i]<<1) - sum[n]);
        if (t < ans) ans = t;
    }
    cout << ans << endl;
    return 0;
}
