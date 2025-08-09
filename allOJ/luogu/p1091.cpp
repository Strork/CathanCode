#include <bits/stdc++.h>
using namespace std;
int f[105]; // 表示 1~i 的上升子序列长度
int a[105];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[i] = 1;
    }
    // 循环：i 从 1~n
    //    内循环 j 从 1~i-1 （找所有前面的长度）
    for (int i = n; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        }
    }
    return 0;
}