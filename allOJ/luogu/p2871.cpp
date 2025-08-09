#include <bits/stdc++.h>
using namespace std;
int n, m;
int w[3500], v[3500];
int f[13000];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= w[i]; --j) {
            f[j] = max(f[j-w[i]] + v[i], f[j]);
        }
    }
    cout << f[m] << endl;
    return 0;
}