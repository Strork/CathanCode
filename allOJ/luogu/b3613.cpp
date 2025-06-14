#include <bits/stdc++.h>
using namespace std;
vector<int> a[500100];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
        }
        for (int i = 1; i <= n; ++i) {
            sort(a[i].begin(), a[i].end());
            for (int j = 0; j < a[i].size(); ++j) {
                cout << a[i][j] << ' ';
            }
            a[i].clear();
            cout << endl;
        }
    }
    return 0;
}