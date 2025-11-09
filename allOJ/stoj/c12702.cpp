#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1000005];
int s[1000005];

int main() {
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        int left = 0;
        if (i - k > 0) left = i - k;
        if (s[i] - s[left - 1] > ans) ans = s[i] - s[left - 1];
    }
    cout << ans << endl;
    return 0;
}