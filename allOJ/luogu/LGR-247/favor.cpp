#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans, sum;

// 1011100
// 0111011
// 1111011
// 策略：最左边不一样，就翻最右边// 否则就是翻最左边
// r = string.size() - 1; 
// while (s[r] == '1') r--; 每次就找到最右边的 0
// l = 0

high[100000];
int dfs(int x) {
    if (!x) return 0;
    int l = dfs(x * 2);
    int r = dfs(x * 2 + 1);
    return high[x] = max(l, r);
}


int main() {
    // freopen("favor.in", "r", stdin);
    int T; cin >> T; while (T--) {
        int n;
        cin >> n;
        string s, base_s;
        cin >> base_s;
        // 1 变 0
        s = base_s;
        sum = 0;
        int r = s.size() - 1;
        while (r >= 0 && s[r] == '0') --r;
        int l = 0; // 01010
        while (l < r) {
            if (s[l] == '1') { // 翻最左侧的;
                s[l] = '0';
                ++sum;
            }
            while (r > l && s[r] == '0') --r;
            if (l == r) break;
            s[r] = '0';
            sum += r - l + 1; // 翻最右侧的
            ++l;
        }
        if (s[r] == '1') ++sum;
        ans = sum;
        // 0 to 1
        s = base_s;
        sum = 0;
        r = s.size() - 1;
        while (r >= 0 && s[r] == '1') --r;
        l = 0; // 0011100
        while (l < r) {
            if (s[l] == '0') { // 翻最左侧的;
                s[l] = '1';
                ++sum;
            }
            while (r > l && s[r] == '1') --r;
            if (l == r) break;
            s[r] = '1';
            sum += r - l + 1; // 翻最右侧的
            ++l, --r;
        }
        if (s[r] == '0') ++sum;
        ans = min(ans, sum);
        cout << ans << endl;
    }
    return 0;
}