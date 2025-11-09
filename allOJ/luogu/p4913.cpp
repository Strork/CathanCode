#include <bits/stdc++.h>
using namespace std;
int l[1000005], r[1000005];
int n;

int dfs(int x) {
    if (!x) return 0;
    return 1 + max(dfs(l[x]), dfs(r[x]));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
    }
    cout << dfs(1) << endl;
    return 0;
}