#include <bits/stdc++.h>
using namespace std;
int x, y, z, n, m;
int ans;

int main() {
    cin >> x >> y >> z >> n >> m;
    for (int gj = 0; gj <= m; ++gj) { 
        for (int mj = 0; mj+gj <= m; ++mj) {
            int xj = m - gj - mj;
            if (xj % z == 0 && gj*x + mj*y + xj/z == n) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}