#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[100005];
int n, t;
int ans;

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) scanf("%d", &s[i]), s[i] += s[i - 1];
    for (int i = 1; i <= n; ++i) {
        int id = upper_bound(s + 1, s + 1 + n, t) - s;
        id--;
        // cout << i << ": " << id << endl;
        ans = max(ans, id - i + 1);
        t += s[i] - s[i - 1];
    }
    cout << ans << endl;
    return 0;
}