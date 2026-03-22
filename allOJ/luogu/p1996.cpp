#include <bits/stdc++.h>
using namespace std;
int r[105];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i < n; ++i) r[i] = i + 1;
    r[n] = 1, r[0] = 1;
    int now = 0, last = -1;
    for (int j = 1; j <= m; ++j) {
        last = now;
        now = r[now];
    }
    cout << now << ' ';
    r[last] = r[now];
    return 0;
}