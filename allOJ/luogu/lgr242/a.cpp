#include <bits/stdc++.h>
using namespace std;
int a[100005];
int n;

void pre() {
    for (int i = 2; i <= 100001; ++i) {
        a[i] = i * (i - 1) >> 1;
        if (a[i] > 1e9) {
            n = i - 1;
            break;
        }
    }
}

int main() {
    int T;
    cin >> T;
    pre();
    while (T--) {
        int m;
        cin >> m;
        int l = lower_bound(a + 1, a + 1 + n, m) - a;
        int r = (m - 1) * 2;
        if (l <= r) cout << l << ' ' << r << endl;
        else cout << "Lose!" << endl;
    }
    return 0;
}