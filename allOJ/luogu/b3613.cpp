#include <bits/stdc++.h>
using namespace std;
vector<int> a[100005];
int q;

int main() {
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int opt; cin >> opt;
        if (opt == 1) {
            int x, y, z;
            cin >> x >> y >> z;
            if(y > a[x][0]) a[x].resize(y + 5);
            a[x][y] = z;
        }
    }
    return 0;
}