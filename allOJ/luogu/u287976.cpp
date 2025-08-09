#include <bits/stdc++.h>
using namespace std;
int f[205];
int v[1000005];
int w[1000005];
int m, n;

int main() {
    int kd;
    cin >> m >> kd;
    for (int i = 1; i <= kd; ++i) {
        int wi, ci, pi;
        cin >> wi >> ci >> pi;
        if (pi == 0) {
            for (int j = wi; j <= m; ++j) {
                f[j] = max(f[j], f[j - wi] + ci);
            }
        } else {
            int t = 1;
            while (t <= pi) {
                ++n;
                w[n] = wi * t;
                v[n] = ci * t;
                pi -= t;
                t *= 2;
            }
            if (pi > 0) {
                ++n;
                w[n] = wi * pi;
                v[n] = ci * pi;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= w[i]; --j) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}