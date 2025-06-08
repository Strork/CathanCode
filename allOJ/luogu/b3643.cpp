#include <bits/stdc++.h>
using namespace std;
bool a[1005][1005];
vector<int> b[1005];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
        b[x].push_back(y);
        b[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 1; i <= n; ++i) {
        cout << b[i].size() << ' ';
        sort(b[i].begin(), b[i].end());
        for (auto j : b[i]) cout << j << ' ';
        cout << endl;
    }
    return 0;
}