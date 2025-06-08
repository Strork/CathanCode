#include <bits/stdc++.h>
using namespace std;
int ans[1050];
int fa[1050];
int n;

int main() {
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        cin >> fa[i];
    }
    for (int i = n; i >= 1; --i) {
        ++ans[i];
        ans[fa[i]] += ans[i];
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}