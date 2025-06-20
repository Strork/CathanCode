#include <bits/stdc++.h>
using namespace std;
string s;
string rs;
int f[1005][1005];

int main() {
    cin >> s;
    rs = s;
    int n = s.size();
    rs.reserve();
    s = "0" + s;
    rs = "0" + rs;
    for (int i = 1; i <= n; ++i) { // 字符串s的坐标
        for(int j = 1; j <= n; ++j) { // 字符串rs的坐标
            if (s[i] == rs[j]) {
                f[i][j] = f[i-1][j-1] + 1;
            }
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    cout << n - f[n][n] << endl;
    return 0;
}