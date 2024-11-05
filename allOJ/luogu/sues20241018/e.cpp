#include <bits/stdc++.h>
using namespace std;
int l, n, a[10000];

int main() {
    cin >> l;
    cin >> n;
    int maxx = 0, minn = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        int x = a[i] - 0;
        int y = l+1 - a[i];
        if (x > y) swap(x, y);
        minn = max(minn, x);
        maxx = max(maxx, y);
    }
    cout << minn << ' ' << maxx << endl;
    return 0;
}