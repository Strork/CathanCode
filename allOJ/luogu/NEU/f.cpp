#include <bits/stdc++.h>
using namespace std;
int n, m;
int sell[105];
int buy[105];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> buy[i];
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            int t;
            cin >> t;
            sell[i] = max(sell[i], t);
        }
    }
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
        if (sell[i] > buy[i]) sum += sell[i] - buy[i];
    cout << sum << endl;
    return 0;
}