#include <bits/stdc++.h>
using namespace std;
int n, k;

int main() {
    cin >> n >> k;
    int ans = 0;
    for (int st = 1;; ++st) {
        bool f = 1;
        ans = st * n + k;
        for (int i = 2; i <= n; ++i) {
            if (ans % (n-1) != 0) {
                f = 0;
                break;
            }
            ans = ans * n / (n-1) + k;
        }
        if (f) break;
    }
    cout << ans << endl;
    return 0;
}