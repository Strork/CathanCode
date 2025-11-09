#include <bits/stdc++.h>
using namespace std;
int a, b, k;

int main() {
    int ans = 0;
    cin >> a >> b >> k;
    while (a < b) {
        int c = a + k;
        int d = a * k;
        a = max(c, d);
        ++ans;
    }
    cout << ans << endl;
    return 0;
}