#include <bits/stdc++.h>
using namespace std;
int sqr[100005]; // 完全平方数 1 4 9 16 25 36 ..... 物品的付出（体积）
int f[100005];
int cnt, n;

void get_sqr() {
    for (int i = 1; i*i <= n; ++i) {
        sqr[++cnt] = i*i;
    }
}

int main() {
    cin >> n;
    get_sqr();
    memset(f, 0x3f, sizeof(f));
    f[0] = 0; // 只初始化 f[0]
    for (int i = 1; i <= cnt; ++i) {
        for (int j = sqr[i]; j <= n; ++j) {
            f[j] = min(f[j], f[j - sqr[i]] + 1); // 完全背包
        }
    }
    cout << f[n] << endl;
    return 0;
}