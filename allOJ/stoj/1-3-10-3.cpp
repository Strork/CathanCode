#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    int zfx = 0;
    int cfx = 0;
    for (int i = 0; i <= n; ++i) { // x1
        for (int j = 0; j <= m; ++j) { // y1
            for (int x = i+1; x <= n; ++x) { // x2
                for (int y = j+1; y <= m; ++y) { // y2
                    if (x-i == y-j) ++zfx;
                    else ++cfx;
                }
            }
        }
    }
    cout << zfx << ' ' << cfx << endl;
    return 0;
}