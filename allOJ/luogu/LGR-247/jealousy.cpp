#include <bits/stdc++.h>
using namespace std;
int n, y, s, t;
bool f[100005];

int main() {
    // freopen("jealousy4.in", "r", stdin);
    cin >> n >> y >> s >> t;
    for (int i = y; i <= 400; i += t) f[i] = 1;
    bool ok = 0;
    for (int i = 1; i <= n; ++i) {
        int st = (i - 1) * s;
        int ed = i * s;
        if (f[st] || f[ed]) continue;
        ok = 1;
        break;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}