#include <bits/stdc++.h>
using namespace std;
int h, t, n;
int v, w, kal;
int f[405][405];

int main() {
    cin >> h >> t >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v >> w >> kal;
        for (int j = h; j >= v; --j) {
            for (int k = t; k >= w; --k) {
                f[j][k] = max(f[j][k], f[j-v][k-w] + kal);
            }
        }
    }
    cout << f[h][t] << endl;
    return 0;
}