#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0) ++ans;
    }
    cout << ans << endl;
    return 0;
}