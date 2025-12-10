#include <bits/stdc++.h>
using namespace std;
int n, ans;

int main() {
    cin >> n;
    ans += n - 1;
    cout << ans << endl;
    for (int i = 1; i < n; ++i) {
        if (i & 1) {
            cout << i << ' ' << n << endl;
        }
        else {
            cout << n << ' ' << i << endl;
        }
    }
    return 0;
}