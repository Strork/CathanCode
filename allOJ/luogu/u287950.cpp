#include <bits/stdc++.h>
using namespace std;
int price[5000], value[5000];
int f[6005];
int n;
int kind, money;

int main() {
    cin >> kind >> money;
    for (int i = 1; i <= kind; ++i) { // kind 种物品
        int a, b, c;
        cin >> a >> b >> c;
        int t = 1;
        while (c) { // 开始拆解 c 的二进制
            if (c < t) t = c; // 最后多余的
            c -= t; // 总量减去拆出去的
            ++n;
            price[n] = a * t; // t 是捆起来几个这种物品
            value[n] = b * t;
            t <<= 1; // t 乘 2
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = money; j >= price[i]; --j) {
            f[j] = max(f[j], f[j - price[i]] + value[i]);
        }
    }
    cout << f[money] << endl;
    return 0;
}