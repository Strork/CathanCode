#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];

void solution40() {
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            int t = a[i] + a[j];
            if ((t & (t-1)) == 0) ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    freopen("1.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (n <= 100000) solution40();
    return 0;
}