#include <bits/stdc++.h>
using namespace std;
int x, y, z, n, m;

int main() {
    cin >> x >> y >> z >> n >> m;
    int ans = 0;
    for (int i = 0; i <= m; ++i) { // 枚举 i 只公鸡
        for (int j = 0; j <= m - i; ++j) { // 枚举 j 只母鸡
            int k = m - i - j;// k 只小鸡
            // 满足条件（恰好花了 n 元）时 ans++
        }
    }
    // 输出答案
    return 0;
}