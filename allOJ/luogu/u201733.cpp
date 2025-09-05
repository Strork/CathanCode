#include <bits/stdc++.h>
using namespace std;
int money[10005];
int rd[10005];
int n, m, cnt;
vector<int> a[10005];
stack<int> s;

void topSort() {
    while (s.size()) {
        int x = s.top();
        s.pop();
        for (auto y : a[x]) {
            --rd[y];
            money[y] = max(money[y], money[x] + 1);
            if (rd[y] == 0) {
                ++cnt;
                s.push(y);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a[y].push_back(x);
        ++rd[x];
    }
    for (int i = 1; i <= n; ++i) {
        if (rd[i] == 0) s.push(i), ++cnt;
        money[i] = 100;
    }
    topSort();
    if (cnt != n) cout << "Poor Xed" << endl;
    else {
        int ans = 0;
        for (int i = 1; i <= n; ++i) ans += money[i];
        cout << ans << endl;
    }
    return 0;
}