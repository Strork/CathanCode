#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int n;

int main() {
    a[0] = -1;
    int T; cin >> T; while (T--) {
        cin >> n;
        int cnt = -1;
        bool ans = 1;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] > a[i - 1]) cnt++;
            if (a[i] - cnt <= 0) ans = 0;
        }
        if (ans) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}