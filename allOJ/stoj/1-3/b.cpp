#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) { // 测试 T 组数据
        long long x; // 按照题目数据范围，1<=x<=10^18
        cin >> x;
        int cnt = 0, ans = 0; // cnt 统计连续 1 的数量
        while (x > 0) {
            if (x % 2 == 1) cnt++; // 如果最后一位是 1，cnt++
            else cnt = 0; // 否则连续的数量归零
            if (cnt > ans) ans = cnt; // ans 记录最大的 cnt
            x /= 2; // 统计一次，除以 2 （二进制统计）
        }
        cout << ans << endl;
    }
    return 0;
}