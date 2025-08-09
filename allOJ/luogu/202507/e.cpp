#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1005];

int main() {
    cin >> n >> k;
    for (int i = 0; i <= k; ++i) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            cout << 1 << endl;
            continue;
        }
        if (x > y) swap(x, y);
        int i = lower_bound(a, a+k, x) - a;
        int j = lower_bound(a, a+k, y) - a;
        if (i == j || i+1 == j && a[i] == x) cout << 2 << endl;
        else {
            if (y+1 != a[j]) --j;
            int m = j-i+1;
            cout << 2+m << endl;
        }
    }
    return 0;
}