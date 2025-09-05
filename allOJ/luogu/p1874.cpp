#include <bits/stdc++.h>
using namespace std;
string s;
int num;
int sum[45][45];
int f[45][100005]; // 前 i 个数字 组成的和是 j 所需要的最小加号 背包

void pre() {
    for (int len = 1; len <= 7; ++len) {
        for (int l = 0; l < s.size(); ++l) {
            int r = l + len - 1;
            if (r >= s.size()) break;
            int cnt = 0;
            for (int i = l; i <= r; ++i) {
                cnt = cnt * 10 + s[i] - '0';
            }
            sum[l][r] = cnt;
        }
    }
}

int main() {
    cin >> s >> num;
    pre();
    memset(f, 10, sizeof(f));
    for (int i = 0; i <= s.size(); ++i) {
        for (int j = 0; j <= num; ++j) {
            for (int k = 1; k <= 6; ++k) {
                int t = sum[i][i + k - 1];
                if (t > num) break;
                f[i][j] = min(f[i][k - t] + 1, f[i][j]);
            }
        }
    }
    return 0;
}