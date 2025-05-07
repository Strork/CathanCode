#include <bits/stdc++.h>
using namespace std;
int n;
int a[105];
int m;
int cnt;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == m) ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
