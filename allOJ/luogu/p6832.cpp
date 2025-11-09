#include <bits/stdc++.h>
using namespace std;
int cnt[130];

int main() {
    string s; cin >> s;
    int ans = 0;
    for (auto x : s) cnt[x]++, ans = max(cnt[x], ans);
    cout << ans << endl;
    return 0;
}
