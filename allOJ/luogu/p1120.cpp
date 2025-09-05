#include <bits/stdc++.h>
using namespace std;
int n, m, len;
int a[70], nt[70];
bool use[70];

// 1. 可行性剪枝：只找因数、第一根小木棍必须能找到解

bool dfs(int x, int cnt, int sum) { // 搜索起点，完成的小木棍个数，目前长度
    if (cnt * len == m) return true; // 找到解
    if (sum == len) return dfs(1, cnt + 1, 0); // 凑好一根了
    int id = lower_bound(a + x, a + 1 + n, len - sum, greater<int>()) - a; // 枚举起点
    for (int i = id; i <= n; ++i) {
        if (use[i] || sum + a[i] > len) continue;
        use[i] = 1;
        if (dfs(i + 1, cnt, sum + a[i])) return 1;
        use[i] = 0;
        if (sum == 0 || sum + a[i] == len) return 0; // 第一根or最后一根不能得到解
        i = nt[i];
    }
    return 0;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        m += a[i];
    }
    sort(a+1, a+1+n, greater<int>()); // 小木棍排序
    nt[n] = n;
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] == a[i + 1]) nt[i] = nt[i + 1];
        else nt[i] = i;
    }
    len = a[1]; // 从最长的小木棍开始找
    while (len <= m) {
        if (m % len == 0) {
            if (dfs(1, 0, 0)) {
                cout << len << endl;
                return 0;
            }
        }
        ++len;
    }
    return 0;
}