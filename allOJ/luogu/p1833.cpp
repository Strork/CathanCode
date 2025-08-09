#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T;
ll t[200005];
ll c[200005];
ll f[1005];
int tree, n;

int main() {
    // T 通过 st 和 ed 计算
    int h1, h2, m1, m2;
    scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
    T = (h2 - h1) * 60 + m2 - m1;
    cin >> tree;
    for (int i = 1; i <= tree; ++i) {
        int ti, ci, pi;
        cin >> ti >> ci >> pi;
        if (pi == 0) {
            for (int j = ti; j <= T; ++j) { // 完全背包
                f[j] = max(f[j], f[j - ti] + ci);
            }
        } else { // 拆分成 n 棵樱花树
            int k = 1; // k 就是 二进制数
            while (pi >= k) {
                pi -= k; // 拿出 k 棵树 作为一个整体（新的樱花树）
                t[++n] = k * ti;
                c[n] = k * ci;
                k *= 2;
            }
            if (pi > 0) { // 拆完了 还剩 pi 个
                ++n;
                t[n] = pi * ti;
                c[n] = pi * ci;
            }
        }
    }

    // 0/1背包
    for (int i = 1; i <= n; ++i) {
        for (int j = T; j >= t[i]; --j) {
            f[j] = max(f[j], f[j - t[i]] + c[i]);
        }
    }
    cout << f[T] << endl;
    return 0;
}