#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("math.in", "r", stdin);
    // freopen("math.out", "w", stdout);
int T; cin >> T; while (T--) {
    int a, b;
    cin >> a >> b;
    int t = b - a;
    if (t == 0) puts("0");
    else if ((t > 0 && (t & 1)) || t < 0 && !(t & 1)) puts("1");
    else if (t < 0 && (t & 1)) puts("2");
    else {
        if (t % 4 == 0) puts("3");
        else puts("2");
    }
}
    return 0;
}