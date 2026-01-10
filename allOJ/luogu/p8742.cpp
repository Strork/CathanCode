#include <bits/stdc++.h>
using namespace std;
bool f[1000005];
int n;
int ans = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        for (int j = 100000; j >= 1; --j) {
            int l = abs(j - x);
            bool fst = f[j];
            if (f[l]) f[j] = 1;
            int r = j + x;
            if (f[r]) f[j] = 1;
            if (!fst && f[j]) ans++;
        }
        if (!f[x]) ans++;
        f[x] = 1;
    }
    cout << ans;
    return 0;
}