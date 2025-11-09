#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll id[55][55];
int dis[55][55];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> id[i][j];
            for (int x = 1; x <= i; ++x) {
                for (int y = 1; y <= m; ++y) {
                    if (x == i && y == m) break;
                    if (id[x][y] == id[i][j]) {
                        int t = (i - x) * (i - x) + (j - y) * (j - y);
                        dis[x][y] = max(dis[x][y], t);
                        dis[i][j] = max(dis[i][j], t);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1;  j <= m; ++j) {
            cout << dis[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}