#include<bits/stdc++.h>
using namespace std;
int n, ans;

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int k = n - i - j;
            if (i + j <= k) continue;
            if (k < j) break;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}