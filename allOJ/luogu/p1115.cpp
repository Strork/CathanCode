#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int f[N], ans = -1234512345;
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
        f[i] = max(f[i], f[i - 1] + f[i]);
        ans = max(f[i], ans);
    }
    cout << ans << endl;
    return 0;
}