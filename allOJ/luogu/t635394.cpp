#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k;
int a[100005];
int s[100005];
unordered_map<int, int> pre;
int ans = -1;
int id;

int main() {
    cin >> n >> k;
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = (s[i-1] + a[i]) % k;
        if (pre.find(s[i]) != pre.end()) {
            if (i - pre[s[i]] + 1 >= ans) {
                ans = i - pre[s[i]] + 1;
                id = pre[s[i]];
            }
        } else {
            pre[s[i]] = i;
        }
    }
    if (ans == -1) cout << -1 << endl;
    else {
        cout << ans - 1 << endl;
        for (int i = id + 1; i <= id + ans - 1; ++i) cout << a[i] << ' ';
    }
    return 0;
}