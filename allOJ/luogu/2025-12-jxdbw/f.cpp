#include <bits/stdc++.h>
using namespace std;
int f[105][105];
vector<string> p[105][105];
string a, b, c;

int main() {
    cin >> a >> b >> c;
    a = "a" + a, b = "b" + b, c = "c" + c;
    for (int i = 1; i <= a.size(); ++i) {
        for (int j = 1; j <= b.size(); ++j) {
            if (a[i] == b[j]) {
                if (f[i - 1][j] > f[i][j - 1])
                    p[i][j] = p[i - 1][j], f[i][j] = f[i - 1][j] + 1;
                else if (f[i - 1][j] < f[i][j - 1])
                    p[i][j] = p[i][j - 1], f[i][j] = f[i][j - 1] + 1;
                else {
                    p[i][j] = p[i][j - 1];
                    f[i][j] = f[i][j - 1] + 1;
                    for (auto str : p[i - 1][j]) p[i][j].push_back(str);
                }
                for (auto str : p[i][j]) str += a[i];  // 拼一下
            } else {
                if (f[i - 1][j] > f[i][j - 1])
                    p[i][j] = p[i - 1][j], f[i][j] = f[i - 1][j];
                else if (f[i - 1][j] < f[i][j - 1])
                    p[i][j] = p[i][j - 1], f[i][j] = f[i][j - 1];
                else {
                    p[i][j] = p[i][j - 1];
                    f[i][j] = f[i][j - 1];
                    for (auto str : p[i - 1][j]) p[i][j].push_back(str);
                }
            }
        }
    }
    int az = a.size(), bz = b.size();
    // for (int i = 1; i <= az; ++i)
    //     for (int j = 1; j <= bz; ++j) cout << f[i][j] << endl;
    sort(p[a.size()][b.size()].begin(), p[a.size()][b.size()].end());
    int ans = -1;
    string ans_str;
    for (auto str : p[az][bz]) {  // 从最长公共子序列里面找
        if (str.find(c) != string::npos) {
            int t = str.size() - 1;
            ans = max(ans, t);
        } else {
            int t = str.size();
            ans = max(ans, t);
            ans_str = str;
        }
    }
    if (ans_str != "") cout << ans_str << endl;
    cout << 0 << endl;
    return 0;
}