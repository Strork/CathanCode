#include <bits/stdc++.h>
using namespace std;
int n, q;
int out[1000005];  // 是否暴露
int f[1000005];    // 是否感染
int cnt = 0;       // 释放病毒的人数（为 0 则暴露区域是安全的）

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
    }
    for (int i = 1; i <= q; ++i) {
        int x;
        cin >> x;  // 修改 x 状态
        if (out[x]) {
            if (f[x])
                --cnt;  // 如果 x 之前是暴露，且感染了，那么传染病毒的人少一个
            else if (cnt)
                f[x] = 1;      // 保险起见，如果 x 戴回去之前也会被感染
        } else if (!out[x]) {  // 如果 x 之前戴着口罩
            if (f[x])
                ++cnt;
            else if (cnt) {
                f[x] = 1;  // x 由于需要摘口罩被感染
                ++cnt;
            }
        }
        out[x] ^= 1;  // 最后修改 x 口罩状态
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt && out[i]) f[i] = 1;
        printf("%d ", f[i]);
    }
    return 0;
}