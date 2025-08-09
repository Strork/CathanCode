#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        int cnt = 0;
        int ans = 0;
        while (x) {
            if (x % 2) cnt += 1;
            else cnt = 0;
            if (cnt > ans) ans = cnt;
            x = x / 2;
        }
        cout << ans << endl;
    }
    return 0;
}