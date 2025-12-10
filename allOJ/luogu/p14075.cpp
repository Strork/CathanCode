#include <bits/stdc++.h>
using namespace std;
int f[100005];
int a[100005];
int n;
string s;

int main() {
    cin >> n >> s;
    s = "$" + s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    f[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        bool ch[130] = {};
        for (int j = i; j >= 1; --j) {
            if (ch[s[j]]) break;
            ch[s[j]] = 1;
            f[i] = max(f[i], f[j - 1] + a[i - j + 1]);
        }
    }
    cout << f[n] << endl;
    return 0;
}