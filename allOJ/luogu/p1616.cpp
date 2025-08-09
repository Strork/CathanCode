#include <bits/stdc++.h>
#define ll long long
using namespace std;
int m, T;
ll f[10000005];


int main() {
    cin >> T >> m;
    for (int i = 1; i <= m; ++i) {
        ll a, b;
        cin >> a >> b;
        for (int j = a; j <= T; ++j) {
            f[j] = max(f[j-a] + b, f[j]);
        }
    }
    cout << f[T] << endl;
    return 0;
}