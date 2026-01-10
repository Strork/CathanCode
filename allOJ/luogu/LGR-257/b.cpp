#include <bits/stdc++.h>
using namespace std;
int cnt[133];
int ans;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        int n, a, b, c;
        ans = cnt['5'] = cnt['2'] = cnt['0'] = 0;
        cin >> n >> a >> b >> c >> s;
        for (int i = 0; i < n; ++i) {
            if (i < n - 2 && s[i] == '5' && s[i + 1] == '2' && s[i + 2] == '0')
                ++ans, i += 2;
            else if (i < n - 1 && s[i] == '5' && s[i + 1] == '2' && c)
                --c, ++ans, ++i;
            else if (i < n - 1 && s[i] == '5' && s[i + 1] == '0' && b)
                --b, ++ans, ++i;
            else if (i < n - 1 && s[i] == '2' && s[i + 1] == '0' && a)
                --a, ++ans, ++i;
            else
                ++cnt[s[i]];
        }
        for (int j = 1; j <= n; ++j) {
            bool f = 0;
            if (a <= b && a <= c && cnt['5'] && b && c)
                --b, --c, --cnt['5'], ++ans, f = 1;
            else if (b <= a && b <= c && cnt['2'] && a && c)
                --a, --c, --cnt['2'], ++ans, f = 1;
            else if (c <= a && c <= b && cnt['0'] && a && b)
                --a, --b, --cnt['0'], ++ans, f = 1;
            if (!f) break;  // 一次也不执行
        }
        ans += min(a, min(b, c));
        cout << ans << endl;
    }
    return 0;
}