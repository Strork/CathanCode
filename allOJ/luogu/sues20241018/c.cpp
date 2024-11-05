#include <bits/stdc++.h>
using namespace std;
int a[11], b;

int main() {
    for (int i = 1; i <= 10; ++i) cin >> a[i];
    cin >> b;
    int ans = 0;
    for (int i = 1; i <= 10; ++i) {
        if (b+30 >= a[i]) ++ans;
    }
    cout << ans << ' ' << endl;
    return 0;
}