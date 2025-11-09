#include <bits/stdc++.h>
using namespace std;
int s[500005];
int pre[1<<22];
int n, k, ans;

int main() {
    memset(pre, -1, sizeof(pre));
    pre[0] = 0;
    cin >> n >> k;
    int st = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] ^= s[i - 1];
        int x = s[i] ^ k; // 求 s[r] ^ k == s[l - 1]
        if (pre[x] >= st) ans++, st = i;
        pre[s[i]] = i; // s[l - 1] 出现的最晚位置
    }
    cout << ans << endl;
    return 0;
}