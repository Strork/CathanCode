#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e5 + 5;
int a[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        if (s[1] == 'o') a[x] = y;
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    return 0;
}