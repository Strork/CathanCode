#include <bits/stdc++.h>
using namespace std;
int a[15];
int ans = 0;
bool f;

int main() {
    for (int i = 1; i <= 13; ++i) {
        int x;
        cin >> x;
        if (x == 0) ++ans;
        if (x >= 2) f = 1;
    }
    if (!f) ++ans;
    cout << ans << endl;
    return 0;
}