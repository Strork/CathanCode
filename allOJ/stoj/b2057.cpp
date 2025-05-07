#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int t;
        cin >> t;
        if (t > ans) ans = t;
    }
    cout << ans << endl;
    return 0;
}
