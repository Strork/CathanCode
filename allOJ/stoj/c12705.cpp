#include <bits/stdc++.h>
using namespace std;
int n, k, a[20004];
int s[20005];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int cnt = 0;
    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            if (s[r] - s[l - 1] == k) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}