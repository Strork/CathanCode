#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[100005], a[1000005];
int n;
string s;
bool vis[26];

int main() {
    cin >> n >> s;
    s = "&" + s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    f[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        memset(vis, 0, sizeof(vis)); // 清空字符数组
        f[i] = f[i - 1] + a[1]; // 单独字母成一组
        vis[s[i] - 'a'] = 1;
        for (int j = i - 1; j >= 1; --j) {
            int c = s[j] - 'a'; // 小写字母
            if (vis[c]) break; // 字母重复直接停止
            vis[c] = 1;
            f[i] = max(f[i], f[j - 1] + a[i - j + 1]);
        }
    }
    cout << f[n] << endl;
    return 0;
}