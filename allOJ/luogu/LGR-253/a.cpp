#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll x;
        cin >> x;
        int ans = sqrt(x / 9);
        cout << ans << endl;
    }
    return 0;
}