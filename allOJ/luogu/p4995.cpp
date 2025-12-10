#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, ans;
int a[500];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int j = n, i = 1, k = 0;
    while (i <= j) {
        if (i <= j) ans += pow(a[j] - a[k], 2), k = j--; // 跳到高的石头
        if (i <= j) ans += pow(a[k] - a[i], 2), k = i++; // 跳到矮的石头
    }
    cout << ans << endl;
    return 0;
}