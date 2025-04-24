#include <bits/stdc++.h>
using namespace std;

int main() {
    int L;
    cin >> L;
    int ans = 0;
    for (int i = 1; i < L; ++i) {
        for (int j = i; j <= L; ++j) {
            int k = L - i - j;
            if (k < j) break;
            if (k == i && k == j) break;
            if (i + j <= k) continue;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}