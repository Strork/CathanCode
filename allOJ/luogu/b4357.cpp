#include <bits/stdc++.h>
using namespace std;
int l, r;
int ans;

int main() {
    cin >> l >> r;
    if (l <= 1) l = 2; // 最小的能统计的就是 2
    for (int i = l; i <= r; ++i) { // 每个 i 是要判断的数字
        int cnt = 0;
        int num = i;
        while (num) {
            ++cnt; // 统计二进制 1 的个数
            num &= num - 1; // 消去二进制末尾的 1
        }
        if (cnt <= 2 && cnt >= 1) {
            ++ans;
            //cout << i << endl;
        }
    }
    cout << ans << endl;
    return 0;
}