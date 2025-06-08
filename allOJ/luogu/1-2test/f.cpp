#include <bits/stdc++.h>
using namespace std;
int n, k;

int main() {
    int ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + k) % i;
    }
    cout << ans + 1 << endl;
    return 0;
}