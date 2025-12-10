#include <bits/stdc++.h>
using namespace std;
int n, s[10005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> s[i];
            s[i] += s[i - 1];
        }
        bool ok = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[n] - s[i]) {
                ok = 1;
                break;
            }
        }
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}