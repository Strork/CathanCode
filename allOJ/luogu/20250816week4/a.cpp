#include <bits/stdc++.h>
using namespace std;
int a[130][55];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) a[s[j]][i]++;
        a['W'][i] += a['W'][i-1];
        a['B'][i] += a['B'][i-1];
        a['R'][i] += a['R'][i-1];
    }
    int ans = 1E9;
    for (int i = 1; i <= n - 2; ++i) {
        for (int j = i + 1; j <= n - 1; ++j) {
            int w = m * i - a['W'][i];
            int b = (j - i) * m - a['B'][j] + a['B'][i];
            int r = (n - j) * m - a['R'][n] + a['R'][j];
            ans = min(ans, w + b + r);
        }
    }
    cout << ans << endl;
    return 0;
}