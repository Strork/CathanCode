#include <bits/stdc++.h>
using namespace std;
int f[2005][2005];
string a, b;

int main() {
    cin >> a >> b;
    a = '0' + a; b = '0' + b;
    int sa = a.size() - 1;
    int sb = b.size() - 1;
    for (int i = 1; i <= sa; ++i) f[i][0] = i; // 删除 i 次
    for (int j = 1; j <= sb; ++j) f[0][j] = j; // 添加 j 次
    for (int i = 1; i <= sa; ++i) {
        for (int j = 1; j <= sb; ++j) {
            int delta = 1; // 是否要 +1
            if (a[i] == b[j]) delta = 0; // 相等时修改操作不用+1
            f[i][j] = min(min(f[i-1][j], f[i][j-1])+1, f[i-1][j-1]+delta);
        }
    }
    cout << f[sa][sb] << endl;
    return 0;
}