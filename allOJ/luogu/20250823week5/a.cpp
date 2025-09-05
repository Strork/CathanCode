#include <bits/stdc++.h>
using namespace std;
int cnt[257][2], ans;

int main() {
    string a[2];
    cin >> a[0] >> a[1];
    for (int i = 0; i < 2; ++i) {
        for (auto c : a[i]) {
            cnt[c][i]++;
        }
    }
    for (int i = 'a'; i <= 'z'; ++i) ans += min(cnt[i][0], cnt[i][1]);
    cout << ans << endl;
    return 0;
}