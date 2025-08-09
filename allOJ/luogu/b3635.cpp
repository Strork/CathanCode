#include <bits/stdc++.h>
using namespace std;
int f[1000005];
int n;

int main() {
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (i >= 1) f[i] = min(f[i], f[i - 1]+1);
        if (i >= 5) f[i] = min(f[i], f[i - 5]+1);
        if (i >= 11) f[i] = min(f[i], f[i - 11]+1);
    }
    cout << f[n];
    return 0;
}