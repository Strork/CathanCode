#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[100010][2], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> f[i][0];
    for (int i = 1; i <= n; ++i) cin >> f[i][1];
    f[2][0] += f[1][0], f[2][1] += f[1][1];
    for (int i = 3; i <= n; ++i) {
        f[i][0] += max(f[i-1][0], f[i-2][1]);
        f[i][1] += max(f[i-1][1], f[i-2][0]);
    }
    cout << max(f[n][0], f[n][1]) << endl;
    return 0;
}