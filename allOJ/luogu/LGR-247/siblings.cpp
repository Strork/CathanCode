#include <bits/stdc++.h>
#define ll long long
using namespace std;
int r[505];
bool f[250005];
int n, m;

inline int read() {
    int read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

void solution() {
    memset(f, 0, sizeof(f));
    memset(r, 0, sizeof(r));
    n = 0, m = 0;
    int t = read();
    for (int i = 1; i <= t; ++i) {
        int x = read(), y = read();
        r[x] = max(r[x], y);
        n = max(x, n);
    }
    for (int i = 1; i <= n; ++i) m += r[i]; // 背包之和
    f[0] = 1; // 初始化，0 是开始就属于凑出来的
    int ans = 123456789;
    for (int i = 1; i < n; ++i) {
        for (int j = m; j >= r[i]; --j) { // 枚举选择了第 i 排能凑出的和
            if (f[j - r[i]]) { // 01背包
                f[j] = 1; 
                int a = i + j; // 第一个人的路程
                int b = n + (m - j); // 第二个人的路程（到头）
                ans = min(ans, max(a, b));
            }
        }
    }
    cout << ans * 2 << endl;
}

int main() {
    int T = read(); while (T--) {
        solution();
    }
    return 0;
}