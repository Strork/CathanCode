#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int n, x;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> x;
    cout << lower_bound(a + 1, a + 1 + n, x) - a;
    return 0;
}